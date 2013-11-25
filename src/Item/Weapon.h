/*
 * Weapon.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#ifndef WEAPON_H_
#define WEAPON_H_

#include "Equipment.h"

using namespace std;

class Weapon: public Equipment
{

    protected:

        int attackBonus;
        int damageBonus;
        string weaponType;
        int range;

    public:

        Weapon();
        Weapon(string name, int value, int weight, int attackBonus, int damageBonus, string pweaponType, int range);
        Weapon(int charLevel, bool isRandom, string pweaponType);
        virtual ~Weapon();
        string toString() override;
        string getClassName();

        int getRange() const {return range;}
        void setRange(int range) {this->range = range;}
        const string& getWeaponType() const {return weaponType;}
};

#endif /* WEAPON_H_ */
