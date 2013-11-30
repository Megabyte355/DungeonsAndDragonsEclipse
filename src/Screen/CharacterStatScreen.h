/*
* CharacterStatScreen.h
* Author: TIFFANY
* Created on Nov 29, 2013
*/

#ifndef CHARACTERSTATSCREEN_H_
#define CHARACTERSTATSCREEN_H_

#include "Screen.h"
#include "TextureRenderer.h"
#include "TextRenderer.h"
#include "GameConfig.h"
#include "MenuOption.h"
#include "ScreenManager.h"
#include "PersistentData.h"
#include "Fighter.h"
#include <sstream>
#include "SDL.h"
#include <iostream>
#include <vector>

class CharacterStatScreen : public virtual Screen
{

        public:
        CharacterStatScreen();
        virtual ~CharacterStatScreen();

        void initialize() override;
        void reset() override;
        void update(float) override;
        void draw() override;
        void handleEvents(SDL_Event &event) override;

        // Character editor choices
        std::vector<MenuOption*> menuOptions;

    private:
        //Textfields
        TextField * nameTextField;
        Fighter * newFighter;
        Character* currentChar;
        int levelSlot;
        int hpSlot;
        int acSlot;
        int strSlot;
        int dexSlot;
        int conSlot;
        int intSlot;
        int wisSlot;
        int chaSlot;
        int attackBonusSlot1;
        int attackBonusSlot2;
        int attackBonusSlot3;
        int attackBonusSlot4;

        // Screen changers
        void returnToMenu();

};

#endif
