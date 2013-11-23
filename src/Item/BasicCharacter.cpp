/*
 * BasicCharacter.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "BasicCharacter.h"

using namespace std;

BasicCharacter::BasicCharacter() {
    charName = "John Doe";
    str = 5, con = 5, dex = 5, intel = 5, wis = 5, cha = 5;
    totalArmor = 0;
    totalAttack = 0;
    totalDamage = 0;
	backpack = new ItemContainer(containerType_t::backpack);
	wornInventory = new ItemContainer(containerType_t::wornInventory);
}

//I have assumed that all these parameters will be defined in a proper character class that regards d20 rules.
BasicCharacter::BasicCharacter(string pname, int pstr, int pcon, int pdex, int pintel, int pwis, int pcha,
        int ptotalArmor, int ptotalAttack, int ptotalDamage) {
    charName = pname;
    str = pstr, con = pcon, dex = pdex, intel = pintel, wis = pwis, cha = pcha;
    totalArmor = ptotalArmor;
    totalAttack = ptotalAttack;
    totalDamage = ptotalDamage;
	backpack = new ItemContainer(containerType_t::backpack);
	wornInventory = new ItemContainer(containerType_t::wornInventory);

}

void BasicCharacter::displayCharacterStats() {
    cout << charName << "'s Character Statistics:" << std::endl;
    cout << "STR: " << str << "\t CON: " << con << "\t DEX: " << dex << "\t INT: " << intel << "\t WIS: " << wis
            << "\t CHAR: " << cha << endl;
    cout << "Total Damage: " << totalDamage << endl;
    cout << "Total Attack: " << totalAttack << endl;
    cout << "Total Armor: " << totalArmor << endl;
}

void BasicCharacter::wieldEquipment(Item * e) {
	wornInventory->addItem(*e);
}

void BasicCharacter::unwieldEquipment(Item * e) {
    wornInventory->removeItem(*e);
}

BasicCharacter::~BasicCharacter() {
    delete wornInventory;
    delete backpack;
}

void BasicCharacter::update(){

	cout << "Calling update() from BasicCharacter class Observer using the Observer Pattern!" << endl << endl;

	wornInventory->calculateContainerStats();
	wornInventory->displayContainerEquips();
}

ItemContainer * BasicCharacter::getBackPack() const{
	return backpack;
}

ItemContainer * BasicCharacter::getWornInventory() const{
	return wornInventory;
}