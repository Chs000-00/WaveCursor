#pragma once

#include "../Singleton.hpp"

class PlatformManager: public Singleton<PlatformManager> {
private:
    bool m_shown = true;
    bool m_previouslyShown = true;

    // Shows or hides the cursor based off if it should be shown & if it is on screen.
    void resetCursor();

    // Init function called on all platforms.
    void sharedInit();

    // Check if cursor is within the game screen.
    bool isCursorOnScreen();

    // Call resetCursor(); each iteration
    void update();


public:

    // Sets the cursor visibility.
    void setCursorVisibility(bool visible);

    // Returns if the cursor is hidden currently
    bool getIsHidden();

    // Initlizes the platform & cursor.
    void init();
};