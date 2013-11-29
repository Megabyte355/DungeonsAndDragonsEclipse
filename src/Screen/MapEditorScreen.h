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
#include <vector>

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
};

#endif /* MAPEDITORSCREEN_H_ */
