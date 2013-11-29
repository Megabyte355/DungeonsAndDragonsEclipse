/* 
 * File:   Character.cpp
 * Author: Tiffany Ip 9341943
 * Created on October 17, 2013, 3:03 PM
 */
#include "Character.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

/*SET FUNCTIONS*/
void Character::setName(std::string name){
    cout << "Setting name of character to " << name << "." << endl;
    charName = name;
}
void Character::setLevel(int startLvl){
    cout << "Setting level of character to " << startLvl << "." << endl;
    level = startLvl;
}
void Character::setType(std::string ct){
    charType = ct;
}

void Character::setAC(){ 
    armorClass = 10 + getAbilityModifier(getDex()); 
}

void Character::setStr(int strScore){
    str = strScore;
}
void Character::setDex(int dexScore){
    dex = dexScore;
}
void Character::setCon(int conScore){
    con = conScore;
}
void Character::setInt(int intScore){
    intel = intScore;
}
void Character::setWis(int wisScore){
    wis = wisScore;
}
void Character::setCha(int chaScore){
    cha = chaScore;
}
void Character::setStrMod(int strScore){
    strMod = getAbilityModifier((double)strScore);
}
void Character::setDexMod(int dexScore){
    dexMod = getAbilityModifier((double)dexScore);
}
void Character::setConMod(int conScore){
    conMod = getAbilityModifier((double)conScore);
}
void Character::setIntMod(int intScore){
    intMod = getAbilityModifier((double)intScore);
}
void Character::setWisMod(int wisScore){
    wisMod = getAbilityModifier((double)wisScore);
}
void Character::setChaMod(int chaScore){
    chaMod = getAbilityModifier((double)chaScore);
}


void Character::setAttackBonuses(){
    setBaseAttackBonus1();
    setBaseAttackBonus2();
    setBaseAttackBonus3();
    setBaseAttackBonus4();
}
void Character::setBaseAttackBonus1(){
    baseAttackBonus1 = level;
}
void Character::setBaseAttackBonus2(){
    int bonus = (level - 5);
    if (bonus < 0){ bonus = 0;}
    baseAttackBonus2 = bonus;
}
void Character::setBaseAttackBonus3(){
    int bonus = (level - 10);
    if (bonus < 0){ bonus = 0; }
    baseAttackBonus3 = bonus;
}
void Character::setBaseAttackBonus4(){
    int bonus = (level - 15);
    if (bonus < 0 ){ bonus = 0; }
    baseAttackBonus4 = bonus;
}

/*GET FUNCTIONS*/
std::string Character::getName() {
    return charName;
}
int Character::getLevel() {
    return level;
}
int Character::getHP() {
    return hitPoints;
}
int Character::getAC() {
    return armorClass;
}
int Character::getSpeed(){
    return speed;
}

int Character::getStr() {
    return str;
}
int Character::getDex() {
    return dex;
}
int Character::getCon() {
    return con;
}
int Character::getInt() {
    return intel;
}
int Character::getWis() {
    return wis;
}
int Character::getCha() {
    return cha;
}
int Character::getStrMod(){
    return strMod;
}
int Character::getDexMod(){
    return dexMod;
}
int Character::getConMod(){
    return conMod;
}
int Character::getIntMod(){
    return intMod;
}
int Character::getWisMod(){
    return wisMod;
}
int Character::getChaMod(){
    return chaMod;
}

int Character::attack1() {
    return rollD20() + getBaseAttackBonus1() + getStrMod(); //TODO add weapon bonus later!!
}
int Character::attack2() {
    return rollD20() + getBaseAttackBonus2() + getStrMod();
}
int Character::attack3() {
    return rollD20() + getBaseAttackBonus3() + getStrMod();
}
int Character::attack4() {
    return rollD20() + getBaseAttackBonus4() + getStrMod();
}

int Character::getBaseAttackBonus1() {
    return baseAttackBonus1;
}
int Character::getBaseAttackBonus2() {
    return baseAttackBonus2;
}
int Character::getBaseAttackBonus3() {
    return baseAttackBonus3;
}
int Character::getBaseAttackBonus4() {
    return baseAttackBonus4;
}
int Character::getHitDie(){
    return 0;     //overriden by subclasses
}

/*CONSTRUCTORS*/
Character::Character(void){
    //empty constructor
}
Character::Character(string name, int level){
    //overriden
}

Character::Character(int level){
    setLevel(level);
    generateAbilityScores();
    chooseAbilityScores();
    setAC(); 
}

