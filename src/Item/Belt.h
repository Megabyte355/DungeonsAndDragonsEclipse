/*
 * Belt.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#ifndef BELT_H_
#define BELT_H_
#include "Equipment.h"

using namespace std;

class Belt: public Equipment {

protected:
	int consitutionBonus;

public:
	Belt();
	Belt(string pname, int pvalue, int pweight, int pconsitutionBonus);
	virtual ~Belt();
	string toString() override;
	string getClassName();
};

#endif /* BELT_H_ */
