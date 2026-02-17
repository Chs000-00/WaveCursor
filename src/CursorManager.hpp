#pragma once

#include "Singleton.hpp"
#include "Cursor.hpp"

class CursorManager: public Singleton<CursorManager> {
private:
    SimpleCursor* m_cursor = nullptr;

public:
    void updateOrInit();
    void updateToPosition();
    void visible(bool state);
};