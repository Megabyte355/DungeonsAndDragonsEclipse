/*
 * Recordable.h
 *
 *  Created on: Nov 7, 2013
 *      Author: Gary
 */

#ifndef RECORDABLE_H_
#define RECORDABLE_H_

#include "FileIO.h"
#include <sstream>

class Recordable
{
    public:
        virtual ~Recordable();

        void save(int);
        void load(int);

    protected:
        virtual std::string toString() = 0;
        virtual void fromString(std::string) = 0;

        FileIO * fileHandler;
};

#endif /* RECORDABLE_H_ */
