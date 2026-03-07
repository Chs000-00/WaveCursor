#include "../CursorManager.hpp"
#include "Geode/cocos/menu_nodes/CCMenu.h"
#include <Geode/Modify/VideoOptionsLayer.hpp>
#include <Geode/Modify/MenuLayer.hpp>
#include <Geode/binding/VideoOptionsLayer.hpp>

using namespace geode::prelude;

class $modify(VideoOptionsLayer) {
    void updateResolution(int resolution) {
        VideoOptionsLayer::updateResolution(resolution);
        CursorManager::get()->createCursor();
    }
};


class $modify(MenuLayer) {
    void onMoreGames(CCObject* sender) {
        auto crash = dynamic_cast<CCMenu*>(sender);
        crash->_setZOrder(1);
        MenuLayer::onMoreGames(sender);
    }
};