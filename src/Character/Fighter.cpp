/* 
 * File:   Fighter.cpp
 * Author: Tiffany Ip 9341943
 * Created on October 19, 2013, 6:06PM
 */
#include "Fighter.h"

using namespace std;

Fighter::Fighter(void){
    //empty constructor
}

Fighter::Fighter(string name, int level):Character(name, level){
    cout << "Creating new character..." << endl;
    setName(name);
    setLevel(level);
    generateAbilityScores();
    assignRandomScores();

    setStrMod(getStr());
    setDexMod(getDex());
    setConMod(getCon());
    setIntMod(getInt());
    setWisMod(getWis());
    setChaMod(getCha());

    setAC();
    setHP();
    setAttackBonuses();
}

void Fighter::levelUp() {
    int level = this->getLevel();
    this->setLevel(++level);
    this->levelUpHP();
    this->setAttackBonuses();
}
void Fighter::levelUpHP(){
    int conMod = getConMod();
    srand(time(NULL));

    hitPoints += ( (rand()% hitDie ) +1 ) + conMod;
    cout << "Hitpoints have increased due to " << hitPoints << "!" << endl;
}


//overriden setHP
void Fighter::setHP(){
    int conMod = getAbilityModifier(getCon());
    srand(time(NULL));
    //cout << "Constitution Mod is = " << conMod << endl;
    
    for (int i = 0; i < getLevel() ;i++) {
        hitPoints += ((rand()% hitDie )+1) + conMod;
        cout << "Hitpoints at level " << (i+1) << " is " << hitPoints << endl;
    }
    notify();
}

void Fighter::setSpeed(){
    speed = 6;
}

//GET FUNCTIONS
int Fighter::rollDamage(){
    return getStrMod() + 1; //TODO equip.getDamage()
}
int Fighter::getAC() {
    return armorClass;
}
int Fighter::getHitDie(){
    return hitDie;
}
int Fighter::attack1() {
    return rollD20() + getBaseAttackBonus1() + getStrMod(); //TODO add weapon bonus later!!
}
int Fighter::attack2() {
    return rollD20() + getBaseAttackBonus2() + getStrMod();
}
int Fighter::attack3() {
    return rollD20() + getBaseAttackBonus3() + getStrMod();
}
int Fighter::attack4() {
    return rollD20() + getBaseAttackBonus4() + getStrMod();
}


/* This is overriding the Observable class' notifyAll function
	It allows the fighter class to pass itself as an instance to
	notify observers with the proper data */
//void Fighter::notifyAll()
//{
//	vector<Observer> observers = getObservers(); //get the list of observers
//	vector<Observer>::iterator itr; //create an iterator to go through the vector
//	for ( itr = observers.begin(); itr != observers.end(); itr++ )
//	{
//		itr->notify(*this); //notify by passing the instance itself
//	}
//}

void Fighter::printChar(){
	cout << endl<< "This is your new character: " << endl;
    cout << "Name: " << getName() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "HP: " << getHP() << endl;
    cout << "AC: " << getAC() << endl << endl;
    cout << "Speed: " << getSpeed() << endl;
    cout << "Your ability scores: " << endl;
    cout << "Strength " << getStr() << "     & Mod " << getStrMod() << endl;
    cout << "Dexterity " << getDex() << "    & Mod " << getDexMod() << endl;
    cout << "Constitution " << getCon() << " & Mod " << getConMod() << endl;
    cout << "Intelligence " << getInt() << " & Mod " << getIntMod() << endl;
    cout << "Wisdom " << getWis() << "       & Mod " << getWisMod() << endl;
    cout << "Charisma " << getCha() << "     & Mod " << getChaMod() << endl << endl;

	cout << endl;
}

Fighter::~Fighter(){
    //empty
}
