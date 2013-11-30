/*
 * PersistentData.h
 *
 *  Created on: Nov 29, 2013
 *      Author: Gary
 */

#ifndef PERSISTENTDATA_H_
#define PERSISTENTDATA_H_

#include <vector>
#include "Map.h"
#include "Character.h"

class PersistentData
{
    public:
        enum MapLoadMode
        {
            NewMap, Premade, SavedSlot
        };

        virtual ~PersistentData();
        static PersistentData * getInstance();

        void setMapLoadSize(int w, int h);
        void setMapLoadPremade(int);
        void setMapLoadSlot(int);
        Map* getCurrentMap() const;
        int getMapLoadHeight() const;
        void setMapLoadMode(MapLoadMode mapLoadMode);
        MapLoadMode getMapLoadMode();
        int getMapLoadPremade() const;
        int getMapLoadSlot() const;
        int getMapLoadWidth() const;
        void saveMapToCurrentSlot(Map *);
        void loadMapFromCurrentSlot();

        //character
        enum CharLoadMode
        {
            NewChar, PremadeChar, SavedChar
        };

        void setCharLoadPremade(int);
        void setCharLoadSlot(int);
        Character* getCurrentChar() const;
        int getCharLoadPremade() const;
        int getCharLoadSlot() const;
        void setCharLoadMode(CharLoadMode charLoadMode);
        void saveCharToCurrentSlot(Character *);
        void loadCharFromCurrentSlot();

    private:
        PersistentData();
        static PersistentData * instance;

        // Map loading variables
        Map * currentMap;
        MapLoadMode mapLoadMode;
        int mapLoadWidth;
        int mapLoadHeight;
        int mapLoadPremade;
        int mapLoadSlot;
        std::vector<Map*> savedMaps;
        std::vector<Map*> premadeMaps;

        // Character variables
        Character * currentChar;
        CharLoadMode charLoadMode;
        int charLoadPremade;
        int charLoadSlot;
        std::vector<Character*> savedCharacters;
        std::vector<Character*> premadeCharacters;

};

#endif /* PERSISTENTDATA_H_ */
