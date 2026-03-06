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