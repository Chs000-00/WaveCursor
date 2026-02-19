#include "CursorManager.hpp"
#include "Geode/DefaultInclude.hpp"
#include <Geode/Geode.hpp>
#include <Geode/binding/PlatformToolbox.hpp>
#include "alphalaneous.alphas-ui-pack/include/API.hpp" // IWYU pragma: keep

using namespace geode::prelude;

class BasicScheduler : public CCObject {
public:
    void update(float dt) {
        CursorManager::get()->update();
    }
};


$execute {

    alpha::prelude::CursorManager::get()->setCursor(alpha::prelude::Cursor::NONE);

    auto c =  CursorManager::get();

    c->m_forceHide = Mod::get()->getSettingValue<bool>("always-force-hide-cursor");
    c->createCursor();
    c->enableTrail(Mod::get()->getSettingValue<bool>("enable-trail"));
    c->setCursorSize(Mod::get()->getSettingValue<int>("cursor-size"));

    
    Loader::get()->queueInMainThread([]{
        CCScheduler::get()->scheduleUpdateForTarget(new BasicScheduler{}, 5000, false);
    });


    // Init Setting callbacks
    
    listenForSettingChanges<bool>("always-force-hide-cursor", [](bool value) { CursorManager::get()->m_forceHide = value; });

    listenForSettingChanges<int>("cursor-size", [](int value) { CursorManager::get()->setCursorSize(value); });

    listenForSettingChanges<bool>("enable-trail", [](bool value) { CursorManager::get()->enableTrail(value); });
}
