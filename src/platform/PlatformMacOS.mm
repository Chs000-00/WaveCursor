#include "Geode/loader/Log.hpp"
#import <Cocoa/Cocoa.h>
#include <Geode/Geode.hpp>
#include "Platform.hpp"

using namespace geode::prelude;


static std::mutex s_mutex;
static std::condition_variable s_cv;
static int s_signal = 0;


void PlatformManager::resetCursor() {
    if (this->m_previouslyHidden != this->m_hidden) {
        if (this->m_hidden) {
            [NSCursor hide];
        } else {
            [NSCursor unhide];
        }
        this->m_previouslyHidden = this->m_hidden;
    }
}

static void handlerThread() {
    std::unique_lock<std::mutex> lock(s_mutex);
    s_cv.wait(lock, [] { return s_signal != 0; });

    // #ifdef GEODE_IS_INTEL_MAC
    // auto signalAddress = reinterpret_cast<void*>(s_context->uc_mcontext->__ss.__rip);
    // #else // m1
    // auto signalAddress = reinterpret_cast<void*>(s_context->uc_mcontext->__ss.__pc);
    // #endif
    log::info("WaveCursor handled an exception");
    s_signal = 0;
    [NSCursor unhide];
}

extern "C" void signalHandler(int signal, siginfo_t* signalInfo, void* vcontext) {

    // for some reason this is needed, dont ask me why
	#ifdef GEODE_IS_INTEL_MAC
	s_backtrace[2] = reinterpret_cast<void*>(context->uc_mcontext->__ss.__rip);
	#else
	s_backtrace[2] = reinterpret_cast<void*>(context->uc_mcontext->__ss.__pc);
	#endif

    {
        std::unique_lock<std::mutex> lock(s_mutex);
        s_signal = signal;
        s_siginfo = signalInfo;
        s_context = context;
    }

    s_cv.notify_all();
    std::unique_lock<std::mutex> lock(s_mutex);
    s_cv.wait(lock, [] { return s_signal == 0; });
}


void PlatformManager::init() {
    GameEvent(GameEventType::Exiting).listen([] {
        log::info("Caught exit gameevent. Showing cursor...");
        PlatformManager::get()->setCursorVisibility(true);
    }).leak();


    struct sigaction action;
    action.sa_sigaction = &signalHandler;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);
    sigaction(SIGSEGV, &action, nullptr);
    // Lets track interrupt cause we are evil and shit
    sigaction(SIGINT, &action, nullptr);
    sigaction(SIGFPE, &action, nullptr);
    sigaction(SIGILL, &action, nullptr);
    sigaction(SIGTERM, &action, nullptr);
    sigaction(SIGABRT, &action, nullptr);
    sigaction(SIGBUS, &action, nullptr);

    std::thread(&handlerThread).detach();
}