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

Weapon::Weapon(string pname, int pvalue, int pweight, int pattackBonus, int pdamageBonus, string pweaponType, int prange):Equipment(pname, pvalue, pweight){
	weaponType = pweaponType;
	range = prange;
    attackBonus = pattackBonus;
    damageBonus = pdamageBonus;
	possibleEnchants.push_back(characterStats::ATTACK);
	possibleEnchants.push_back(characterStats::DAMAGE);
    enchantEquipment();
	insertStatistic(characterStats::ATTACK, attackBonus);
	insertStatistic(characterStats::DAMAGE, damageBonus);
}

Weapon::Weapon(int charLevel, bool isRandom, string pweaponType):Equipment(charLevel, isRandom){
    name = "Randomly Generated Weapon";
    weaponType = pweaponType;
    if(weaponType == "Sword"){
        range = 1;
    }else if(weaponType == "Bow"){
        range = rand()%charLevel + 5;
    }
    attackBonus = (rand() % charLevel) + 8;
    damageBonus = (rand() % charLevel) + 8;
    possibleEnchants.push_back(characterStats::ATTACK);
    possibleEnchants.push_back(characterStats::DAMAGE);
    enchantEquipment();
    insertStatistic(characterStats::ATTACK, attackBonus);
    insertStatistic(characterStats::DAMAGE, damageBonus);
    generateRandomStats(charLevel);
}

Weapon::~Weapon() {
}

int Weapon::getAttackBonus()
{
    return attackBonus;
}

int Weapon::getDamageBonus()
{
    return damageBonus;
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
