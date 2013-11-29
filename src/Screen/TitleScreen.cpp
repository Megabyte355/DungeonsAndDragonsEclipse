/*
 * TitleScreen.cpp
 *
 *  Created on: Nov 23, 2013
 *      Author: Gary
 */

#include <TitleScreen.h>

TitleScreen::TitleScreen() :
        Screen("TitleScreen")
{
    flickeringDelay = 500;
    flickeringText = "Press any key";
    currentFlickerTime = 0;
    flickeringTextState = false;
}

TitleScreen::~TitleScreen()
{
    reset();
}

void TitleScreen::initialize()
{
    flickeringTextState = false;
}

void TitleScreen::reset()
{
}

void TitleScreen::update(float deltaTime)
{
    currentFlickerTime += deltaTime;
    if (currentFlickerTime > flickeringDelay)
    {
        flickeringTextState = !flickeringTextState;
        currentFlickerTime = 0;
    }
}

void TitleScreen::draw()
{
    GameConfig * config = GameConfig::getInstance();
    TextureRenderer::getInstance()->drawTexture("title_screen", 0, 0, config->SCREEN_WIDTH, config->SCREEN_HEIGHT);
    TextRenderer * text = TextRenderer::getInstance();

    // White text
    text->setSettings("triforce", 30, TextRenderer::black);
    text->renderText(425, 25, "Gary Chang");
    text->renderText(625, 25, "Tiffany Ip");
    text->renderText(425, 75, "Kevin Silva");
    text->renderText(625, 75, "Tim Smith");

    // Shadow
    text->setSettings("triforce", 30, TextRenderer::white);
    text->renderText(423, 23, "Gary Chang");
    text->renderText(623, 23, "Tiffany Ip");
    text->renderText(423, 73, "Kevin Silva");
    text->renderText(623, 73, "Tim Smith");

    if (flickeringTextState)
    {
        text->renderText(507, 527, flickeringText, "triforce", TextRenderer::black, 45);
        text->renderText(505, 525, flickeringText, "triforce", TextRenderer::white, 45);
    }

    config = nullptr;
    text = nullptr;
}

void TitleScreen::handleEvents(SDL_Event& event)
{
    if (event.type == SDL_QUIT)
    {
        GameConfig::getInstance()->gameIsRunning = false;
    }
    else if (event.key.keysym.sym == SDLK_ESCAPE)
    {
        active = false;
    }
    else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONUP)
    {
        goToMenuScreen();
    }
}

void TitleScreen::goToMenuScreen()
{
    ScreenManager::requestScreenChange("TitleScreen", "MenuScreen");
}
