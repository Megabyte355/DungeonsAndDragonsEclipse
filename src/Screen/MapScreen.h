/*
 * MapScreen.h
 *
 *  Created on: Nov 9, 2013
 *      Author: Gary
 */

#ifndef MAPSCREEN_H_
#define MAPSCREEN_H_

#include "GameConfig.h"
#include "ScreenManager.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "OptionLabel.h"
#include "FileIO.h"
#include "Map.h"
#include "MapTile.h"
#include "TileOption.h"

class MapScreen : public virtual Screen
{
    public:
        MapScreen();
        ~MapScreen();
        void initialize() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event * event) override;
        void reset() override;

        static void queryMapSize();
        void initData(int,int);

        static Cell::CellType selectedCellType();
        static void selectTileOption(Cell::CellType);
        static void returnToMenu();
        static Cell::CellType selectedTile;

        static void validatePath();
        static bool pathCheckRequest;
    private:
        TextureRenderer * textures;
        TextRenderer * texts;

        static int mapWidth;
        static int mapHeight;

        Map * mapModel;

        bool firstLoop;


        bool displayRed;
        bool displayGreen;
        std::vector<TileOption*> tileOptions;
        std::vector<OptionLabel*> optionLabels;
        std::vector<MapTile*> mapTiles;

        std::vector<CellLocation> validPath;

};

#endif /* MAPSCREEN_H_ */