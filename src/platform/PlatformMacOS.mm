#import <Cocoa/Cocoa.h>
#include <Geode/Geode.hpp>
#include "Platform.hpp"

using namespace geode::prelude;

void PlatformManager::resetCursor() {
    if (this->m_previouslyShown != this->m_shown) {
        if (this->m_shown) {
            [NSCursor unhide];
        } else {
            [NSCursor hide];
        }
        this->m_previouslyShown = this->m_shown;
    }
}

void PlatformManager::init() {
    this->sharedInit();
}