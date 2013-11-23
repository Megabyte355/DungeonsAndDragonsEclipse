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

Shield::Shield(string name, int value, int weight, int armorBonus, int strBonus, string pshieldType):Equipment(name, value, weight){
	shieldType = pshieldType;
	possibleEnchants.push_back(characterStats::ARMOR);
    enchantEquipment();
	insertStatistic(characterStats::ARMOR, armorBonus);
	insertStatistic(characterStats::STRENGTH, strBonus);
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