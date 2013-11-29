/* 
 * File:   MoblinBuilder.h
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 3:04 PM
 */

#ifndef MOBLINBUILDER_H
#define	MOBLINBUILDER_H
#include "CharacterBuilder.h"

class MoblinBuilder : public CharacterBuilder {
    
    public:
        virtual void setType();
        virtual void buildType();
        virtual void buildStats();
        virtual void buildItems();
    
};

#endif	/* MOBLINBUILDER_H */

