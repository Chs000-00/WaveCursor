#include <Geode/Geode.hpp>
#include "Platform.hpp"

using namespace geode::prelude;

bool PlatformManager::getIsHidden() {
    return this->m_shown;
}

void PlatformManager::setCursorVisibility(bool visible) {
    this->m_shown = visible;
    this->resetCursor();
}

void PlatformManager::sharedInit() {
    GameEvent(GameEventType::Exiting).listen([] {
        log::info("Caught exit GameEvent. Unhiding cursor...");
        PlatformManager::get()->setCursorVisibility(true);
    }).leak();
}

// Thanks Alphalaneous!
bool PlatformManager::isCursorOnScreen() {
    auto mousePos = getMousePos();
    if (auto scene = CCScene::get()) {
        auto sceneBox = scene->boundingBox();
        return sceneBox.containsPoint(mousePos);
    }

    return false;
}

void PlatformManager::update() {
    if (PlatformManager::isCursorOnScreen()) {
        if (!this->m_didJustEnterScreen) {
            this->m_didJustEnterScreen = true;
            this->setCursorVisibility(this->m_stateBeforeScreenExit);
        }
        resetCursor();
    }
    else {
        if (this->m_didJustEnterScreen) {
            this->m_stateBeforeScreenExit = this->m_shown;
        }
        this->m_didJustEnterScreen = false;
        this->setCursorVisibility(true);
    }
}