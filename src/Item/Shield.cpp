/*
 * Shield.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Shield.h"

using namespace std;

Shield::Shield():Equipment() {
	name = "Generic Shield";
	armorBonus = 3;
	strBonus = 2 ;
	shieldType = "Light";
	possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
	insertStatistic(characterStats::ARMOR, armorBonus);
	insertStatistic(characterStats::STRENGTH, strBonus);
}

Shield::Shield(string pname, int pvalue, int pweight, int parmorBonus, int pstrBonus, string pshieldType):Equipment(pname, pvalue, pweight){
    armorBonus = parmorBonus;
    strBonus = pstrBonus;
	shieldType = pshieldType;
	possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
	insertStatistic(characterStats::ARMOR, armorBonus);
	insertStatistic(characterStats::STRENGTH, strBonus);
}

Shield::Shield(int charLevel, bool isRandom):Equipment(charLevel, isRandom){
    name = "Randomly Generated Shield";
    armorBonus = rand() % charLevel;
    strBonus = rand() % charLevel;
	shieldType = "Random Type";
    possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
    insertStatistic(characterStats::ARMOR, armorBonus);
    insertStatistic(characterStats::STRENGTH, strBonus);
    generateRandomStats(charLevel);
}

Shield::~Shield() {
}

string Shield::toString(){
	stringstream ss;
	ss << Equipment::toString();
	ss << "Shield Type: " << shieldType << endl;
	return ss.str();
}

string Shield::getClassName(){
	return "Shield";
}
