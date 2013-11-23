/*
 * Shield.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#ifndef SHIELD_H_
#define SHIELD_H_

#include "Equipment.h"

class Shield: public Equipment {

protected:
	
	int armorBonus;
	int strBonus;
	string shieldType;
	
public:
	Shield();
	Shield(string name, int value, int weight, int armorBonus, int strBonus, string shieldType);
	virtual ~Shield();
	string toString() override;
	string getClassName();

};

#endif /* SHIELD_H_ */
