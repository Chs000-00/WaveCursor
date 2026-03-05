#pragma once

#include "../Singleton.hpp"

class PlatformManager: public Singleton<PlatformManager> {
private:
    bool m_shown = true;
    bool m_previouslyShown = true;

    bool m_didJustEnterScreen = true;
    bool m_stateBeforeScreenExit = true;

    // Shows or hides the cursor based off if it should be shown & if it is on screen.
    void resetCursor();

    // Init function called on all platforms.
    void sharedInit();


public:
    // Call resetCursor(); each iteration
    void update();

    // Sets the cursor visibility.
    void setCursorVisibility(bool visible);

    // Returns if the cursor is hidden currently
    bool getIsHidden();

    // Initlizes the platform & cursor.
    void init();

    // Check if cursor is within the game screen.
    static bool isCursorOnScreen();
};