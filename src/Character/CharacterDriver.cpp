/*
 * CharacterDriver.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: Gary
 */

#include "CharacterDriver.h"

CharacterDriver::CharacterDriver()
{
    myFighter = nullptr;
}

CharacterDriver::~CharacterDriver()
{
    myFighter = nullptr;
    delete myFighter;
}

void CharacterDriver::runProgram()
{
    std::string newName; //for input of name
    int wantedLevel; //for input of desired starting level
    int value;

    cout << "Welcome to DnD 3.5's Character creation! The process shall help you create a basic character for the game."
            << endl;
    cout
            << "Unfortunately due to lack of magical items and a thing called time. We will only create a fighter class for you."
            << endl;
    cout << "We'll start with a name, please input a name for your character..." << endl;
    cin >> newName;
    cout << "What level should " << newName << " be? Please input a number from 1 to 20" << endl;
    cin >> wantedLevel;
    while (wantedLevel < 1 || wantedLevel > 20)
    {
        cout << "You've put " << wantedLevel << " which is not within 1 to 20. Please try again..." << endl;
        cin >> wantedLevel;
    }
    cout << endl << newName << " shall start at level " << wantedLevel << "." << endl;
    //Observer ob = Observer(); //create a new observer for the character
    Fighter * player = new Fighter(newName, wantedLevel); //create fighter class!

    // Attach observer
    player->attach(this);

    player->printChar();

    cout << "Now for set tests, input a new value for strength from 0-18" << endl;
    cin >> value;
    while (value < 0 || value > 18)
    {
        cout << "Wrong value... choose from 0 to 18 max" << endl;
        cin >> value;
    }
    player->setStr(value, player->getAbilityModifier(value));

    myFighter = player;
    player = nullptr;
}

void CharacterDriver::update()
{
    cout << "[CharacterDriver::update() function is called via Observer Pattern]" << endl;
}

Fighter * CharacterDriver::returnFighter()
{
    return myFighter;
}
