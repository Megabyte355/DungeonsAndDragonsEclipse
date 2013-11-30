////============================================================================
//// Name        : DnDAssignment1.cpp
//// Author      : Kevin Silva
//// Description : Dungeons and Dragons Assignment 1 - Part 3 (Inventory Manager)
////============================================================================
//
//#include <iostream>
//#include <string>
//#include <time.h>
//
//#include "Armor.h"
//#include "Belt.h"
//#include "Boots.h"
//#include "Ring.h"
//#include "Shield.h"
//#include "Weapon.h"
//#include "Helmet.h"
//#include "ItemContainer.h"
//#include "ItemContainerObserver.h"
//#include "ChestBuilder.h"
//#include "ItemContainerDirector.h"
//#include "CharacterItemManager.h"
//
//
//using namespace std;
//
//int main(){
//
//	srand (time(NULL));
//
//    cout << "Welcome to the Item Generator created by Kevin Silva!" << endl << endl;
//	cout << "Let's try creating a few items." << endl << "=======================" << endl << endl;
////
////	//CREATING A BUILDER
////	cout << "CREATING A BUILDER!" << endl << "=======================" << endl << endl;
////	ChestBuilder * chestBuilder = new ChestBuilder(10, 15);
////
////	//CREATING A DIRECTOR
////	cout << "CREATING A DIRECTOR!" << endl << "=======================" << endl << endl;
////	ItemContainerDirector director(chestBuilder);
////	director.construct();
////
////	//GETTING FINAL RESULT (ITEM LIST)
////	cout << "GETTING FINAL RESULT (ITEM LIST)!" << endl << "=======================" << endl << endl;
////	ItemContainer * finalResult = director.getResult();
////
//	//DISPLAY TO SHOW IT WORKS
////	finalResult->displayContainerEquips();
////	finalResult->displayContainerStats();
//
//
//	CharacterItemManager test;
//
//
//	//CREATING Pre-made Beginner Equipment Set - Stats must be validated!
//	Armor beginnerArmor("Special Armor", 100, 15, "Medium", 4);
//	Helmet beginnerHelmet("Cool Helmet", 75, 10, 2);
//	Belt beginnerBelt("Barbaric Belt", 150, 10, 5);
//	Boots beginnerBoots("Overpowered Boots", 500, 20, 8, 10);
//	Ring beginnerRing("Fancy Ring", 80, 5, 2,1,0);
//	Shield beginnerShield("Beginner Shield", 120, 35, 4, 3, "Medium");
//	Weapon beginnerSword("Beginner Sword", 300, 30, 8, 10, "Sword");
//	Weapon beginnerBow("Beginner Sword", 300, 30, 8, 10, "Bow");
//
//	int characterLevel = 1;
//
//	Helmet genHelmet(characterLevel, true);
//	Armor genArmor(characterLevel, true);
//	Shield genShield(characterLevel, true);
//	Bracers genBracers(characterLevel, true);
//	Ring genRing(characterLevel, true);
//	Belt genBelt(characterLevel, true);
//	Boots genBoots(characterLevel, true);
//	Weapon genSword(characterLevel, true, "Sword");
//	Weapon genBow(characterLevel, true, "Bow");
//
//
//	test.addToBag(&genHelmet);
//	test.addToBag(&genArmor);
//	test.addToBag(&genShield);
//	test.addToBag(&genBracers);
//	test.addToBag(&genRing);
//	test.addToBag(&genBelt);
//	test.addToBag(&genBoots);
//	test.addToBag(&genSword);
//	test.addToBag(&genBow);
//
//	//Small test
//	test.getBag().displayContainerEquips();
//
//	test.equipItem(&genHelmet);
//	test.equipItem(&genBelt);
//	
//	
//	if(test.getBelt() != nullptr)
//		test.getBelt()->toString();
//
//	test.calculateInventoryStats();
//	cout << test.displayInventoryStats();
//
//	return 0;
//
////}
