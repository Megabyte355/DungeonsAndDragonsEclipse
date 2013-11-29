
#include "Combat.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Combat::Combat(void) {
}

void Combat::combatRound(Character* p, Character* m) {

//    //setup Dice
//    srand(time(NULL));
//
//    //get order
//    int proll = rand() % 20 + p.getAbilityModifier(p.getDex()) + 1;
//    int mroll = rand() % 20 + m.getAbilityModifier(m.getDex()) + 1;
//    int atkroll;
// //   int numPatks = calcNumOfAttacks(p);
//   // int numMatks = calcNumOfAttacks(m);
//
//    //act
//    if (croll > mroll) {
//        //attack
//        if (p.getBaseAttack() > 0) {
//              atkroll = rand() % 20 + 1 + p.getBaseAttack()+p->getAbilityModifier(p.getstr())+p.getEquipment().getWeaponAttack();
//              if(atkroll>m.getAC())
//                  m.setHP(p.getEquipment().getWeaponDamage()+p->getAbilityModifier(p->getStr()));
//           }
//        if (p.getBaseAttack2() > 0) {
//               attacks++;
//           }
//        if (p.getBaseAttack3() > 0) {
//               attacks++;
//           }
//        if (p.getBaseAttack4() > 0) {
//               attacks++;
//           }
//
//        }
//        if (m.getHP <= 0) {
//            p.addCash(m.treasure());
//            ~m.Monster(); //destroy
//            while (m.hasmoreattacks && p.getHP() > 0) {
//                atkroll = rand() % 20 + 1 + m.attackbonus;
//                if (atkroll > p.getAC())
//                    p.setHP(p.getHP() - m.attackDamage());
//            }
//            if (p.getHP <= 0)
//                gameover();
//        } else {
//            //attack
//
//            while (m.hasmoreattacks && p.getHP() > 0) {
//                atkroll = rand() % 20 + 1 + m.attackbonus;
//                if (atkroll > p.getAC())
//                    p.setHP(p.getHP() - m.attackDamage());
//            }
//            if (p.getHP <= 0)
//                gameover();
//            while (p.hasmoreattacks && m.getHP() > 0) {
//                atkroll = rand() % 20 + 1 + p.attackbonus;
//                if (atkroll > m.getAC())
//                    m.setHP(m.getHP() - p.attackDamage());
//            }
//            if (m.getHP <= 0) {
//                p.addCash(m.treasure());
//                ~m.Monster(); //destroy
//            }
//
//            //dmg
//
//        }
//    }
}

int calcNumOfAttacks(Character* c) {
    int attacks;
//
//    if (c.getBaseAttack() > 0) {
//        attacks++;
//    }
//    if (c.getBaseAttack2() > 0) {
//        attacks++;
//    }
//    if (c.getBaseAttack3() > 0) {
//        attacks++;
//    }
//    if (c.getBaseAttack4() > 0) {
//        attacks++;
//    }
    return attacks;

}

Combat::~Combat(void) {
}