/*OTHER FUNCTIONS*/
void Character::generateAbilityScores(){
    int rollNum = 0; //to count how many total rolls were made (max of 6 stat rolls)
    srand(time(NULL)); //makes sure the random is really random according to time, otherwise it generates the same random numbers
    cout << "Generating 6 random ability scores for you..." << endl;
    
    while (rollNum < 6){ //while number of ability score rolls is less than 6, keep rolling
        int sum = 0, min = 7;
        for (int i = 0; i < 4; i++) { //four rolls of D6s for one ability score
            int num = rand() % 6 + 1; 
            if (num < min) min = num; //find the minimum
            sum += num; 
        }
        sum -= min; //removes the smallest die value from the total 
        rolls.push_back(sum); //insert into vector of rolls
        rollNum++;
    }
}

int Character::getAbilityModifier(double score){
    int mod;
    score = score-10.0;
    mod = (int)floor(score/2.0); //formula for getting modifiers
    //cout << "Modifier=" << mod << endl; //DEBUG
    return mod;
}

//returns the highest ability score from the vector of rolls
//      and removes it from the vector so it doesn't get chosen again
int Character::getHighestAbilityScore(){
    int max = 0;
    std::vector<int>::iterator it, maxScore;
    
    maxScore = std::max_element(rolls.begin(),rolls.end());
    max = *maxScore;
    rolls.erase(maxScore);

    return max;
}

bool Character::hasAttack1() {
    if (baseAttackBonus1 > 0) {
        return true;
    }
    return false;
}

bool Character::hasAttack2() {
    if (baseAttackBonus2 > 0) {
        return true;
    }
    return false;
}

bool Character::hasAttack3() {
    if (baseAttackBonus3 > 0) {
        return true;
    }
    return false;
}

bool Character::hasAttack4() {
    if (baseAttackBonus4 > 0) {
        return true;
    }
    return false;
}

int Character::rollD20() {
    srand(time(NULL));
    return (rand() % 20+1);
}

int Character::rollDie(int type){
    srand(time(NULL));
    return (rand()%type+1);
}

int Character::rollDamage(){
    return getStrMod() + 1; //TODO equip.getDamage()
}

void Character::takeDamage(int dmg){
    hitPoints -= dmg;
}

/**UNUSED FUNCTIONS*/
bool verifyRoll(int rollNum, vector<int> rolls){
    //if the rollNum given (index) is not part of the vector, return false
    if ((rollNum>0 || rollNum<7) & (rollNum<=rolls.size())){
        return true;
    }
    else {
        return false;
    }
}

void Character::chooseAbilityScores() {
    int rollNum;
    int score;
    cout << "Now you may choose which of these rolls will go to an ability specified." << endl;
    cout << "Choose the score by the roll number." << endl;
    cout << "Example: Roll #1 = 14, Roll #2 = 13, you want Strength of 14. Type in '1'." << endl << endl;
    for (int i = 0; i < rolls.size(); i++) {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";
    }
    cout << endl << "For Strength (Str):";
    cin >> rollNum;

    while (!verifyRoll(rollNum, rolls)) { //verify the roll # chosen
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1); //get the value at said roll #
    setStr(score); //set the ability score
    cout << "Strength=" << getStr() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1); //erase the value from the vector (so it doesnt get chosen again)
    for (int i = 0; i < rolls.size(); i++) {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";
    }

    cout << endl << "For Dexterity (Dex):";
    cin >> rollNum;
    while (!verifyRoll(rollNum, rolls)) {
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1);
    setDex(score);
    cout << "Dexterity=" << getDex() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1);
    for (int i = 0; i < rolls.size(); i++) {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";

    }

    cout << endl << "For Constitution (Con):";
    cin >> rollNum;
    while (!verifyRoll(rollNum, rolls)) {
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1);
    setCon(score);
    cout << "Constitution=" << getCon() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1);
    for (int i = 0; i < rolls.size(); i++) {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";
    }

    cout << endl << "For Intelligence (Int):";
    cin >> rollNum;
    while (!verifyRoll(rollNum, rolls)) {
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1);
    setInt(score);
    cout << "Intelligence=" << getInt() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1);
    for (int i = 0; i < rolls.size(); i++) {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";
    }

    cout << endl << "For Wisdom (Wis):";
    cin >> rollNum;
    while (!verifyRoll(rollNum, rolls)) {
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1);
    setWis(score);
    cout << "Wisdom=" << getWis() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1);
    for (int i = 0; i < rolls.size(); i++) {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";
    }

    cout << endl << "For Charisma (Cha):";
    cin >> rollNum;
    while (!verifyRoll(rollNum, rolls)) {
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1);
    setCha(score);
    cout << "Charisma=" << getCha() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1);
}


