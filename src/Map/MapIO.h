/*
 * MapIO.h
 *
 *  Created on: Nov 8, 2013
 *      Author: Gary
 */

#ifndef MAPIO_H_
#define MAPIO_H_

#include "FileIO.h"
#include <sstream>
#include <memory>
#include <iostream>

class MapIO: public virtual FileIO
{
    public:
        MapIO( void (*loader)(std::string), std::string (*saver)());
        ~MapIO();

        void save(int slot) override;
        void load(int slot) override;

    private:
        std::string prefix;
        std::string postfix;

        // Function pointers
        std::string (*saver)();
        void (*loader)(std::string);
};

#endif /* MAPIO_H_ */
