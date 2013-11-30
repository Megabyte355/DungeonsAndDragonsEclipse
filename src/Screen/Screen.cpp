/*
 * Screen.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "Screen.h"

int Screen::instanceIdCounter = 0;

Screen::Screen(std::string name)
{
    uniqueName = name;
    active = false;
    paused = false;
    instanceId = instanceIdCounter++;
    audio = AudioManager::getInstance();
}


Screen::~Screen(void)
{
}

int Screen::getInstanceId()
{
    return instanceId;
}

std::string Screen::getScreenName()
{
    return uniqueName;
}
