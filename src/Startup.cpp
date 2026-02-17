#include "CursorManager.hpp"
#include "Geode/DefaultInclude.hpp"
#include <Geode/Geode.hpp>
#include <Geode/binding/PlatformToolbox.hpp>

using namespace geode::prelude;

class NetworkScheduler : public CCObject {
public:
    void update(float dt) {
        CursorManager::get()->updateToPosition();
    }
};


$execute {
    
    PlatformToolbox::hideCursor();

    CursorManager::get()->updateOrInit();
    
    Loader::get()->queueInMainThread([]{
        CCScheduler::get()->scheduleUpdateForTarget(new NetworkScheduler{}, 5000, false);
    });
}
