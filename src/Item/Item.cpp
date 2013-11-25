/*
 * Item.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Kevin
 */

#include "Item.h"

Item::Item() {
	name = "Generic Item";
	value = 0;
	weight = 0;
}

Item::Item(int v, int w, string pname){
	name = pname;
    value = v;
    weight = w;
}

Item::Item(int charLevel, bool isRandom){
    value = 100*(rand() % charLevel +1);
    weight = 10*(rand() % charLevel +1);
}

Item::~Item() {
}

//Generated getters/setters.
string Item::getName(){
	return name;
}
void Item::setName(string pname){
	name = pname;
}

int Item::getValue()
{
    return value;
}

void Item::setValue(int value)
{
    this->value = value;
}

int Item::getWeight()
{
    return weight;
}

void Item::setWeight(int weight)
{
    this->weight = weight;
}

bool Item::isEqual(Item it) {
    return (value == it.value)&&(weight == it.weight);
}

string Item::toString(){

	stringstream ss;

	ss << name << endl;
	ss << "Weight: " << weight << endl;
	ss << "Value: " << value << endl;

	return ss.str();
}
