/*
 * Armor.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#ifndef ARMOR_H_
#define ARMOR_H_

#include "Equipment.h"

using namespace std;

class Armor: public Equipment
{

    protected:
        int armorBonus;
		string armorType;
    public:
        Armor();
		Armor(string pname, int pvalue, int pweight, string parmorType, int parmorBonus, string ptextureName);
		Armor(int charLevel, bool isRandom, string ptextureName);
        virtual ~Armor();
		string toString() override;
		string getClassName();
};

#endif /* ARMOR_H_ */
