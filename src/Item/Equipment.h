#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

#include "Item.h"
#include <map>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

enum characterStats
{
    STRENGTH, CONSTITUTION, DEXTERITY, INTELLIGENCE, WISDOM, CHARISMA, ARMOR, ATTACK, DAMAGE
};
string getStatsEnumString(int enumVal);

class Equipment: public Item
{
    protected:

        int enchantLevel;
        characterStats enchantType;
        map<characterStats, int> equipmentStats;
        vector<characterStats> possibleEnchants;

    public:

        //static map<characterStats, string> stringMapping;
        //string getStatsEnumString(int);

        Equipment();
        Equipment(string pname, int pvalue, int pweight);
        Equipment(int charLevel, bool isRandom);
        virtual ~Equipment();

        virtual void enchantEquipment();
        void insertStatistic(characterStats stat, int value);

        virtual string toString() override;
        bool virtual isEqual(Equipment * e);
        bool compareEquipmentStats(const map<characterStats, int> & l, const map<characterStats, int>& r);

        void generateRandomStats(int i);

        //Getters
        int getEnchantLevel();
        characterStats getEnchantType();
        map<characterStats, int> getEquipmentStats();
        string getName();
        virtual string getClassName() =0;

};

#endif /* EQUIPMENT_H_ */
