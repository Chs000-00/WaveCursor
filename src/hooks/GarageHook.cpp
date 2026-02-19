#include "../CursorManager.hpp"
#include <Geode/Modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(GJGarageLayer) {
    void onSelect(CCObject* sender) {
        GJGarageLayer::onSelect(sender);
        CursorManager::get()->createCursor();
    }
};