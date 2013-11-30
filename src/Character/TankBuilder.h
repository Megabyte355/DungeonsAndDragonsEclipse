/* 
 * File:   TankBuilder.h
 * Author: Tiffany
 *
 * Created on November 23, 2013, 1:45 PM
 */

#ifndef TANKBUILDER_H
#define	TANKBUILDER_H

#include "CharacterBuilder.h"

class TankBuilder : public CharacterBuilder {
        public: 
        virtual void setType();
        virtual void buildType();
        virtual void buildStats();
        virtual void buildItems();
};

#endif	/* TANKBUILDER_H */

