/*
 * EditorMenuScreen.h
 *
 *  Created on: Nov 28, 2013
 *      Author: Gary
 */

#ifndef EDITORMENUSCREEN_H_
#define EDITORMENUSCREEN_H_

#include "GameConfig.h"
#include "ScreenManager.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "ScreenManager.h"
#include <iostream>
#include <SDL.h>
#include <vector>

class EditorMenuScreen: public virtual Screen
{
    public:
        EditorMenuScreen();
        virtual ~EditorMenuScreen();

        void initialize() override;
        void reset() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event &event) override;

        // Editor Menu Options
        std::vector<MenuOption*> editorOptions;

    private:
        void goToCharacterEditorScreen();
        void goToMapEditorScreen();
        void goToMainMenuScreen();
};

#endif /* EDITORMENUSCREEN_H_ */
