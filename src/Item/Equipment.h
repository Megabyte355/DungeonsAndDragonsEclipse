#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

#include "Item.h"
#include <map>
#include <vector>
#include <sstream>

using namespace std;

enum characterStats{STRENGTH, CONSTITUTION, DEXTERITY, INTELLIGENCE, WISDOM, CHARISMA, ARMOR, ATTACK, DAMAGE};
string getStatsEnumString( int enumVal );


typedef map<characterStats, int> StatPair;

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
        virtual ~Equipment();

		virtual void enchantEquipment();
        void insertStatistic(characterStats stat, int value);
		virtual string toString() override;
        bool virtual isEqual(Equipment * e);
        bool compareEquipmentStats(const StatPair& l, const StatPair& r);

        //Getters
        int getEnchantLevel();
        characterStats getEnchantType();
        StatPair getEquipmentStats();
        string getName();
		virtual string getClassName() =0;

};

#endif /* EQUIPMENT_H_ */
