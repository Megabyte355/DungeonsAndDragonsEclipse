/*
 * GameConfig.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "GameConfig.h"

GameConfig* GameConfig::instance = nullptr;

GameConfig::GameConfig()
{
    gameIsRunning = false;
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
