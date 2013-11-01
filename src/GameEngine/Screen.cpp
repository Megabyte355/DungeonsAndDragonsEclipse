/*
 * Screen.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "Screen.h"

Screen::Screen(std::string name)
{
    uniqueName = name;
}


Screen::~Screen(void)
{
}

std::string Screen::getName()
{
    return uniqueName;
}
