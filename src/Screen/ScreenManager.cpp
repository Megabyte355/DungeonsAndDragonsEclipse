/*
 * ScreenManager.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "ScreenManager.h"

std::shared_ptr<ScreenManager> ScreenManager::instance;

ScreenManager::ScreenManager()
{
}

ScreenManager::~ScreenManager()
{
    while (!storedScreens.empty())
    {
        storedScreens.back().reset();
        storedScreens.pop_back();
    }
    activeScreens.clear();
    screensToProcess.clear();

    std::cout << "ScreenManager destroyed" << std::endl;
}

std::shared_ptr<ScreenManager> ScreenManager::getInstance()
{
    if (!instance)
    {
        instance = std::shared_ptr<ScreenManager>(new ScreenManager());
    }
    return instance;
}

void ScreenManager::initialize()
{
    storedScreens.push_back(std::make_shared<TestScreen>());
    pushScreen("TestScreen");
//    storedScreens.push_back(std::make_shared<MenuScreen>());
//    pushScreen("MenuScreen");
}

// Move a screen from storedScreen to activeScreens
void ScreenManager::pushScreen(std::shared_ptr<Screen> s)
{
    s->active = true;
    activeScreens.push_back(s);
}

void ScreenManager::pushScreen(std::string s)
{
    for (std::vector<std::shared_ptr<Screen>>::iterator it = storedScreens.begin(); it != storedScreens.end(); it++)
    {
        if ((*it)->getName() == s)
        {
            (*it)->active = true;
            activeScreens.push_back(*it);
            break;
        }
    }
}

// Remove a screen from activeScreens and screensToUpdate
void ScreenManager::popScreen(std::shared_ptr<Screen> s)
{
    popScreen(s->getName());
}

void ScreenManager::popScreen(std::string s)
{
    for (std::vector<std::shared_ptr<Screen>>::iterator it = activeScreens.begin(); it != activeScreens.end(); it++)
    {
        if ((*it)->getName() == s)
        {
            activeScreens.erase(it);
            break;
        }
    }
}

void ScreenManager::popScreen(int instanceId)
{
    for (std::vector<std::shared_ptr<Screen>>::iterator it = activeScreens.begin(); it != activeScreens.end(); it++)
    {
        if ((*it)->getInstanceId() == instanceId)
        {
            activeScreens.erase(it);
            break;
        }
    }
}

void ScreenManager::update(float gameTime)
{
    // End the program if there are no active screens
    if (activeScreens.empty())
    {
        GameConfig::getInstance()->gameIsRunning = false;
    }

    // For each screen in active screens, perform Update()
    copyActiveScreens();
    for (auto s : screensToProcess)
    {
        s->update(gameTime);
        
        // If no longer active, remove from activeScreens vector
        if (!s->active)
        {
            popScreen(s->getInstanceId());
        }
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
