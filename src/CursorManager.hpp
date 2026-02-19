#pragma once

#include "Singleton.hpp"
#include "Cursor.hpp"

class CursorManager: public Singleton<CursorManager> {
private:
    SimpleCursor* m_cursor = nullptr;
    float m_cursorSize;
    bool m_enableTrail = false;

public:
    bool m_forceHide = false;

    void createCursor();
    void enableTrail(bool enable);
    void update();
    void setCursorSize(int size);
};