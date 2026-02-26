#include <Geode/Geode.hpp>
#include "Platform.hpp"

using namespace geode::prelude;

bool PlatformManager::getIsHidden() {
    return this->m_hidden;
}