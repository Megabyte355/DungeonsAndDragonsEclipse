/*
 * FileIO.h
 *
 *  Created on: Nov 8, 2013
 *      Author: Gary
 */

#ifndef FILEIO_H_
#define FILEIO_H_


#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <sstream>


class FileIO
{
    public:
        FileIO(std::string prefix, std::string postfix);
        virtual ~FileIO();

        void save(int, std::string);
        std::string load(int);

    private:
        std::string prefix;
        std::string postfix;
};

#endif /* FILEIO_H_ */
