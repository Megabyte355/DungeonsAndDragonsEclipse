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

        Helmet * helmet;
        Armor * armor;
        Shield * shield;
        Bracers * bracers;
        Ring * ring;
        Belt * belt;
        Boots * boots;
        Weapon * weapon;

        map<characterStats, int> inventoryStats;

        ItemContainer bag;

    public:

        CharacterItemManager();
        virtual ~CharacterItemManager();

        bool isItemInBag(Item * e);
        bool isItemEquipped(Equipment * e);
        Equipment ** getEquipmentSlot(Equipment * e) ;

        void equipItem(Equipment * e);
        void unequipItem(Equipment * e);

        void addToBag(Item * e);
        void removeFromBag(Item * e);

        map<characterStats, int> getInventoryStats();

        int getInventorySpecificStat(characterStats);
        int getInventoryStrength();
        int getInventoryConstitution();
        int getInventoryDexterity();
        int getInventoryIntelligence();
        int getInventoryWisdom();
        int getInventoryCharisma();
        int getInventoryArmor();
        int getInventoryAttack();
        int getInventoryDamage();

        void calculateInventoryStats();
        void appendStatsInMap(map<characterStats, int> localMap, map<characterStats, int> &localContainer);
        string displayInventoryStats();

        ItemContainer getBag() {return bag;}

        Armor * getArmor() {return armor;}
        Belt * getBelt() {return belt;}
        Boots * getBoots() {return boots;}
        Bracers * getBracers(){return bracers;}
        Helmet * getHelmet() {return helmet;}
        Ring * getRing() {return ring;}
        Shield * getShield() {return shield;}
        Weapon * getWeapon() {return weapon;}
};

#endif /* CHARACTERITEMMANAGER_H_ */
