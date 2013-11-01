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

        void update(float);
        void draw();
        void handleEvents(SDL_Event * event);

    private:
        ScreenManager();

        static std::shared_ptr<ScreenManager> instance;
        std::vector<std::shared_ptr<Screen>> storedScreens;
        std::vector<std::shared_ptr<Screen>> activeScreens;
        std::vector<std::shared_ptr<Screen>> screensToProcess;

        void copyActiveScreens();
        void cleanCopiedScreens();
};

#endif /* SCREENMANAGER_H_ */
