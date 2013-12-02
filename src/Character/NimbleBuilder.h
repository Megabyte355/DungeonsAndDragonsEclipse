/* 
 * File:   NimbleBuilder.h
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 1:49 PM
 */

#ifndef NIMBLEBUILDER_H
#define	NIMBLEBUILDER_H
#include "CharacterBuilder.h"

class NimbleBuilder : public CharacterBuilder{
     public: 
        virtual void setType();
        virtual void buildType();
        virtual void buildStats();
        virtual void buildItems();
};


#endif	/* NIMBLEBUILDER_H */

