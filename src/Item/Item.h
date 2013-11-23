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

using namespace std;

class Item
{
    protected:

		string name;
        int value;
        int weight;

    public:
        Item();
        Item(int v, int w, string n);
        virtual ~Item();

		virtual string toString();

		string getName();
		void setName(string pname);
        int getValue();
        void setValue(int value);
        int getWeight();
        void setWeight(int weight);

        bool virtual isEqual(Item it);

};

#endif /* ITEM_H_ */
