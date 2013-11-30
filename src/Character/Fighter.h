/* 
 * File:   Fighter.h
 * Author: Tiffany Ip 9341943
 *
 * Created on October 19, 2013, 6:05 PM
 */

#ifndef FIGHTER_H
#define	FIGHTER_H
#include "Character.h"
#include "BullyBuilder.h"
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "CharacterItemManager.h"



using namespace std;

class Fighter : public Character 
{
    static const int hitDie = 10;
    
    public:
        Fighter();
        Fighter(string name, int level);
        virtual void setHP();
        virtual void setSpeed();
        
        CharacterItemManager inventory;
        
        int rollDamage();
        int getAC();
        int getHitDie();
        int attack1();
        int attack2();
        int attack3();
        int attack4();
        
        //INVENTORY RELATED STUFF
        void equipItem(Equipment * e);
        void unequipItem(Equipment * e);
        void addSingleItemToBag(Item * e);
        void removeSingleItemFromBag(Item * e);
        void pickupChestContents(ItemContainer * cont);

//	void notifyAll(); //overriding
	void printChar();
        
        ~Fighter();
};
#endif	/* FIGHTER_H */

