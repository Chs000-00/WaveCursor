#include "CursorManager.hpp"
#include "Geode/ui/OverlayManager.hpp"
#include "Cursor.hpp"
#include <Geode/Enums.hpp>
#include <Geode/binding/GameManager.hpp>
#include <Geode/binding/PlatformToolbox.hpp>
#include <Geode/binding/PlayLayer.hpp>
#include "alphalaneous.alphas-ui-pack/include/API.hpp" // IWYU pragma: keep


void CursorManager::createCursor() {
    auto gameManager = GameManager::get();

    if (!this->m_cursor) {
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
    
    this->m_cursor->setAnchorPoint(ccp(1.0f, 0.5f));

    this->m_cursor->setRotation(240);
    this->m_cursor->setScale(this->m_cursorSize);
}

void CursorManager::update() {
    this->m_cursor->setPosition(getMousePos());

    if(this->m_forceHide) {
        alpha::prelude::CursorManager::get()->setCursor(alpha::prelude::Cursor::NONE);
    }

    if(this->m_enableTrail) {

    }

    // eclipse moment
    bool canShowInLevel = true;
    if (auto* playLayer = PlayLayer::get()) {
        auto g = GameManager::get();
        canShowInLevel = playLayer->m_hasCompletedLevel || 
        playLayer->m_isPaused || 
        (!g->getGameVariable(GameVar::LockCursor)) ||
        (g->getGameVariable(GameVar::ShowCursor));
    }

    this->m_cursor->setVisible(canShowInLevel);
}

void CursorManager::setCursorSize(int size) {
    this->m_cursorSize = ((float)size)/100;
    this->createCursor();
}

void CursorManager::enableTrail(bool enable) {
    this->m_enableTrail = enable;
    this->createCursor();
}