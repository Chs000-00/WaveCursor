#include <Geode/Geode.hpp>
#include "Platform.hpp"

using namespace geode::prelude;

bool PlatformManager::getIsHidden() {
    return this->m_shown;
}

void PlatformManager::setCursorVisibility(bool visible) {
    this->m_shown = visible;
    this->resetCursor();
}
