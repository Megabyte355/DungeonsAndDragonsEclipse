/* 
 * File:   BullyBuilder.h
 * Author: Tiffany Ip 9341943
 *
 * Created on November 23, 2013, 11:39 AM
 */

#ifndef BULLYBUILDER_H
#define	BULLYBUILDER_H

#include "CharacterBuilder.h"

class BullyBuilder : public CharacterBuilder {
    
    public: 
        virtual void setType();
        virtual void buildType();
        virtual void buildStats();
        virtual void buildItems();
};

#endif	/* BULLYBUILDER_H */

