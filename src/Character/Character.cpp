/*
 * File:   Character.cpp
 * Author: Tiffany Ip 9341943
 * Created on October 17, 2013, 3:03 PM
 */
#include "Character.h"
#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

/*SET FUNCTIONS*/
void Character::setName(std::string name)
{
    cout << "Setting name of character to " << name << "." << endl;
    charName = name;
}
void Character::setStartingLevel(int startLvl)
{
    cout << "Setting level of character to " << startLvl << "." << endl;
    level = startLvl;
}
void Character::setHP()
{
    //empty (overriden by subclasses)
}
void Character::setAC()
{
    armorClass = 10 + getAbilityModifier(getDex());
}
void Character::setStr(int strScore, int strMod)
{
    str = strScore + strMod;
}
void Character::setDex(int dexScore, int dexMod)
{
    dex = dexScore + dexMod;
}
void Character::setCon(int conScore, int conMod)
{
    con = conScore + conMod;
}
void Character::setInt(int intScore, int intMod)
{
    intel = intScore + intMod;
}
void Character::setWis(int wisScore, int wisMod)
{
    wis = wisScore + wisMod;
}
void Character::setCha(int chaScore, int chaMod)
{
    cha = chaScore + chaMod;
}
void Character::setBaseAttack()
{
    baseAttack = getBaseAttackBonus() + getAbilityModifier(getStr());
}
void Character::setDamageBonus()
{
    damageBonus = getAbilityModifier(getStr());
}

/*GET FUNCTIONS*/
std::string Character::getName()
{
    return charName;
}
int Character::getLevel()
{
    return level;
}
int Character::getHP()
{
    return hitPoints;
}
int Character::getAC()
{
    return armorClass;
}
int Character::getStr()
{
    return str;
}
int Character::getDex()
{
    return dex;
}
int Character::getCon()
{
    return con;
}
int Character::getInt()
{
    return intel;
}
int Character::getWis()
{
    return wis;
}
int Character::getCha()
{
    return cha;
}
int Character::getBaseAttack()
{
    return baseAttack;
}
int Character::getDamageBonus()
{
    return damageBonus;
}
int Character::getHitDie()
{
    return 0;     //overriden by subclasses
}
int Character::getBaseAttackBonus()
{
    return 0;     //overriden by subclasses
}

void Character::generateAbilityScores()
{
    int rollNum = 0; //to count how many total rolls were made (max of 6 stat rolls)
    srand(time(NULL)); //makes sure the random is really random according to time, otherwise it generates the same random numbers
    cout << "Generating 6 random ability scores for you..." << endl;
    
    while (rollNum < 6)
    { //while number of ability score rolls is less than 6, keep rolling
        int sum = 0, min = 7;
        for (int i = 0; i < 4; i++)
        { //four rolls of D6s for one ability score
            int num = rand() % 6 + 1;
            if (num < min)
                min = num; //find the minimum
            sum += num;
        }
        sum -= min; //removes the smallest die value from the total
        rolls.push_back(sum); //insert into vector of rolls
        rollNum++;
    }
}

int Character::getAbilityModifier(double score)
{
    int mod;
    score = score - 10.0;
    mod = (int) floor(score / 2.0); //formula for getting modifiers
    //cout << "Modifier=" << mod << endl; //DEBUG
    return mod;
}

