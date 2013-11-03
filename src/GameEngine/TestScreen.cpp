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

    // Text test
//    SDL_Color color = {255, 255, 255};
//    SDL_Color color2 = {29, 209, 35};
//    SDL_Color red = {255, 0, 0};
    //TextRenderer::renderText(10, 10, "StarCraft", "assets/starcraft_font.ttf", color, 32);
    //TextRenderer::renderText(10, 60, "Hello World!!!", "assets/starcraft_font.ttf", color2, 50);
    //TextRenderer::renderText(10, 100, "Dungeons and Dragons", "assets/starcraft_font.ttf", red, 45);

    TextRenderer::renderText(10, 10, "StarCraft", "starcraft_font", TextRenderer::white, 32);
    TextRenderer::renderText(10, 60, "Hello World!!!", "arial_italic", TextRenderer::blue, 50);
    TextRenderer::renderText(10, 100, "Dungeons and Dragons", "calibri_bold", TextRenderer::red, 75);

    TextRenderer::renderText(20, 200, "White", "arial_black", TextRenderer::white, 25);
    TextRenderer::renderText(20, 230, "Red", "arial_black", TextRenderer::red, 25);
    TextRenderer::renderText(20, 260, "Blue", "arial_black", TextRenderer::blue, 25);
    TextRenderer::renderText(20, 290, "Green", "arial_black", TextRenderer::green, 25);
    TextRenderer::renderText(20, 320, "Black", "arial_black", TextRenderer::black, 25);
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
                //GameConfig::getInstance()->gameIsRunning = false;
                active = false;
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
        case SDL_MOUSEBUTTONDOWN:
            std::cout << "Left click? " << (event->button.button == SDL_BUTTON_LEFT) << std::endl;
            std::cout << "Right click? " << (event->button.button == SDL_BUTTON_RIGHT) << std::endl;
            std::cout << "Click at : (" << event->button.x << ", "<< event->button.y << ")" << std::endl;
            break;

        case SDL_MOUSEBUTTONUP:
            std::cout << "Left up? " << (event->button.button == SDL_BUTTON_LEFT) << std::endl;
            std::cout << "Right up? " << (event->button.button == SDL_BUTTON_RIGHT) << std::endl;
            std::cout << "Click at : (" << event->button.x << ", "<< event->button.y << ")" << std::endl;
            break;

        case SDL_MOUSEMOTION:
            std::cout << "Moving at : (" << event->motion.x << ", "<< event->motion.y << ")" << std::endl;
            break;
        default:
            break;
    }
}
