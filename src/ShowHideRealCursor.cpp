#include "CursorManager.hpp"
#include <Geode/Modify/CCEGLView.hpp>

using namespace geode::prelude;

class $modify(CCEGLView) {
    static void onModify(auto& self) {
        if (!self.setHookPriorityPost("cocos2d::CCEGLView::showCusor", Priority::Late)) {
            log::warn("Failed to set hook priority for CCEGLView::showCusor.");
        }
    }

    void showCusor(bool state) {
        CursorManager::get()->visible(state);
    }
};