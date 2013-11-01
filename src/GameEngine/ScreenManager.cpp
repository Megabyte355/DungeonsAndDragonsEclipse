/*
 * ScreenManager.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "ScreenManager.h"

ScreenManager* ScreenManager::screenManagerInstance = nullptr;

ScreenManager::ScreenManager(void)
{
}

ScreenManager::~ScreenManager(void)
{
    while (!storedScreens.empty())
    {
        delete storedScreens.back();
        storedScreens.pop_back();
    }
    activeScreens.clear();
    screensToProcess.clear();
}

ScreenManager * ScreenManager::getInstance()
{
    if (screenManagerInstance == nullptr)
    {
        screenManagerInstance = new ScreenManager();
    }
    return screenManagerInstance;
}

void ScreenManager::initialize()
{
    storedScreens.push_back(new TestScreen());

    pushScreen("TestScreen");
}

// Move a screen from storedScreen to activeScreens
void ScreenManager::pushScreen(Screen * s)
{
    s->initialize();
    activeScreens.push_back(s);
}

void ScreenManager::pushScreen(std::string s)
{
    for (std::vector<Screen*>::iterator it = storedScreens.begin(); it != storedScreens.end(); it++)
    {
        if ((*it)->getName() == s)
        {
            activeScreens.push_back(*it);
            break;
        }
    }
}

// Remove a screen from activeScreens and screensToUpdate
void ScreenManager::popScreen(Screen * s)
{
    popScreen(s->getName());
}

void ScreenManager::popScreen(std::string s)
{
    for (std::vector<Screen*>::iterator it = activeScreens.begin(); it != activeScreens.end(); it++)
    {
        if ((*it)->getName() == s)
        {
            activeScreens.erase(it);
            break;
        }
    }
}

void ScreenManager::update(float gameTime)
{
    // For each screen in active screens, perform Update()
    copyActiveScreens();
    for (auto s : screensToProcess)
    {
        s->update(gameTime);
    }
    cleanCopiedScreens();
}

void ScreenManager::draw()
{
    // For each screen in active screens, perform Draw()
    copyActiveScreens();
    for (auto s : screensToProcess)
    {
        s->draw();
    }
    cleanCopiedScreens();
}

void ScreenManager::handleEvents(SDL_Event * event)
{
    // For each screen in active screens, perform HandleEvents()
    copyActiveScreens();
    for (auto s : screensToProcess)
    {
        s->handleEvents(event);
    }
    cleanCopiedScreens();
}


void ScreenManager::copyActiveScreens()
{
    // Copy all screens in activeScreens to screensToProcess vector
    for (auto s : activeScreens)
    {
        screensToProcess.push_back(s);
    }
}

void ScreenManager::cleanCopiedScreens()
{
    screensToProcess.clear();
}
