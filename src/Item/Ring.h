/*
 * Ring.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#ifndef RING_H_
#define RING_H_

#include "Equipment.h"

class Ring: public Equipment {

protected:
	int charismanBonus;
	int wisdomBonus;
	int intBonus;
public:
	Ring();
	Ring(string name, int value, int weight, int charismanBonus, int wisdomBonus, int intBonus, string ptextureName);
	Ring(int charLevel, bool isRandom, string ptextureName);
	virtual ~Ring();
	string toString() override;
	string getClassName();

};

#endif /* RING_H_ */
