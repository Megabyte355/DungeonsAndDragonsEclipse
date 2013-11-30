/*
 * Item.h
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Item
{
    protected:

        string name;
        int value;
        int weight;
        string textureName;

    public:
        Item();
        Item(int pvalue, int pweight, string pname, string ptextureName);
        Item(int charLevel, bool isRandom, string ptextureName);
        virtual ~Item();

        virtual string toString();
        bool virtual isEqual(Item it);

        string getName();
        void setName(string pname);
        int getValue();
        void setValue(int value);
        int getWeight();
        void setWeight(int weight);
        string getTextureName();
        void setTextureName(string str);
};

#endif /* ITEM_H_ */
