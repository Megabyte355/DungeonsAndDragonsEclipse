#include "Combat.h"
#include "Character.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Combat::Combat(void) {
}


Combat::~Combat(void) {
}

void Combat::combatRound(Character* p, Character* m) {

  bool combatDone = false;
  int pRoll;
  int mRoll;

  while(!combatDone){

    pRoll = p->rollD20()+p->getDexMod();
    mRoll = m->rollD20()+m->getDexMod();

    if(mRoll!=pRoll)
      combatDone=true;

    if(pRoll>mRoll){//player goes first
      //player attacks
      combatAction(p,m);

      if(m->getHP()>0)//monster attacks if still alive
        combatAction(m,p);
    }
    else if(pRoll<mRoll){//monster goes first
      //monster attacks
      combatAction(m,p);
      if(p->getHP()>0)//player attacks if still alive
        combatAction(p,m);
    }
  }
}

void Combat::combatAction(Character* attacker, Character* defender){

  if(attacker->hasAttack1()){//player attacks
          if(attacker->attack1()>=defender->getAC())
            defender->takeDamage(attacker->rollDamage());

          if(attacker->hasAttack2()){
            if(attacker->attack1()>=defender->getAC())
              defender->takeDamage(attacker->rollDamage());

            if(attacker->hasAttack3()){
              if(attacker->attack1()>=defender->getAC())
                defender->takeDamage(attacker->rollDamage());

              if(attacker->hasAttack4())
                if(attacker->attack1()>=defender->getAC())
                  defender->takeDamage(attacker->rollDamage());

            }
          }
  }

}
