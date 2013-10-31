/*
 * ScreenManager.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include <vector>
#include "Screen.h"
#include "TestScreen.h"

// Forward declaration
class Game;
class Screen;


class ScreenManager
{
public:
    static ScreenManager * GetInstance();
    ~ScreenManager(void);

    void Initialize();
    void PushScreen(Screen * s);
    void PushScreen(std::string s);
    void PopScreen(Screen * s);
    void PopScreen(std::string s);

    void Update(float);
    void Draw();
    void HandleEvents(SDL_Event * event);

private:
    ScreenManager(void);

    static ScreenManager* screenManagerInstance;
    std::vector<Screen*> storedScreens;
    std::vector<Screen*> activeScreens;
    std::vector<Screen*> screensToProcess;

    void CopyActiveScreens();
    void CleanCopiedScreens();
};

#endif /* SCREENMANAGER_H_ */
