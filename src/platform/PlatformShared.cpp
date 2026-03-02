#include <Geode/Geode.hpp>
#include "Platform.hpp"

using namespace geode::prelude;

bool PlatformManager::getIsHidden() {
    return this->m_shown;
}

void PlatformManager::setCursorVisibility(bool visible) {
    log::info("Updating cursor visibility...");
    this->m_shown = visible;
    this->resetCursor();
}

void PlatformManager::sharedInit() {
    GameEvent(GameEventType::Exiting).listen([] {
        log::info("Caught exit GameEvent. Unhiding cursor...");
        PlatformManager::get()->setCursorVisibility(true);
    }).leak();
}
