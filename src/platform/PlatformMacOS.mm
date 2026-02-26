#import <Cocoa/Cocoa.h>
#include <Geode/Geode.hpp>
#include "Platform.hpp"

using namespace geode::prelude;

void PlatformManager::resetCursor() {
    if (this->m_previouslyHidden != this->m_hidden) {
        if (this->m_hidden) {
            [NSCursor hide];
        } else {
            [NSCursor unhide];
        }
        this->m_previouslyHidden = this->m_hidden;
    }
}

void PlatformManager::init() {
    GameEvent(GameEventType::Exiting).listen([] {
        PlatformManager::get()->setCursorVisibility(true);
    }).leak();
}