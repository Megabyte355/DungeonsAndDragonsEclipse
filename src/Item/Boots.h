/*
 * Boots.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#ifndef BOOTS_H_
#define BOOTS_H_

#include "Equipment.h"

class Boots: public Equipment {

protected:
	int armorBonus;
	int dexBonus;
public:
	Boots();
	Boots(string pname, int pvalue, int pweight, int parmorBonus, int pdexBonus);
	virtual ~Boots();
	string toString() override;
	string getClassName();
};

#endif /* BOOTS_H_ */
