#include "Cursor.hpp"
#include "CursorManager.hpp"
#include <Geode/Modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(GJGarageLayer) {
    // void playerColorChanged() {
        
    //     GJGarageLayer::playerColorChanged();
    // }

    void onSelect(CCObject* sender) {
        GJGarageLayer::onSelect(sender);
        auto c = CursorManager::get();
        c->updateOrInit();
    }
};