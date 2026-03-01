#include "Geode/loader/Log.hpp"
#import <Cocoa/Cocoa.h>
#include <Geode/Geode.hpp>
#include "Platform.hpp"

using namespace geode::prelude;

// Hello index staff this single file is going to be the reason my mod gets rejected!!

static std::mutex s_mutex;
static std::condition_variable s_cv;
static siginfo_t* s_siginfo = nullptr;
static ucontext_t* s_context = nullptr;
static int s_signal = 0;

static void(*old_handler)(int);

void PlatformManager::resetCursor() {
    log::info("Changing cursor state: {} {}", this->m_previouslyShown, this->m_shown);
    if (this->m_previouslyShown != this->m_shown) {
        if (this->m_shown) {
            [NSCursor unhide];
        } else {
            [NSCursor hide];
        }
        this->m_previouslyShown = this->m_shown;
    }
}

static void handlerThread() {
    log::info("Waiting in WaveCursor unhide thread");

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

    old_handler(s_signal);
}

extern "C" void signalHandler(int signal, siginfo_t* signalInfo, void* vcontext) {

	auto context = reinterpret_cast<ucontext_t*>(vcontext);
    
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
    struct sigaction old;
    action.sa_sigaction = &signalHandler;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);

    // Copy all current sigactions to old
    sigaction(SIGSEGV, nullptr, &old);
    // sigaction(SIGINT, nullptr, &old);     // This one does not get tracked
    sigaction(SIGFPE, nullptr, &old);
    sigaction(SIGILL, nullptr, &old);
    sigaction(SIGTERM, nullptr, &old);
    sigaction(SIGABRT, nullptr, &old);
    sigaction(SIGBUS, nullptr, &old);

    // Copy the pointer from the old sigactions
    old_handler = old.sa_handler;

    // Hook the sigactions!
    sigaction(SIGSEGV, &action, nullptr);
    sigaction(SIGINT, &action, nullptr);     
    sigaction(SIGFPE, &action, nullptr);
    sigaction(SIGILL, &action, nullptr);
    sigaction(SIGTERM, &action, nullptr);
    sigaction(SIGABRT, &action, nullptr);
    sigaction(SIGBUS, &action, nullptr);

    std::thread(&handlerThread).detach();
}