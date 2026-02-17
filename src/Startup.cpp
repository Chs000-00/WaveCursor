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

   c->updateOrInit();
   c->m_forceHide = Mod::get()->getSettingValue<bool>("always-force-hide-cursor");
    
    Loader::get()->queueInMainThread([]{
        CCScheduler::get()->scheduleUpdateForTarget(new NetworkScheduler{}, 5000, false);
    });

    listenForSettingChanges<bool>("always-force-hide-cursor", [](bool value) {
        CursorManager::get()->m_forceHide = value;
    });

}
