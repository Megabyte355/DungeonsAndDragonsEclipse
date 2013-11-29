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
        
//	void notifyAll(); //overriding
	void printChar();
        
        ~Fighter();
};
#endif	/* FIGHTER_H */

