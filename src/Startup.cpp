#include "CursorManager.hpp"
#include "Geode/DefaultInclude.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class NetworkScheduler : public CCObject {
public:
    void update(float dt) {
        CursorManager::get()->updateToPosition();
    }
};


$execute {
    auto cursorManager = CursorManager::get();
    cursorManager->updateOrInit();
        Loader::get()->queueInMainThread([]{
        CCScheduler::get()->scheduleUpdateForTarget(new NetworkScheduler{}, 5000, false);
    });
}
