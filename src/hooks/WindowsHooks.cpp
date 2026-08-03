#include "../CursorManager.hpp"
#include <Geode/Modify/CCEglView.hpp>
#include <Geode/Modify/PlatformToolbox.hpp>

using namespace geode::prelude;

#ifdef GEODE_IS_WINDOWS

class $modify(CCEGLView) {
    void showCursor(bool state) {
        CursorManager::get()->m_show = state;
        CCEGLView::showCursor(state);
    }
};

#elif GEODE_IS_MACOS

class $modify(PlatformToolbox) {
    static void showCursor() {
        CursorManager::get()->m_show = true;
        // Don't call PlatformToolbox::showCursor() to hide default macOS cursor
    }

    static void hideCursor() {
        CursorManager::get()->m_show = false;
        PlatformToolbox::hideCursor();
    }
};

class $modify(CCEGLView) {
    void onGLFWWindowFocusCallback(void* window, int focused) {
        CCEGLView::onGLFWWindowFocusCallback(window, focused);

        // Recreate cursor when window gains focus (handles monitor changes)
        if (focused) {
            CursorManager::get()->createCursor();
        }
    }
};

#endif