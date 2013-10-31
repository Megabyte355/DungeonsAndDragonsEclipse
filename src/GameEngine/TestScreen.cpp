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

void TestScreen::Instance()
{

}

void TestScreen::Initialize()
{
    // Reset everything
}

void TestScreen::Update(float gameTime)
{
    for (auto kiwi : k)
    {
        kiwi->Update(gameTime);
    }
    o.Move(gameTime);
    
}

void TestScreen::Draw()
{
    for (auto kiwi : k)
    {
        kiwi->Draw();
    }
    o.Draw();
}

void TestScreen::HandleEvents(SDL_Event * event)
{
    switch(event->type)
    {
        case SDL_QUIT:
            GameConfig::gameIsRunning = false;
            break;
        case SDL_KEYDOWN:

            //std::cout << "Key pressed: " << event->key.keysym.sym << endl;
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                GameConfig::gameIsRunning = false;
            }
            switch (event->key.keysym.sym)
            {
                case SDLK_UP:
                    o.MoveUp(true);
                    break;
                case SDLK_DOWN:
                    o.MoveDown(true);
                    break;
                case SDLK_LEFT:
                    o.MoveLeft(true);
                    break;
                case SDLK_RIGHT:
                    o.MoveRight(true);
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
                    o.MoveUp(false);
                    break;
                case SDLK_DOWN:
                    o.MoveDown(false);
                    break;
                case SDLK_LEFT:
                    o.MoveLeft(false);
                    break;
                case SDLK_RIGHT:
                    o.MoveRight(false);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
