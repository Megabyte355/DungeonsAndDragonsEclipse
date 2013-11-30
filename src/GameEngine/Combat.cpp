#include "Combat.h"
#include "Character.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
Combat::Combat(void)
{
}

Combat::~Combat(void)
{
}

void Combat::combatRound(Character* p, Character* m)
{

    bool combatDone = false;
    int pRoll;
    int mRoll;

    while (!combatDone)
    {

        pRoll = p->rollD20() + p->getDexMod();
        cout << "Player rolled" << pRoll << endl;
        mRoll = m->rollD20() + m->getDexMod();
        cout << "Monster rolled" << mRoll << endl;

        if (mRoll != pRoll)
            combatDone = true;

        if (pRoll > mRoll)
        { //player goes first
            //player attacks
            cout << "Player goes first." << endl;
            combatAction(p, m);

            if (m->getHP() > 0)
            {      //monster attacks if still alive
                combatAction(m, p);
                cout << "Monster's turn" << endl;
            }
        }
        else if (pRoll < mRoll)
        {      //monster goes first
            cout << "Monster won initiative." << endl;
            //monster attacks
            combatAction(m, p);
            if (p->getHP() > 0)
            {      //player attacks if still alive
                combatAction(p, m);
                cout << "Player's turn" << endl;
            }
        }
    }
}

void Combat::combatAction(Character* attacker, Character* defender)
{

    if (attacker->hasAttack1())
    {      //player attacks
        cout << "attacker strikes with the first attack...";
        if (attacker->attack1() >= defender->getAC())
        {
            defender->takeDamage(attacker->rollDamage());
            cout << "it hits";
        }
        else
            cout << "a miss!";
        if (attacker->hasAttack2())
        {
            cout << "attackers second attack..";
            if (attacker->attack1() >= defender->getAC())
                defender->takeDamage(attacker->rollDamage());

            if (attacker->hasAttack3())
            {
                cout << "attackers third attack..";
                if (attacker->attack1() >= defender->getAC())
                    defender->takeDamage(attacker->rollDamage());

                if (attacker->hasAttack4())
                {
                    cout << "attackers fourth attack..";
                    if (attacker->attack1() >= defender->getAC())
                        defender->takeDamage(attacker->rollDamage());
                }

            }
        }
    }

}
