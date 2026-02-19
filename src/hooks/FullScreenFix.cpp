#include "../CursorManager.hpp"
#include <Geode/Modify/VideoOptionsLayer.hpp>
#include <Geode/binding/VideoOptionsLayer.hpp>

using namespace geode::prelude;

class $modify(VideoOptionsLayer) {
    void updateResolution(int resolution) {
        VideoOptionsLayer::updateResolution(resolution);
        CursorManager::get()->createCursor();
    }
};