#include "Cursor.hpp"
#include "Geode/binding/GameManager.hpp"
#include "Geode/cocos/CCScheduler.h"
#include "Geode/cocos/cocoa/CCObject.h"
#include "Geode/cocos/misc_nodes/CCMotionStreak.h"
#include "Geode/cocos/sprite_nodes/CCSprite.h"
#include "Geode/cocos/textures/CCTexture2D.h"
#include "Geode/ui/IconButtonSprite.hpp"
#include "Geode/ui/OverlayManager.hpp"
#include "Geode/utils/cocos.hpp"
#include "ccTypes.h"
#include <Geode/Enums.hpp>
#include <Geode/binding/GhostTrailEffect.hpp>
#include <Geode/binding/HardStreak.hpp>

using namespace geode::prelude;

// Stolen from createtogether lol

SimpleCursor* SimpleCursor::create(const CursorData& cursorData) {
    auto ret = new SimpleCursor();
    if (ret->init(cursorData)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

void SimpleCursor::updateCursor(const CursorData& cursorData) {
    auto gameManager = GameManager::get();
    this->m_cursorData = cursorData;
    this->m_cursorSprite->updatePlayerFrame(cursorData.cursorID, IconType::Wave);
    this->m_cursorSprite->setColor(gameManager->colorForIdx(cursorData.cursorColor1));
    this->m_cursorSprite->setSecondColor(gameManager->colorForIdx(cursorData.cursorColor2));

    if (cursorData.cursorHasGlow) {
        this->m_cursorSprite->setGlowOutline(gameManager->colorForIdx(cursorData.cursorGlowColor));
    }
    else {
        this->m_cursorSprite->disableGlowOutline();
    }
}

SimplePlayer* SimpleCursor::getSimplePlayer() {
    return this->m_cursorSprite;
}

bool SimpleCursor::init(const CursorData& cursorData) {
    if (!CCNode::init()) {
        return false;
    }

    this->m_cursorSprite = SimplePlayer::create(0);
    this->addChild(this->m_cursorSprite);

    this->setContentSize(this->m_cursorSprite->m_outlineSprite->getScaledContentSize());
    this->m_cursorSprite->setPosition(this->m_cursorSprite->m_outlineSprite->getScaledContentSize() / 2);
    this->updateCursor(cursorData);

    CCScheduler::get()->scheduleSelector(schedule_selector(SimpleCursor::update), this, 0.0, kCCRepeatForever, 0.0, false);

    return true;
}

void SimpleCursor::createPlainTrail() {
    if (this->m_hardTrail) { this->m_hardTrail->setVisible(false); }
    if (this->m_ghostTrail) { this->m_ghostTrail->setVisible(false); }

    if (this->m_plainTrail) {
        this->m_plainTrail->setVisible(true); 
        this->m_plainTrail->release();
    }
    auto gm = GameManager::get();
    auto sprite = "streak_0" + std::to_string(gm->getPlayerStreak()) + "_001.png";
    log::info("Loading PlainStreak {}", sprite);
    this->m_plainTrail = CCMotionStreak::create(0.5, 2, 10, ccWHITE, sprite.c_str());
    OverlayManager::get()->addChild(this->m_plainTrail);
    this->m_plainTrail->setID("cursor-plain-trail"_spr); 
    this->m_plainTrail->setZOrder(-1);
}


void SimpleCursor::createHardTrail() {
    if (this->m_plainTrail) { this->m_plainTrail->setVisible(false); }
    if (this->m_ghostTrail) { this->m_ghostTrail->setVisible(false); }

    if (this->m_hardTrail) {
         this->m_hardTrail->setVisible(true); 
    } else {
        this->m_hardTrail = HardStreak::create();
    }
}


void SimpleCursor::createGhostTrail() {
    if (this->m_plainTrail) { this->m_plainTrail->setVisible(false); }
    if (this->m_hardTrail) { this->m_hardTrail->setVisible(false); }

    if (this->m_ghostTrail) {
         this->m_ghostTrail->setVisible(true); 
    } else {
        this->m_ghostTrail = GhostTrailEffect::create();
    }
}

void SimpleCursor::update(float dt) {
    if(this->m_plainTrail) {
        this->m_plainTrail->setPosition(getMousePos());
    }
}
