/*
 * StringStreamable.h
 *
 *  Created on: Nov 7, 2013
 *      Author: Gary
 */

#ifndef STRINGSTREAMABLE_H_
#define STRINGSTREAMABLE_H_

#include <sstream>

class StringConvertible
{
    public:
        StringConvertible();
        virtual ~StringConvertible();

        virtual std::string toString() = 0;
        virtual void fromString(std::string) = 0;
    protected:
        std::stringstream ss;
};

#endif /* STRINGSTREAMABLE_H_ */
