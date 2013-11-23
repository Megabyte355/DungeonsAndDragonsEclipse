//============================================================================
// Name        : DnDAssignment1.cpp
// Author      : Kevin Silva
// Description : Dungeons and Dragons Assignment 1 - Part 3 (Inventory Manager)
//============================================================================

#include <iostream>
#include <string>

#include "Armor.h"
#include "Belt.h"
#include "Boots.h"
#include "Equipment.h"
#include "Ring.h"
#include "Shield.h"
#include "Weapon.h"
#include "Helmet.h"
#include "ItemContainer.h"
#include "ItemContainerObserver.h"

using namespace std;

int main(){

    cout << "Welcome to the Item Generator created by Kevin Silva!" << endl << endl;
	cout << "Let's try creating a few items." << endl << "=======================" << endl << endl;

	//ARMOR
	Armor armor1;
	Armor armor2("Special Armor", 100, 15, "Medium", 4);
	//HELMET
	Helmet helmet1;
	Helmet helmet2("Cool Helmet", 75, 10, 2);	

	//BELT
	Belt belt1;
	Belt belt2("Barbaric Belt", 150, 10, 5);

	//BOOTS
	Boots boots1;
	Boots boots2("Overpowered Boots", 500, 20, 8, 10);
	
	//RING
	Ring ring1;
	Ring ring2("Fancy Ring", 80, 5, 2,1,0);
	
	//SHIELD
	Shield shield1;
	Shield shield2("Beginner Shield", 120, 35, 4, 3, "Medium");	
	
	//WEAPON
	Weapon weapon1;
	Weapon weapon2("Majestic Sword", 300, 30, 8, 10, "Sword", 1);

	//==============================================================
	//TESTING OBSERVER PATTERN!!
	//==============================================================
	
	cout << "CREATING AN OBSERVABLE INVENTORY (ItemContainer)!" << endl;
	ItemContainer char1Inventory(containerType_t::wornInventory);
		
	cout << endl << "CREATING AN OBSERVER!" << endl;
	ItemContainerObserver observerPatternTester(&char1Inventory);

	cout << endl << "ADDING OBSERVER TO NOTIFIERS LIST!" << endl;
	char1Inventory.attach(&observerPatternTester);

	cout << endl << "LET'S ADD SOME EQUIPMENTS TO OUR INVENTORY!!!" << endl << "=================================" << endl;

    //ADD ITEMS
    cout << endl << "==============================" << endl << "ADDING armor1 OBJECT!" << endl << "=============================="<< endl;
    char1Inventory.addItem(armor1);
    cout << endl << "==============================" << endl << "ADDING boots2 OBJECT!" << endl << "=============================="<< endl;
    char1Inventory.addItem(boots2);
    cout << endl << "==============================" << endl << "ADDING helmet2 OBJECT!" << endl << "=============================="<< endl;
    char1Inventory.addItem(helmet2);
    cout << endl << "==============================" << endl << "ADDING shield1 OBJECT!" << endl << "=============================="<< endl;
    char1Inventory.addItem(shield1);
    cout << endl << "==============================" << endl << "ADDING weapon2 OBJECT!" << endl << "=============================="<< endl;
    char1Inventory.addItem(weapon2);
    cout << endl << "==============================" << endl << "ADDING ring2 OBJECT!" << endl << "=============================="<< endl;
    char1Inventory.addItem(ring2);

    //REMOVING ITEMS
    cout << endl << "==============================" << endl << "REMOVING ring2 OBJECT!" << endl << "=============================="<< endl;
    char1Inventory.removeItem(ring2);

    cout << endl << endl << "==============================" << endl << "END OF ITEM ADDITION" << endl << "==============================" << endl << endl;

    cout << "PROGRAM EXECUTION END!" << endl << "Goodbye." ;


	return 0;

}
