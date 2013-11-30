/*
 * EditorMenuScreen.h
 *
 *  Created on: Nov 28, 2013
 *      Author: Gary
 */

#ifndef EDITORMENUSCREEN_H_
#define EDITORMENUSCREEN_H_

#include <iostream>
#include <SDL.h>
#include <vector>
#include <sstream>
#include "GameConfig.h"
#include "ScreenManager.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "ScreenManager.h"
#include "NumericTextField.h"
#include "PersistentData.h"

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

        // Editor choices
        std::vector<MenuOption*> generalEditorChoices;

        // Map Editor options
        std::vector<MenuOption*> mapEditorChoices;

        // Character Editor options
        std::vector<MenuOption*> characterEditorChoices;

        // Button arrows
        std::vector<Button*> mapIncrementButtons;

    private:
        enum EditorMenuState
        {
            GeneralEditorMenu, CharacterMenu, MapMenu
        };
        EditorMenuState currentState;
        std::vector<MenuOption*> * currentChoices;
        NumericTextField * widthText;
        NumericTextField * heightText;
        int premadeSlot;
        int fileSlot;
        int newMapWidth;
        int newMapHeight;

        void changeMenu(EditorMenuState);

        // Menu state changers
        void characterEditorMenu();
        void mapEditorMenu();
        void generalEditorMenu();

        // Screen changers
        void goToMainMenuScreen();
        void goToMapEditorScreen();
        void goToMapEditorScreenWithPremade();
        void goToMapEditorScreenWithSaved();
        void goToCharacterEditorScreen();
        void goToCharacterEditorScreenWithPremade();
        void goToCharacterEditorScreenWithSaved();

        // Incrementers
        void fileSlotUp();
        void fileSlotDown();
        void premadeSlotUp();
        void premadeSlotDown();

};

#endif /* EDITORMENUSCREEN_H_ */
