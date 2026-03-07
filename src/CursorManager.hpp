#pragma once

#include "Singleton.hpp"
#include "Cursor.hpp"

class CursorManager: public Singleton<CursorManager> {
private:
    float m_cursorSize;
    bool m_enableTrail = false;

    Ref<SimpleCursor> m_cursor = nullptr;

public:
    bool m_forceHide = false;

    void createCursor();
    void enableTrail(bool enable);
    void update();
    void setCursorSize(int size);
};