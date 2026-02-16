#include "CursorManager.hpp"
#include "Geode/ui/OverlayManager.hpp"
#include "cursor.hpp"
#include <Geode/binding/GameManager.hpp>

void CursorManager::updateOrInit() {
    auto gameManager = GameManager::get();
    if (this->m_cursor) {
        auto data = SimpleCursor::CursorData(
            gameManager->getPlayerColor(),
            gameManager->getPlayerColor2(),
            gameManager->getPlayerDart(),
            gameManager->getPlayerGlow(),
            gameManager->getPlayerGlowColor()
        );
        this->m_cursor = SimpleCursor::create(data);
        this->m_cursor->setID("cursor"_spr);
        OverlayManager::get()->addChild(this->m_cursor);
    } else {
        auto data = SimpleCursor::CursorData(
            gameManager->getPlayerColor(),
            gameManager->getPlayerColor2(),
            gameManager->getPlayerDart(),
            gameManager->getPlayerGlow(),
            gameManager->getPlayerGlowColor()
        );
        this->m_cursor->updateCursor(data);
    }
}

void CursorManager::updateToPosition() {
    this->m_cursor->setPosition(getMousePos());
}