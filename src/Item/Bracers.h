/*
 * Bracers.h
 *
 *  Created on: Nov 23, 2013
 *      Author: Kevin
 */

#ifndef BRACERS_H_
#define BRACERS_H_

#include "Equipment.h"

using namespace std;

class Bracers: public Equipment
{
    public:
        Bracers();
        Bracers(string pname, int pvalue, int pweight);
        virtual ~Bracers();

        string toString() override;
        string getClassName();
};

#endif /* BRACERS_H_ */
