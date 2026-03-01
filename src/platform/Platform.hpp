#pragma once

#include "../Singleton.hpp"

class PlatformManager: public Singleton<PlatformManager> {
private:
    bool m_shown = true;
    bool m_previouslyShown = true;
    void resetCursor();
    void update();

public:
    void setCursorVisibility(bool visible);
    bool getIsHidden();
    void init();
};