/*
 * Game.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "Game.h"

Game::Game(void)
{
    screenManager = nullptr;
    renderer = nullptr;
    window = nullptr;
    textures = nullptr;
    texts = nullptr;

    initialize();
}

Game::~Game(void)
{
    screenManager.reset();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    delete textures;
    delete texts;
    std::cout << "Game Destroyed" << std::endl;
}

void Game::initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Util::logSDLError(std::cout, "SDL_Init");
        return;
    }
    if (TTF_Init() == -1)
    {
        std::cout << TTF_GetError() << std::endl;
        return;
    }
    window = SDL_CreateWindow(GameConfig::GAME_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        Util::logSDLError(std::cout, "SDL_CreateWindow");
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        Util::logSDLError(std::cout, "SDL_CreateRenderer");
        return;
    }
    
    textures = TextureRenderer::getInstance();
    textures->setRenderer(renderer);
    textures->loadAllTextures();
    texts = TextRenderer::getInstance();
    texts->setRenderer(renderer);
    texts->loadFontPaths();
    screenManager = ScreenManager::getInstance();
    screenManager->initialize();

    GameConfig::getInstance()->gameIsRunning = true;

    std::cout << "Game Started" << std::endl;
}

void Game::update(float gameTime)
{
    screenManager->update(gameTime);
}

void Game::draw()
{
    SDL_RenderClear(renderer);
    screenManager->draw();
    SDL_RenderPresent(renderer);
}

void Game::handleEvents(SDL_Event * event)
{
    screenManager->handleEvents(event);
}
