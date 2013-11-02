/*
 * GameConfig.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef GAMECONFIG_H_
#define GAMECONFIG_H_

#include <string>

class GameConfig
{
    public:
        ~GameConfig();

        static GameConfig * getInstance();

        // Screen properties
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
        const static std::string GAME_TITLE;

        // Game loop settings
        const static int TICKS_PER_SECOND = 60;
        const static int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
        const static int MAX_FRAMESKIP = 5;
        static bool gameIsRunning;

        // Font settings
        const static int DEFAULT_FONT_SIZE = 12;

    private:
        GameConfig();
        static GameConfig * instance;
};

#endif /* GAMECONFIG_H_ */
