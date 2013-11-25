/*
 * Ring.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Ring.h"

Ring::Ring():Equipment() {
	name = "Generic Ring";
	charismanBonus = 1;
	wisdomBonus = 1;
	intBonus = 1;
	possibleEnchants.push_back(characterStats::ARMOR);
	possibleEnchants.push_back(characterStats::STRENGTH);
	possibleEnchants.push_back(characterStats::CONSTITUTION);
	possibleEnchants.push_back(characterStats::WISDOM);
	possibleEnchants.push_back(characterStats::CHARISMA);
	enchantEquipment();
	insertStatistic(characterStats::CHARISMA, charismanBonus);
	insertStatistic(characterStats::WISDOM, wisdomBonus);
	insertStatistic(characterStats::INTELLIGENCE, intBonus);

}

Ring::Ring(string name, int value, int weight, int charismanBonus, int wisdomBonus, int intBonus):Equipment(name, value, weight){
	possibleEnchants.push_back(characterStats::ARMOR);
	possibleEnchants.push_back(characterStats::STRENGTH);
	possibleEnchants.push_back(characterStats::CONSTITUTION);
	possibleEnchants.push_back(characterStats::WISDOM);
	possibleEnchants.push_back(characterStats::CHARISMA);
	enchantEquipment();
	insertStatistic(characterStats::CHARISMA, charismanBonus);
	insertStatistic(characterStats::WISDOM, wisdomBonus);
	insertStatistic(characterStats::INTELLIGENCE, intBonus);
}

Ring::~Ring() {
}

string Ring::toString(){
	stringstream ss;
	ss << Equipment::toString();
	return ss.str();
}

string Ring::getClassName(){
	return "Ring";
}
