/* 
 * File:   Moblin.h
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 2:01 PM
 */

#ifndef MOBLIN_H
#define	MOBLIN_H
#include "Character.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Moblin : public virtual Character {
    static const int hitDie = 8;

public:
    Moblin();
    Moblin(int level);
    ~Moblin();

    //setters
    void setHP();
    void setSpeed();

    //getters
    int getHitDie();
    int getAC();
};

#endif	/* MOBLIN_H */

