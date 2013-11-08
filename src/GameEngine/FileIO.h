/*
 * FileIO.h
 *
 *  Created on: Nov 8, 2013
 *      Author: Gary
 */

#ifndef FILEIO_H_
#define FILEIO_H_

#include "StringConvertible.h"
#include <iostream>
#include <iostream>
#include <fstream>

class FileIO
{
    public:
        FileIO();
        virtual ~FileIO();

        virtual void save(int) = 0;
        virtual void load(int) = 0;
};

#endif /* FILEIO_H_ */
