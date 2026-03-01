#pragma once

#include "../Singleton.hpp"

class PlatformManager: public Singleton<PlatformManager> {
private:
    bool m_shown = false;
    bool m_previouslyShown = true;
    void resetCursor();
    void update();
    void init();

public:
    void setCursorVisibility(bool visible);
    bool getIsHidden();

};