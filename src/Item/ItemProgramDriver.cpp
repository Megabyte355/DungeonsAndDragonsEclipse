//============================================================================
// Name        : DnDAssignment1.cpp
// Author      : Kevin Silva
// Description : Dungeons and Dragons Assignment 1 - Part 3 (Inventory Manager)
//============================================================================

#include <iostream>
#include <string>
#include <time.h>

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
#include "ChestBuilder.h"
#include "ItemContainerDirector.h"
#include "CharacterItemManager.h"


using namespace std;

int main(){

	srand (time(NULL));

    cout << "Welcome to the Item Generator created by Kevin Silva!" << endl << endl;
	cout << "Let's try creating a few items." << endl << "=======================" << endl << endl;
//
//	//CREATING A BUILDER
//	cout << "CREATING A BUILDER!" << endl << "=======================" << endl << endl;
//	ChestBuilder * chestBuilder = new ChestBuilder(10, 15);
//
//	//CREATING A DIRECTOR
//	cout << "CREATING A DIRECTOR!" << endl << "=======================" << endl << endl;
//	ItemContainerDirector director(chestBuilder);
//	director.construct();
//
//	//GETTING FINAL RESULT (ITEM LIST)
//	cout << "GETTING FINAL RESULT (ITEM LIST)!" << endl << "=======================" << endl << endl;
//	ItemContainer * finalResult = director.getResult();
//
	//DISPLAY TO SHOW IT WORKS
//	finalResult->displayContainerEquips();
//	finalResult->displayContainerStats();



	//STUFF FOR ASSIGNMENT 2


	CharacterItemManager test;


	//Pre-made Beginner Set
	Armor beginnerArmor("Special Armor", 100, 15, "Medium", 4);
	Helmet beginnerHelmet("Cool Helmet", 75, 10, 2);
	Belt beginnerBelt("Barbaric Belt", 150, 10, 5);
	Boots beginnerBoots("Overpowered Boots", 500, 20, 8, 10);
	Ring beginnerRing("Fancy Ring", 80, 5, 2,1,0);
	Shield beginnerShield("Beginner Shield", 120, 35, 4, 3, "Medium");
	Weapon beginnerSword("Beginner Sword", 300, 30, 8, 10, "Sword");
	Weapon beginnerBow("Beginner Sword", 300, 30, 8, 10, "Bow");

	int characterLevel = 1;

	Helmet randomGeneratedHelmet(characterLevel, true);
	Armor randomGeneratedArmor(characterLevel, true);
	Shield randomGeneratedShield(characterLevel, true);
	Bracers randomGeneratedBracers(characterLevel, true);
	Ring randomGeneratedRing(characterLevel, true);
	Belt randomGeneratedBelt(characterLevel, true);
	Boots randomGeneratedBoots(characterLevel, true);
	Weapon randomGeneratedSword(characterLevel, true, "Sword");
	Weapon randomGeneratedBow(characterLevel, true, "Bow");


	test.addToBag(&randomGeneratedHelmet);
	test.addToBag(&randomGeneratedArmor);
	test.addToBag(&randomGeneratedShield);
	test.addToBag(&randomGeneratedBracers);
	test.addToBag(&randomGeneratedRing);
	test.addToBag(&randomGeneratedBelt);
	test.addToBag(&randomGeneratedBoots);
	test.addToBag(&randomGeneratedSword);
	test.addToBag(&randomGeneratedBow);

	//Small test
	test.getBag().displayContainerEquips();

	test.equipItem(&randomGeneratedHelmet);
	test.equipItem(&randomGeneratedBelt);
	
	
	if(test.getBelt() != nullptr)
		test.getBelt()->toString();

	test.calculateInventoryStats();
	cout << test.displayInventoryStats();



	//==============================================================
	//TESTING OBSERVER PATTERN!!
	//==============================================================
//
//	cout << "CREATING AN OBSERVABLE INVENTORY (ItemContainer)!" << endl;
//	ItemContainer char1Inventory();
//
//	cout << endl << "CREATING AN OBSERVER!" << endl;
//	ItemContainerObserver observerPatternTester(&char1Inventory);
//
//	cout << endl << "ADDING OBSERVER TO NOTIFIERS LIST!" << endl;
//	char1Inventory.attach(&observerPatternTester);
//
//	cout << endl << "LET'S ADD SOME EQUIPMENTS TO OUR INVENTORY!!!" << endl << "=================================" << endl;
//
//    //ADD ITEMS
//    cout << endl << "==============================" << endl << "ADDING armor1 OBJECT!" << endl << "=============================="<< endl;
//    char1Inventory.addItem(armor1);
//    cout << endl << "==============================" << endl << "ADDING boots2 OBJECT!" << endl << "=============================="<< endl;
//    char1Inventory.addItem(boots2);
//    cout << endl << "==============================" << endl << "ADDING helmet2 OBJECT!" << endl << "=============================="<< endl;
//    char1Inventory.addItem(helmet2);
//    cout << endl << "==============================" << endl << "ADDING shield1 OBJECT!" << endl << "=============================="<< endl;
//    char1Inventory.addItem(shield1);
//    cout << endl << "==============================" << endl << "ADDING weapon2 OBJECT!" << endl << "=============================="<< endl;
//    char1Inventory.addItem(weapon2);
//    cout << endl << "==============================" << endl << "ADDING ring2 OBJECT!" << endl << "=============================="<< endl;
//    char1Inventory.addItem(ring2);
//
//    //REMOVING ITEMS
//    cout << endl << "==============================" << endl << "REMOVING ring2 OBJECT!" << endl << "=============================="<< endl;
//    char1Inventory.removeItem(ring2);
//
//    cout << endl << endl << "==============================" << endl << "END OF ITEM ADDITION" << endl << "==============================" << endl << endl;
//
//    cout << "PROGRAM EXECUTION END!" << endl << "Goodbye." ;


	return 0;

}
