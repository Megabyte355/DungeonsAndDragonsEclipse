/*
 * InventoryScreen.h
 *
 *  Created on: Nov 30, 2013
 *      Author: Tim
 */

#ifndef INVENTORYSCREEN_H_
#define INVENTORYSCREEN_H_

#include "Screen.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "GameConfig.h"
#include "MenuOption.h"
#include "ScreenManager.h"
#include <vector>

class InventoryScreen: public virtual Screen
{
    public:
	InventoryScreen();
        virtual ~InventoryScreen();

        void initialize() override;
        void reset() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event &event) override;

        // Menu options
        std::vector<MenuOption*> menuOptions;

    private:
        void goBack();
};



#endif /* INVENTORYSCREEN_H_ */
