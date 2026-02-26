#pragma once

#include "../Singleton.hpp"

class PlatformManager: public Singleton<PlatformManager> {
private:
    bool m_hidden = false;
    bool m_previouslyHidden = false;
    void resetCursor();
    void update();
    void init();

public:
    void setCursorVisibility(bool visible);
    bool getIsHidden();

};