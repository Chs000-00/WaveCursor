#include "../CursorManager.hpp"
#include <Geode/Modify/CharacterColorPage.hpp>

using namespace geode::prelude;

class $modify(CharacterColorPage) {
    void onPlayerColor(CCObject* sender) {
        CharacterColorPage::onPlayerColor(sender);
        CursorManager::get()->createCursor();
    }
    
    void toggleGlow(CCObject* sender) {
        CharacterColorPage::toggleGlow(sender);
        CursorManager::get()->createCursor();
    }
};