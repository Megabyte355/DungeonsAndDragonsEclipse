#ifndef BASICCHARACTER_H_
#define BASICCHARACTER_H_

#include <iostream>
#include "ItemContainer.h"
#include "Equipment.h"
#include "Observer.h"
#include <string>

using namespace std;

class BasicCharacter : public Observer
{
    public:
        BasicCharacter();
        BasicCharacter(string name, int str, int con, int dex, int intel, int wis, int cha, 
			int totalArmor, int totalAttack, int totalDamage);
        virtual ~BasicCharacter();

        void displayCharacterStats();
        void wieldEquipment(Item * e);
        void unwieldEquipment(Item * e);

        void update() override;

		//Getters
		ItemContainer * getBackPack() const;
		ItemContainer * getWornInventory() const;

    private:

        string charName;
        ItemContainer * backpack;
		ItemContainer * wornInventory;
        int str, con, dex, intel, wis, cha;
        int totalArmor;
        int totalAttack;
        int totalDamage;

};

#endif /* BASICCHARACTER_H_ */
