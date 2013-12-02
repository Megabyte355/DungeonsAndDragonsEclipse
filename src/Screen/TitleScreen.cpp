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
	audio->playMusic(1);
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

    text->setSettings("triforce", 30, TextRenderer::white, TextRenderer::black);
    text->renderTextWithShadow(425, 25, "Gary Chang");
    text->renderTextWithShadow(625, 25, "Tiffany Ip");
    text->renderTextWithShadow(425, 75, "Kevin Silva");
    text->renderTextWithShadow(625, 75, "Tim Smith");

    text->setSettings("triforce", 45, TextRenderer::white, TextRenderer::black);
    if (flickeringTextState)
    {
        text->renderTextWithShadow(507,527,flickeringText);
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
    ScreenManager::requestScreenChange("TitleScreen", "MainMenuScreen");
}
