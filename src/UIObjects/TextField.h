/*
 * TextField.h
 *
 *  Created on: Nov 18, 2013
 *      Author: Gary
 */

#ifndef TEXTFIELD_H_
#define TEXTFIELD_H_

#include "Clickable.h"
#include "GameConfig.h"
#include <string>

class TextField: public virtual Clickable
{
    public:
        TextField(int, int, int, int);
        virtual ~TextField();

        virtual void update() override;
        virtual void handleEvents(SDL_Event &) override;
        virtual void draw() override;

        bool isFocused();
        std::string getText();
        void setText(std::string);

    protected:
        static TextField * focusedTextField;
        static bool currentInputState;
        static bool previousInputState;
        std::string text;
        bool hover;
        bool focus;
};

#endif /* TEXTFIELD_H_ */
