/*
 * Util.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <ostream>
#include <SDL.h>
#include <string>


class Util
{
    public:
        static void logSDLError(std::ostream &os, const std::string &msg);

};

#endif /* UTIL_H_ */
