/*
 * MenuScreen.cpp
 *
 *  Created on: Nov 7, 2013
 *      Author: Gary
 */

#include "MenuScreen.h"

MenuScreen::MenuScreen() :
        Screen("MenuScreen")
{
    initialize();
}

MenuScreen::~MenuScreen()
{
    reset();
}

void MenuScreen::initialize()
{
    active = true;
    textures = TextureRenderer::getInstance();
    texts = TextRenderer::getInstance();

    pressAnyKeyToggleOverTime = false;
    displayDelay = 500;
    currentTime = 0;

    Button * button = new Button(325, 325, 15, "Character Editor");
    button->setOnClick(std::bind(&MenuScreen::goToCharacterScreen, this));
    menuOptions.push_back(button);

    button = new Button(325, 400, 15, "Map Editor");
    button->setOnClick(std::bind(&MenuScreen::goToMapScreen, this));
    menuOptions.push_back(button);
    button = nullptr;

    pressAnyKeyDisplay = true;
    showMenu = false;
}

void MenuScreen::update(float deltaTime)
{
    if (pressAnyKeyDisplay)
    {
        currentTime += deltaTime;
        if (currentTime > displayDelay)
        {
            pressAnyKeyToggleOverTime = !pressAnyKeyToggleOverTime;
            currentTime = 0;
        }
    }
}

void MenuScreen::draw()
{
    textures->drawTexture("bizzare_landscape", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);
    textures->drawTexture("ddlogo", 95, -100, 600, 450);
    //400 x 300
    texts->renderText(252, 227, "Mini Edition", "starcraft_font", TextRenderer::black, 40);
    texts->renderText(250, 225, "Mini Edition", "starcraft_font", TextRenderer::red, 40);

    texts->renderText(50, 450, "Gary Chang", "calibri", TextRenderer::white, 22);
    texts->renderText(50, 480, "Tiffany Ip", "calibri", TextRenderer::white, 22);
    texts->renderText(50, 510, "Kevin Silva", "calibri", TextRenderer::white, 22);
    texts->renderText(50, 540, "Tim Smith", "calibri", TextRenderer::white, 22);

    texts->renderText(GameConfig::SCREEN_WIDTH - 200, GameConfig::SCREEN_HEIGHT - 50, "Not a real product", "calibri",
            TextRenderer::white, 20);

    if (pressAnyKeyToggleOverTime)
    {
        texts->renderText(320, 325, "Press any key", "calibri", TextRenderer::white, 30);
    }

    for (auto o : menuOptions)
    {
        if (o->isVisible())
        {
            o->draw();
        }
    }
}

void MenuScreen::handleEvents(SDL_Event &event)
{

    if (event.type == SDL_QUIT)
    {
        GameConfig::getInstance()->gameIsRunning = false;
    }
    else if (event.key.keysym.sym == SDLK_ESCAPE)
    {
        active = false;
    }
    else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_KEYDOWN)
    {
        if (!showMenu)
        {
            showMenu = true;
            pressAnyKeyDisplay = false;
            pressAnyKeyToggleOverTime = false;
            for (auto o : menuOptions)
            {
                o->toggleVisibility();
            }
        }
        else
        {
            for (auto o : menuOptions)
            {
                o->handleEvents(event);
            }
        }
    }
    else if (event.type == SDL_MOUSEMOTION)
    {
        for (auto o : menuOptions)
        {
            o->handleEvents(event);
        }
    }
}

void MenuScreen::reset()
{
// MenuScreen is not responsible for destroying renderers
    textures = nullptr;
    texts = nullptr;
    for (auto m : menuOptions)
    {
        delete m;
    }
    menuOptions.clear();
}

void MenuScreen::goToCharacterScreen()
{
    ScreenManager::requestScreenChange("MenuScreen", "CharacterScreen");
}

void MenuScreen::goToMapScreen()
{
    ScreenManager::requestScreenChange("MenuScreen", "MapScreen");
}
