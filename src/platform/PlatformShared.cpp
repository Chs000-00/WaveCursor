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