bool verifyRoll(unsigned int rollNum, vector<int> rolls)
{
    //if the rollNum given (index) is not part of the vector, return false
    if ((rollNum > 0 || rollNum < 7) & (rollNum <= rolls.size()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Character::chooseAbilityScores()
{
    int rollNum;
    int score;
    cout << "Now you may choose which of these rolls will go to an ability specified." << endl;
    cout << "Choose the score by the roll number." << endl;
    cout << "Example: Roll #1 = 14, Roll #2 = 13, you want Strength of 14. Type in '1'." << endl << endl;
    for (unsigned int i = 0; i < rolls.size(); i++)
    {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";
    }
    cout << endl << "For Strength (Str):";
    cin >> rollNum;

    while (!verifyRoll(rollNum, rolls))
    { //verify the roll # chosen
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1); //get the value at said roll #
    setStr(score, getAbilityModifier(score)); //set the ability score
    cout << "Strength=" << getStr() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1); //erase the value from the vector (so it doesnt get chosen again)
    for (unsigned int i = 0; i < rolls.size(); i++)
    {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";
    }

    cout << endl << "For Dexterity (Dex):";
    cin >> rollNum;
    while (!verifyRoll(rollNum, rolls))
    {
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1);
    setDex(score, getAbilityModifier(score));
    cout << "Dexterity=" << getDex() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1);
    for (unsigned int i = 0; i < rolls.size(); i++)
    {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";

    }

    cout << endl << "For Constitution (Con):";
    cin >> rollNum;
    while (!verifyRoll(rollNum, rolls))
    {
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1);
    setCon(score, getAbilityModifier(score));
    cout << "Constitution=" << getCon() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1);
    for (unsigned int i = 0; i < rolls.size(); i++)
    {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";
    }

    cout << endl << "For Intelligence (Int):";
    cin >> rollNum;
    while (!verifyRoll(rollNum, rolls))
    {
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1);
    setInt(score, getAbilityModifier(score));
    cout << "Intelligence=" << getInt() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1);
    for (unsigned int i = 0; i < rolls.size(); i++)
    {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";
    }

    cout << endl << "For Wisdom (Wis):";
    cin >> rollNum;
    while (!verifyRoll(rollNum, rolls))
    {
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1);
    setWis(score, getAbilityModifier(score));
    cout << "Wisdom=" << getWis() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1);
    for (unsigned int i = 0; i < rolls.size(); i++)
    {
        cout << "Roll #" << i + 1 << "=" << rolls.at(i) << " | ";
    }

    cout << endl << "For Charisma (Cha):";
    cin >> rollNum;
    while (!verifyRoll(rollNum, rolls))
    {
        cout << "The number you entered is not within the bounds. Try again!" << endl;
        cin >> rollNum;
    }
    score = rolls.at(rollNum - 1);
    setCha(score, getAbilityModifier(score));
    cout << "Charisma=" << getCha() << endl << endl;
    rolls.erase(rolls.begin() + rollNum - 1);
}

Character::Character(string charName, int level)
{
    cout << "Creating new character..." << endl;
    setName(charName);
    setStartingLevel(level);
    generateAbilityScores();
    chooseAbilityScores();
    setAC();
}

std::string Character::toFileString()
{
    std::stringstream ss;

    ss << charName << "\n";
    ss << level << "\n";
    ss << hitPoints << "\n";
    ss << armorClass << "\n";

    ss << str << "\n";
    ss << dex << "\n";
    ss << con << "\n";
    ss << intel << "\n";
    ss << wis << "\n";
    ss << cha << "\n";
    ss << baseAttack << "\n";
    ss << damageBonus << "\n";

    ss << helmet.name << "\n";
    ss << ring1.name << "\n";
    ss << ring2.name << "\n";
    ss << weapon.name << "\n";
    ss << shield.name << "\n";
    ss << armor.name << "\n";
    ss << belt.name << "\n";
    ss << boots.name << "\n";

    return ss.str();
}

void Character::fromFileString(std::string data)
{
    std::stringstream ss;
    std::string line;
    ss << data;

    std::getline(ss, line);
    std::stringstream temp;
    temp << line;
    temp >> charName;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> level;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> hitPoints;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> armorClass;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> str;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> dex;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> con;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> intel;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> wis;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> cha;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> baseAttack;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> damageBonus;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> helmet.name;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> ring1.name;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> ring2.name;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> weapon.name;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> shield.name;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> armor.name;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> belt.name;
    temp.str(std::string());

    std::getline(ss, line);
    temp << line;
    temp >> boots.name;
    temp.str(std::string());
}
