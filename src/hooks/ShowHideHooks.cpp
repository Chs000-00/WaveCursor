#include "../CursorManager.hpp"
#include <Geode/Modify/CCEglView.hpp>

using namespace geode::prelude;

class $modify(CCEGLView) {
    void showCursor(bool state) {
        CursorManager::get()->m_show = state;
        // CCEGLView::showCursor(state);
        CCEGLView::showCursor(false);
    }
};