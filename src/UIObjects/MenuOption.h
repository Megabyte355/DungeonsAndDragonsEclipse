/*
 * MenuOption.h
 *
 *  Created on: Nov 28, 2013
 *      Author: Gary
 */

#ifndef MENUOPTION_H_
#define MENUOPTION_H_

#include "Button.h"
#include "TextRenderer.h"
#include <SDL.h>
#include <string>
#include <functional>

class MenuOption: public Button
{
    public:
        MenuOption(int x, int y, int padding, std::string label);
        MenuOption(int x, int y, int w, int h, std::string label);
        virtual ~MenuOption();

        void draw() override;

};

#endif /* MENUOPTION_H_ */
