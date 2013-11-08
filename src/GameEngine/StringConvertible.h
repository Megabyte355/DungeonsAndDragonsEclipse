/*
 * StringConvertible.h
 *
 *  Created on: Nov 7, 2013
 *      Author: Gary
 */

#ifndef STRINGCONVERTIBLE_H_
#define STRINGCONVERTIBLE_H_

#include <sstream>

class StringConvertible
{
    public:
        StringConvertible();
        virtual ~StringConvertible();

    protected:
        virtual std::string toString() = 0;
        virtual void fromString(std::string) = 0;
};

#endif /* STRINGCONVERTIBLE_H_ */
