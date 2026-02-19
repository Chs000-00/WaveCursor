#include "Cursor.hpp"
#include "Geode/binding/GameManager.hpp"

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
    return true;
}

void SimpleCursor::createPlainTrail() {
    if (this->m_hardTrail) { this->m_hardTrail->setVisible(false); }
    if (this->m_ghostTrail) { this->m_ghostTrail->setVisible(false); }

    if (this->m_plainTrail) {
         this->m_plainTrail->setVisible(true); 
    } else {

    }
}


void SimpleCursor::createHardTrail() {
    if (this->m_plainTrail) { this->m_plainTrail->setVisible(false); }
    if (this->m_ghostTrail) { this->m_ghostTrail->setVisible(false); }

    if (this->m_hardTrail) {
         this->m_hardTrail->setVisible(true); 
    } else {

    }
}


void SimpleCursor::createGhostTrail() {
    if (this->m_plainTrail) { this->m_plainTrail->setVisible(false); }
    if (this->m_hardTrail) { this->m_hardTrail->setVisible(false); }

    if (this->m_ghostTrail) {
         this->m_ghostTrail->setVisible(true); 
    } else {

    }
}
