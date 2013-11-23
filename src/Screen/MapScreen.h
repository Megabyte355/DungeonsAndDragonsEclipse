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
#include "Button.h"
#include "FileIO.h"
#include "Map.h"
#include "MapTile.h"
#include "TileOption.h"
#include <functional>

class MapScreen : public virtual Screen
{
    public:
        MapScreen();
        ~MapScreen();
        void initialize() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event &event) override;
        void reset() override;

        void initData(int,int);

        Cell::CellType selectedCellType();
        void selectTileOption(Cell::CellType);
        void returnToMenu();
        void validatePath();
        bool pathCheckRequest;
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
        std::vector<Button*> optionLabels;
        std::vector<MapTile*> mapTiles;
        std::vector<CellLocation> validPath;
        Cell::CellType selectedTile;
};

#endif /* MAPSCREEN_H_ */
