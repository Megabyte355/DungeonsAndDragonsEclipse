/*
 * GameConfig.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "GameConfig.h"

// Variables that cannot be initialized in header file
GameConfig* GameConfig::instance = nullptr;
const std::string GameConfig::GAME_TITLE = "Dungeons and Dragons";
bool GameConfig::gameIsRunning = false;

GameConfig::GameConfig()
{
}

GameConfig::~GameConfig()
{
}

GameConfig * GameConfig::getInstance()
{
    if (instance == nullptr)
    {
        instance = new GameConfig();
    }
    return instance;
}
