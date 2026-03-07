#include <Geode/Geode.hpp>
#include "Platform.hpp"


#ifdef GEODE_IS_WINDOWS
#include <winuser.h>

using namespace geode::prelude;

// setCursorVisibility(this->m_shown); causes issues with the mouse showing up for half a second in certain cases.

void PlatformManager::resetCursor() {
    if (this->m_previouslyShown != this->m_shown) {
        // ITS REFCOUNTED FFS
        while (true) {
            auto c = ShowCursor(this->m_shown);

            if (c >= 0 && this->m_shown) {
                break;
            } else if (c <= -1 && !this->m_shown) {
                break;
            }
        }
        this->m_previouslyShown = this->m_shown;
    }
}

void PlatformManager::init() {
    this->sharedInit();
}

#endif