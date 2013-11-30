/*
 * Helmet.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#ifndef HELMET_H_
#define HELMET_H_
#include "Equipment.h"

using namespace std;

class Helmet: public Equipment
{
    protected:
        int armorBonus;

    public:

        Helmet();
		Helmet(string pname, int pvalue, int pweight, int parmorBonus, string ptextureName);
		Helmet(int charLevel, bool isRandom, string ptextureName);
        virtual ~Helmet();
		string toString() override;
		string getClassName();
};

#endif /* HELMET_H_ */
