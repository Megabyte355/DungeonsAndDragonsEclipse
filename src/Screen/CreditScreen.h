/*
 * CreditScreen.h
 *
 *  Created on: Nov 29, 2013
 *      Author: Tim
 */

#ifndef CREDITSCREEN_H_
#define CREDITSCREEN_H_

#include "Screen.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "GameConfig.h"
#include "MenuOption.h"
#include "ScreenManager.h"
#include <vector>

class CreditScreen: public virtual Screen
{
    public:
		CreditScreen();
        virtual ~CreditScreen();

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

#endif /* CREDITSCREEN_H_ */
