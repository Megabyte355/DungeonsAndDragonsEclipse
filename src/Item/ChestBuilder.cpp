/*
 * ChestBuilder.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: Kevin
 */

#include "ChestBuilder.h"

ChestBuilder::ChestBuilder():ItemContainerBuilder() {
    cout << "Generating a new concrete Chest Builder!" << endl;
    possibleItems.push_back("Helmet");
    possibleItems.push_back("Armor");
    possibleItems.push_back("Shield");
    possibleItems.push_back("Bracers");
    possibleItems.push_back("Ring");
    possibleItems.push_back("Belt");
    possibleItems.push_back("Boots");
    possibleItems.push_back("Sword");
    possibleItems.push_back("Bow"); 
}

ChestBuilder::ChestBuilder(int pmapLevel, int pcharacterLevel):ItemContainerBuilder(pmapLevel, pcharacterLevel) {
    cout << "Generating a new concrete Chest Builder!" << endl;
    possibleItems.push_back("Helmet");
    possibleItems.push_back("Armor");
    possibleItems.push_back("Shield");
    possibleItems.push_back("Bracers");
    possibleItems.push_back("Ring");
    possibleItems.push_back("Belt");
    possibleItems.push_back("Boots");
    possibleItems.push_back("Sword");
    possibleItems.push_back("Bow");
}

ChestBuilder::~ChestBuilder() {
}

void ChestBuilder::buildContainer() {

	cout << "Calling buildContainer() from ChestBuilder!" << endl<< endl;

    cout << "Generating contents for a level " << mapLevel << " map!" << endl;

    int randomNumberOfItems = rand() % mapLevel +1;

    cout << "How lucky! You have found " << randomNumberOfItems << " items in this chest!" << endl;

    for(int i=0; i<randomNumberOfItems; i++){
        createRandomItem();
    }
	itemContainer->calculateContainerStats();
}

void ChestBuilder::createRandomItem() {
    int randomItemIndex = rand() % possibleItems.size() + 1;
    Equipment * generatedItem = nullptr;

    switch (randomItemIndex){
        case 1:{            
            generatedItem = new Helmet(characterLevel, true);
            break;
        }
        case 2:{            
            generatedItem = new Armor(characterLevel, true);
            break;
        }
        case 3:{
            generatedItem = new Shield(characterLevel, true);
            break;
        }
		case 4:{
			generatedItem = new Bracers(characterLevel, true);
            break;
        }
        case 5:{            
            generatedItem = new Ring(characterLevel, true);
            break;
        }
        case 6:{            
            generatedItem = new Belt(characterLevel, true);
            break;
        }
        case 7:{            
            generatedItem = new Boots(characterLevel, true);
            break;
        }
        case 8:{            
            generatedItem = new Weapon(characterLevel, true, "Sword");
            break;
        }
        case 9:{            
            generatedItem = new Weapon(characterLevel, true, "Bow");
            break;
        }
    }
    itemContainer->addItem(generatedItem);
    generatedItem = nullptr;
}

