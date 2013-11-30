/*
* CharacterEditorScreen.h
* Author: TIFFANY
* Created on Nov 29, 2013
*/

#ifndef CHARACTEREDITORSCREEN_H_
#define CHARACTEREDITORSCREEN_H_

#include "Screen.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "GameConfig.h"
#include "MenuOption.h"
#include "ScreenManager.h"
#include "Fighter.h"
#include <sstream>
#include "SDL.h"
#include <iostream>
#include <vector>

class CharacterEditorScreen : public virtual Screen
{

        public:
        CharacterEditorScreen();
        virtual ~CharacterEditorScreen();

        void initialize() override;
        void reset() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event &event) override;

        // Character editor choices
        std::vector<MenuOption*> characterEditorChoices;

        //Menu Buttons
        //std::vector<Button*> menuOptions;
        // Buttons +/-
        std::vector<Button*> levelIncrementButtons;

        // Fighter Type Buttons
        std::vector<Button*> typeButtons;

    private:
        //Textfields
        TextField * nameTextField;
        Fighter * newFighter;
        int levelSlot;
        int strSlot;
        int dexSlot;
        int conSlot;
        int intSlot;
        int wisSlot;
        int chaSlot;

        // Screen changers
        void returnToMenu();
        void gotoSaveCharacterScreen();

        //Incrementers
        void levelUp();
        void levelDown();

        //Ability Score Creation
        void sortForBully();
        void sortForNimble();
        void sortForTank();
        void reroll();

};

#endif
