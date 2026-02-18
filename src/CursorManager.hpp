#pragma once

#include "Singleton.hpp"
#include "Cursor.hpp"

class CursorManager: public Singleton<CursorManager> {
private:
    SimpleCursor* m_cursor = nullptr;

public:
    bool m_forceHide = false;
    float m_cursorSize;
    void updateOrInit();
    void updateToPosition();
};