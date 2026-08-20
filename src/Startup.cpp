#include "CursorManager.hpp"
// #include "platform/Platform.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/CCEGLView.hpp>

using namespace geode::prelude;

// Just incase the hook still runs for some reason
static bool ignoreWC = false;

class $modify(CCEGLView) {
    void showCursor(bool state) {
        // CCEGLView::showCursor(state);
        if (ignoreWC) {
            CCEGLView::showCursor(state);
            return;
        }
        CursorManager::get()->m_show = state;
        CCEGLView::showCursor(false);
    }
};

class BasicScheduler : public CCObject {
public:
    void update(float dt) {
        CursorManager::get()->update();
        // PlatformManager::get()->update();
    }
};

$execute {
    // auto platform = PlatformManager::get();
    auto c =  CursorManager::get();

    // platform->init();

    // c->m_forceHide = Mod::get()->getSettingValue<bool>("always-force-hide-cursor");
    c->setCursorSize(Mod::get()->getSettingValue<int>("cursor-size"));
    c->enableDisableTrail(Mod::get()->getSettingValue<bool>("enable-trail"));
    // Fix stupid shit


    c->createCursor();
    // platform->setCursorVisibility(false);

    // Just incase the hook still runs for some reason
    ignoreWC = true;
    CCEGLView::get()->showCursor(false);
    CursorManager::get()->m_show = true;
    ignoreWC = false;

    Loader::get()->queueInMainThread([]{
        CCScheduler::get()->scheduleUpdateForTarget(new BasicScheduler{}, 2000, false);
    });

    GameEvent(GameEventType::Loaded).listen([] {
        CursorManager::get()->createCursor();
    }).leak();

    // Init Setting callbacks
    
    listenForSettingChanges<int>("cursor-size", [](int value) { auto c = CursorManager::get(); c->setCursorSize(value); c->createCursor(); });

    listenForSettingChanges<bool>("enable-trail", [](bool value) { auto c = CursorManager::get(); c->enableDisableTrail(value); c->createCursor(); });

    listenForSettingChanges<float>("trail-width", [](float value) { auto c = CursorManager::get(); c->createCursor(); });

    listenForSettingChanges<std::string>("trail-type", [](std::string value) { auto c = CursorManager::get(); c->createCursor(); });
       
    listenForSettingChanges<std::string>("enable-override", [](std::string value) { auto c = CursorManager::get(); c->createCursor(); });
}