/*
 * Weapon.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Weapon.h"

Weapon::Weapon():Equipment() {
	name = "Generic Warrior Sword";
	weaponType = "Sword";
	range = 1; //WE ASSUME SWORD RANGE IS 1 SQUARE
	attackBonus = 8;
	damageBonus = 8;
	possibleEnchants.push_back(characterStats::ATTACK);
	possibleEnchants.push_back(characterStats::DAMAGE);
    enchantEquipment();
	insertStatistic(characterStats::ATTACK, attackBonus);
	insertStatistic(characterStats::DAMAGE, damageBonus);

}

Weapon::Weapon(string name, int value, int weight, int attackBonus, int damageBonus, string pweaponType, int prange):Equipment(name, value, weight){
	weaponType = pweaponType;
	range = prange;
	possibleEnchants.push_back(characterStats::ATTACK);
	possibleEnchants.push_back(characterStats::DAMAGE);
    enchantEquipment();
	insertStatistic(characterStats::ATTACK, attackBonus);
	insertStatistic(characterStats::DAMAGE, damageBonus);
}
Weapon::~Weapon() {
}

string Weapon::toString(){
	stringstream ss;
	ss << Equipment::toString();
	ss << "Weapon Type: " << weaponType << endl;
	return ss.str();
}

string Weapon::getClassName(){
	return "Weapon";
}
