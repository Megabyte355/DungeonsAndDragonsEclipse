/*
 * Game.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef GAME_H_
#define GAME_H_

#include "GameConfig.h"
#include "Util.h"
#include "ScreenManager.h"
#include "Textures.h"
#include <iostream>
#include <string>
#include <SDL.h>

// Forward declaration
class ScreenManager;

class Game
{
public:
    ScreenManager * screenManager;
    SDL_Renderer * renderer;
    SDL_Window * window;
    bool isRunning;

    Game(void);
    ~Game(void);

    void Initialize();
    void Update(float);
    void Draw();
    void HandleEvents(SDL_Event * event);
};

#endif /* GAME_H_ */
