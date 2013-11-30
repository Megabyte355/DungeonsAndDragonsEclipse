/*
 * MapEditorScreen.h
 *
 *  Created on: Nov 28, 2013
 *      Author: Gary
 */

#ifndef MAPEDITORSCREEN_H_
#define MAPEDITORSCREEN_H_

#include "Screen.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "GameConfig.h"
#include "MenuOption.h"
#include "ScreenManager.h"

class MapEditorScreen: public virtual Screen
{
    public:
        MapEditorScreen();
        virtual ~MapEditorScreen();

        void initialize() override;
        void reset() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event &event) override;


    private:

        // Number of cells in the current map
        int mapWidth;
        int mapHeight;

        // Which cell to display on top left
        int displayX;
        int displayY;

        // Cells to display on the screen at once
        int displayWidth;
        int displayHeight;

        // Size of tiles
        int mapTileWidth;
        int mapTileHeight;

};

#endif /* MAPEDITORSCREEN_H_ */
