//============================================================================
// Name        : Assignment 2
// Author      : Gary Chang
// Version     : 1.0
// Description : Implementation of the Observer Pattern over the Map classes
//============================================================================

#include "GameEngine/Game.h"
#include "GameEngine/GameConfig.h"
#include <iostream>
#include <memory>

int main(int argc, char** argv)
{
    // Initialization of Game object
    std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());
    if (!game)
    {
        std::cout << "Unable to load game" << std::endl;
        return 1;
    }


    //GameConfig::getInstance()->gameIsRunning = true;
    GameConfig * config = GameConfig::getInstance();
    config->gameIsRunning = true;

    // Setting up the game loop with constant frame rate
    SDL_Event event;
    Uint32 nextGameTick = SDL_GetTicks();
    int loopCount;
    float now = 0;
    float lastTick = 0;
    float deltaTime = 0;

    // Game loop logic
    while (config->gameIsRunning)
    {
        loopCount = 0;

        // While loop for constant update rate
        while (SDL_GetTicks() > nextGameTick && loopCount < GameConfig::MAX_FRAMESKIP)
        {
            now = SDL_GetTicks();
            deltaTime = now - lastTick;
            lastTick = now;
            game->update(deltaTime);
            nextGameTick += GameConfig::SKIP_TICKS;
            loopCount++;

            // Handle user input
            while (SDL_PollEvent(&event))
            {
                game->handleEvents(&event);
            }
        }

        // Draw graphics on screen
        game->draw();
    }

    return 0;
}
