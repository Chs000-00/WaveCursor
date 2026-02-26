#include <Geode/Geode.hpp>
#include "Platform.hpp"

using namespace geode::prelude;

bool PlatformManager::getIsHidden() {
    return this->m_hidden;
}

void PlatformManager::setCursorVisibility(bool visible) {
    this->m_hidden = visible;
    this->resetCursor();
}
