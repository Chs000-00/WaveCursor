#include "Cursor.hpp"
#include "FixedTrailEffect.hpp"
#include "Geode/binding/GameManager.hpp"
#include "Geode/ui/OverlayManager.hpp"
#include "Geode/utils/cocos.hpp"
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

    CCScheduler::get()->scheduleUpdateForTarget(this, 5500, false);

    return true;
}

void SimpleCursor::createPlainTrail() {
    if (this->m_hardTrail) { this->m_hardTrail->setVisible(false); }
    if (this->m_ghostTrail) { this->m_ghostTrail->setVisible(false); }

    auto gm = GameManager::get();

    if (this->m_plainTrail) {
        this->m_plainTrail->setVisible(true); 
        auto sprite = "streak_0" + std::to_string(gm->getPlayerStreak()) + "_001.png";
        log::info("Loading PlainStreak {}", sprite);
        this->m_plainTrail->setTexture(CCTextureCache::get()->addImage(sprite.c_str(), true));
        this->m_plainTrail->reset();
    } else {
        auto sprite = "streak_0" + std::to_string(gm->getPlayerStreak()) + "_001.png";
        log::info("Loading PlainStreak {}", sprite);
        auto texture = CCTextureCache::get()->addImage(sprite.c_str(), true);
        this->m_plainTrail = CCMotionStreak::create(0.5, 5, 10, ccWHITE, texture);
        this->m_plainTrail->setBlendFunc({ GL_SRC_ALPHA, GL_ONE });   
        OverlayManager::get()->addChild(this->m_plainTrail);
        this->m_plainTrail->setID("cursor-plain-trail"_spr); 
        this->m_plainTrail->setZOrder(-1);
    }
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
        // this->m_ghostTrail->runWithTarget(, 0.05, 0.4, -1, 0.6, false);

        this->m_ghostTrail->m_iconSprite = this->getSimplePlayer()->m_firstLayer;
        this->m_ghostTrail->m_snapshotInterval = 0.05;
        this->m_ghostTrail->m_fadeInterval = 0.4;
        // if (0.6 <= .1f) 0.6 = .1f;
        this->m_ghostTrail->m_scaleTwice = false;
        this->m_ghostTrail->m_ghostScale = 0.6;
        this->schedule(schedule_selector(fixedTrailSnapshot)), 0.05);
        if (-1 > 0.f) this->runAction(cocos2d::CCSequence::create(
            cocos2d::CCDelayTime::create(-1),
            cocos2d::CCCallFunc::create(this, callfunc_selector(GhostTrailEffect::stopTrail)),
            nullptr
        ));
        
      
        // this->m_ghostTrail->doBlendAdditive();
        this->m_ghostTrail->m_color = ccBLACK;
        OverlayManager::get()->addChild(m_ghostTrail);
        this->m_ghostTrail->setVisible(false);

        // CCLayer* ghostContainer = CCLayer::create();
        // ghostContainer->setID("ghost-container"_spr);
        // OverlayManager::get()->addChild(ghostContainer);
        // this->m_ghostTrail->m_objectLayer = ghostContainer;
    }
}

void SimpleCursor::update(float dt) {
    if(this->m_plainTrail) {
        // I love absolllute (position)
        this->m_plainTrail->setPosition(this->convertToWorldSpace(this->getSimplePlayer()->getPosition()));
    } else if (this->m_ghostTrail) {
        // this->m_ghostTrail->trailSnapshot(dt);
    }
}

void SimpleCursor::disableAllTrails() {
    if (this->m_plainTrail) { this->m_plainTrail->setVisible(false); }
    if (this->m_hardTrail) { this->m_hardTrail->setVisible(false); }
    if (this->m_ghostTrail) { this->m_ghostTrail->setVisible(false); }
}