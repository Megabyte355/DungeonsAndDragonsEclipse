/*
 * ScreenManager.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include <vector>
#include <memory>
#include "Screen.h"
#include "TestScreen.h"
#include "MenuScreen.h"
#include "CharacterScreen.h"
#include "MapScreen.h"
#include "TitleScreen.h"
#include "MainMenuScreen.h"
#include "EditorMenuScreen.h"

// Forward declaration
class Game;
class Screen;

class ScreenManager
{
    public:
        static std::shared_ptr<ScreenManager> getInstance();
        ~ScreenManager(void);

        void initialize();
        void pushScreen(std::shared_ptr<Screen> s);
        void pushScreen(std::string s);
        void popScreen(std::shared_ptr<Screen> s);
        void popScreen(std::string s);
        void popScreen(int instanceId);

        void update(float);
        void draw();
        void handleEvents(SDL_Event &event);

        // Screen change request function
        static void requestScreenChange(std::string, std::string);

    private:
        ScreenManager();

        static std::shared_ptr<ScreenManager> instance;
        std::vector<std::shared_ptr<Screen>> storedScreens;
        std::vector<std::shared_ptr<Screen>> activeScreens;
        std::vector<std::shared_ptr<Screen>> screensToProcess;

        void copyActiveScreens();
        void cleanCopiedScreens();

        // Screen change request variables
        static bool changeScreenRequest;
        static std::string nextScreenName;
        static std::string previousScreenName;
};

#endif /* SCREENMANAGER_H_ */
