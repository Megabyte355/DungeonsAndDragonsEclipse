/*
 * Util.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "Util.h"

void Util::logSDLError(std::ostream &os, const std::string &msg)
{
    os << msg << " error: " << SDL_GetError() << std::endl;
}
