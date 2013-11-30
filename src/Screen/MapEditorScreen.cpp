/*
 * MapEditorScreen.cpp
 *
 *  Created on: Nov 28, 2013
 *      Author: Gary
 */

#include "MapEditorScreen.h"

MapEditorScreen::MapEditorScreen() :
        Screen("MapEditorScreen")
{
}

MapEditorScreen::~MapEditorScreen()
{
}

void MapEditorScreen::initialize()
{
    active = true;

    tileOptionList = new MapTileOptionList(625,225,150,350,5);
//    MenuOption * opt;
//    opt = new MenuOption(200, 200, 25, "Create new map");
//    opt->setVisibility(true);
//    opt->setCallback(std::bind(&MapEditorScreen::goToNewGameScreen, this));
//    menuOptions.push_back(opt);
//    opt = new MenuOption(200, 300, 25, "Load pre-made map");
//    opt->setVisibility(true);
//    opt->setCallback(std::bind(&MapEditorScreen::goToEditorMenuScreen, this));
//    menuOptions.push_back(opt);
//    opt = new MenuOption(200, 400, 25, "Load saved map");
//    opt->setVisibility(true);
//    opt->setCallback(std::bind(&MapEditorScreen::goToCreditScreen, this));
//
//    opt = new MenuOption(200, 550, 25, "Back");
//    opt->setVisibility(true);
//    opt->setCallback(std::bind(&MapEditorScreen::goToCreditScreen, this));
//    menuOptions.push_back(opt);
//    opt = nullptr;
}

void MapEditorScreen::reset()
{
//    for (auto o : menuOptions)
//    {
//        delete o;
//    }
//    menuOptions.clear();
    delete tileOptionList;
    tileOptionList = nullptr;
}

void MapEditorScreen::update(float deltaTime)
{
}

void MapEditorScreen::draw()
{
    TextureRenderer * textures = TextureRenderer::getInstance();
    textures->drawTexture("background", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);

    tileOptionList->draw();

    textures = nullptr;
}

void MapEditorScreen::handleEvents(SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_QUIT:
            GameConfig::getInstance()->gameIsRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                active = false;
            }
            break;
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEMOTION:
            tileOptionList->handleEvents(event);
            break;
        default:
            break;
    }
}
