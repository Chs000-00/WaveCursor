#include "CursorManager.hpp"
#include "Geode/ui/OverlayManager.hpp"
#include "Cursor.hpp"
#include <Geode/binding/GameManager.hpp>
#include <Geode/binding/PlatformToolbox.hpp>
#include <Geode/binding/PlayLayer.hpp>


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

    auto trailType = Mod::get()->getSettingValue<std::string>("trail-type");

    if(this->m_enableTrail) {
        if (trailType == "Plain Trail") {
            // this->m_cursor->m_trail = SimpleCursor::Plain;
            this->m_cursor->createPlainTrail();
        } else if (trailType == "Ghost Trail") {
            this->m_cursor->createGhostTrail();
        } else {
            log::error("Could not find trailType {}", trailType);
        }
    } else {
        this->m_cursor->disableAllTrails();
    }
}

void CursorManager::update() {
    this->m_cursor->setPosition(getMousePos());

    if(this->m_forceHide) {
        // TODO: HIDE CURSOR
        // alpha::prelude::CursorManager::get()->setCursor(alpha::prelude::Cursor::NONE);
    }


    // eclipse moment
    bool canShowInLevel = true;
    if (auto* playLayer = PlayLayer::get()) {
        auto g = GameManager::get();
        if (!g->getGameVariable(GameVar::ShowCursor)) {
            canShowInLevel = playLayer->m_hasCompletedLevel || 
                playLayer->m_isPaused || 
                !(g->getGameVariable(GameVar::LockCursor));   
        }
    }

    this->m_cursor->setVisible(canShowInLevel);
}

void CursorManager::setCursorSize(int size) {
    this->m_cursorSize = ((float)size)/100;
}

void CursorManager::enableTrail(bool enable) {
    this->m_enableTrail = enable;
}