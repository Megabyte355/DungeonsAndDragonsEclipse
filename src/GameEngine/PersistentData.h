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
        int getMapLoadPremade() const;
        int getMapLoadSlot() const;
        int getMapLoadWidth() const;

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

};

#endif /* PERSISTENTDATA_H_ */
