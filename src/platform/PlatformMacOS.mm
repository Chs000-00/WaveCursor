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

}

@interface GLFWContentView : NSView
{

}
@end

@implementation GLFWContentView : NSView
- (void)mouseExited:(NSEvent *)event
{
    
    platform = PlatformManager::get();   
    platform->setCursorVisibility(true);
}

- (void)mouseEntered:(NSEvent *)event
{
    platform = PlatformManager::get();   
    platform->setCursorVisibility(false);
}

@end