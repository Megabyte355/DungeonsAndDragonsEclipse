/*
 * CharacterItemManager.h
 *
 *  Created on: Nov 23, 2013
 *      Author: Kevin
 */

#ifndef CHARACTERITEMMANAGER_H_
#define CHARACTERITEMMANAGER_H_

#include "ItemContainer.h"
#include "Item.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Bracers.h"
#include "Ring.h"
#include "Belt.h"
#include "Boots.h"
#include "Weapon.h"

using namespace std;

class CharacterItemManager
{
    private:

        /*
         * Attributed used to simulates Equipment slots
         * Three layers:
         * 1- Pointer to attribute
         * 2- Attribute itself (pointer to the item)
         * 3- Item itself (actual instance)
         */

        Helmet * equippedHelmet;
        Armor * equippedArmor;
        Shield * equippedShield;
        Bracers * equippedBracers;
        Ring * equippedRing;
        Belt * equippedBelt;
        Boots * equippedBoots;
        Weapon * equippedWeapon;

        map<characterStats, int> inventoryStats;

        ItemContainer bag;

		void appendStatsInMap(map<characterStats, int> localMap, map<characterStats, int> &localContainer);

    public:

        CharacterItemManager();
        virtual ~CharacterItemManager();

        bool isItemInBag(Item * e);
        Equipment ** isItemEquipped(Equipment * e);
        Equipment ** getEquipmentSlot(Equipment * e) ;

        void equipItem(Equipment * e);
        void unequipItem(Equipment * e);

        void addToBag(Item * e);
        void removeFromBag(Item * e);

        map<characterStats, int> getInventoryStats();


        void calculateInventoryStats();
        string displayInventoryStats();

        ItemContainer getBag() {return bag;}

        Armor * getArmor() {return equippedArmor;}
        Belt * getBelt() {return equippedBelt;}
        Boots * getBoots() {return equippedBoots;}
        Bracers * getBracers(){return equippedBracers;}
        Helmet * getHelmet() {return equippedHelmet;}
        Ring * getRing() {return equippedRing;}
        Shield * getShield() {return equippedShield;}
        Weapon * getWeapon() {return equippedWeapon;}
};

#endif /* CHARACTERITEMMANAGER_H_ */
