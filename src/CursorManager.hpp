#pragma once

#include "Singleton.hpp"
#include "cursor.hpp"

class CursorManager: public Singleton<CursorManager> {
private:
    SimpleCursor* m_cursor;

public:
    void updateOrInit();
    void updateToPosition();
};