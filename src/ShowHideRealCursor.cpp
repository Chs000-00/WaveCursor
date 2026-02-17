#include "CursorManager.hpp"
#include <Geode/Modify/CCEGLView.hpp>
#include <Geode/Modify/PlatformToolbox.hpp>

using namespace geode::prelude;

#ifdef GEODE_IS_WINDOWS

class $modify(CCEGLView) {
    static void onModify(auto& self) {
        if (!self.setHookPriorityPost("cocos2d::CCEGLView::showCusor", Priority::Late)) {
            log::warn("Failed to set hook priority for CCEGLView::showCusor.");
        }
    }

    void showCusor(bool state) {
        auto c = CursorManager::get();
        if (c->m_forceHide) {
            c->visible(state);
        }    
    }
};

#elif GEODE_IS_MACOS

class $modify(PlatformToolbox) {
    static void onModify(auto& self) {
        if (!self.setHookPriorityPost("PlatformToolbox::showCusor", Priority::Late)) {
            log::warn("Failed to set hook priority for PlatformToolbox::showCusor.");
        }

        if (!self.setHookPriorityPost("PlatformToolbox::hideCusor", Priority::Late)) {
            log::warn("Failed to set hook priority for PlatformToolbox::hideCusor.");
        }
    }

    void showCusor() {
        auto c = CursorManager::get();
        if (c->m_forceHide) {
            c->visible(true);
        }
    }

    void hideCusor() {
        auto c = CursorManager::get();
        if (c->m_forceHide) {
            c->visible(false);
        }    
    }
};

#endif