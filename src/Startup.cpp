#include "CursorManager.hpp"
#include "Geode/DefaultInclude.hpp"
#include <Geode/Geode.hpp>
#include <Geode/binding/PlatformToolbox.hpp>
#include "alphalaneous.alphas-ui-pack/include/API.hpp"

using namespace geode::prelude;

class NetworkScheduler : public CCObject {
public:
    void update(float dt) {
        CursorManager::get()->updateToPosition();
    }
};


$execute {

    alpha::prelude::CursorManager::get()->setCursor(alpha::prelude::Cursor::NONE);

    auto c =  CursorManager::get();

    c->m_cursorSize = ((float)Mod::get()->getSettingValue<int>("cursor-size"))/100;
    c->m_forceHide = Mod::get()->getSettingValue<bool>("always-force-hide-cursor");

    c->updateOrInit();

    
    Loader::get()->queueInMainThread([]{
        CCScheduler::get()->scheduleUpdateForTarget(new NetworkScheduler{}, 5000, false);
    });

    listenForSettingChanges<bool>("always-force-hide-cursor", [](bool value) {
        CursorManager::get()->m_forceHide = value;
    });

    listenForSettingChanges<int>("cursor-size", [](int value) {
        auto c =  CursorManager::get();
        c->m_cursorSize = ((float)value)/100;
        c->updateOrInit();
    });

}
