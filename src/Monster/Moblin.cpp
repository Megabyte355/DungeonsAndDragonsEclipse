/* 
 * File:   Moblin.cpp
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 2:01 PM
 */

#include "Moblin.h"

Moblin::Moblin(void){
    //base stats or nothing
    str = 11;
    dex = 13;
    con = 12;
    intel = 10;
    wis = 9;
    cha = 6;
}

Moblin::Moblin(int level):Character(level){
    
    setStartingLevel(level);
    generateAbilityScores();
    setAC(); 
    this->setHP();
}

void Moblin::setHP(){
    if (getCon() < 0 ){
        int conMod = getAbilityModifier(getCon());
        srand(time(NULL));
        cout << "Constitution Mod is = " << conMod << endl;
    
        for (int i = 0; i < level ;i++) {
                hitPoints += ((rand()% hitDie )+1) + conMod;
                cout << "Hitpoints at level " << (i+1) << " is " << hitPoints << endl;
        }
    }
    else{
        cout << "Constitution Ability Score is not yet set." << endl;
    }
}

void Moblin::setSpeed(){
    speed = 3;
}

int Moblin::getHitDie(){
    return hitDie;
}

int Moblin::getAC(){
    return 15;
}

Moblin::~Moblin()
{
}
