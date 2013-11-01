/*
 * TestScreen.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "TestScreen.h"

TestScreen::TestScreen(void) : Screen("TestScreen")
{
    int instances = rand() % 100 + 50;
    for (int i = instances; i > 0; i--)
    {
        k.push_back(new Kiwi(rand() % 800, rand() % 600, (rand() % 500 + 1) / (float)1000 ));
    }
}


TestScreen::~TestScreen(void)
{
    for (auto kiwi : k)
    {
        delete kiwi;
    }
}

void TestScreen::initialize()
{
    // Reset everything
}

void TestScreen::update(float gameTime)
{
    for (auto kiwi : k)
    {
        kiwi->update(gameTime);
    }
    o.Move(gameTime);
    
}

void TestScreen::draw()
{
    for (auto kiwi : k)
    {
        kiwi->draw();
    }
    o.draw();
}

void TestScreen::handleEvents(SDL_Event * event)
{
    switch(event->type)
    {
        case SDL_QUIT:
            GameConfig::getInstance()->gameIsRunning = false;
            break;
        case SDL_KEYDOWN:

            //std::cout << "Key pressed: " << event->key.keysym.sym << endl;
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                GameConfig::getInstance()->gameIsRunning = false;
            }
            switch (event->key.keysym.sym)
            {
                case SDLK_UP:
                    o.moveUp(true);
                    break;
                case SDLK_DOWN:
                    o.moveDown(true);
                    break;
                case SDLK_LEFT:
                    o.moveLeft(true);
                    break;
                case SDLK_RIGHT:
                    o.moveRight(true);
                    break;
                default:
                    break;
            }
            break;
        case SDL_KEYUP:
            //std::cout << "Key released: " << event->key.keysym.sym << endl;

            switch (event->key.keysym.sym)
            {
                case SDLK_UP:
                    o.moveUp(false);
                    break;
                case SDLK_DOWN:
                    o.moveDown(false);
                    break;
                case SDLK_LEFT:
                    o.moveLeft(false);
                    break;
                case SDLK_RIGHT:
                    o.moveRight(false);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
