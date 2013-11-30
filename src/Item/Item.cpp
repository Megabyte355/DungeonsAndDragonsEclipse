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

Item::Item(int pvalue, int pweight, string pname, string ptextureName){
	name = pname;
    value = pvalue;
    weight = pweight;
    if(!ptextureName.empty()){
        textureName = ptextureName;
    }
}

Item::Item(int charLevel, bool isRandom, string ptextureName){
    name = "Random Generated Equipment";
    value = 100*(rand() % charLevel +1);
    weight = 10*(rand() % charLevel +1);
    if(!ptextureName.empty()){
        textureName = ptextureName;
    }
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

string Item::getTextureName() {
    return textureName;
}

void Item::setTextureName(string str) {
    this->textureName = str;
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
