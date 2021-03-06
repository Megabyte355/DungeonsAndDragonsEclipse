/*
 * TestScreen.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef TESTSCREEN_H_
#define TESTSCREEN_H_

#include "GameConfig.h"
#include "Screen.h"
#include "Orange.h"
#include "Kiwi.h"
#include "Game.h"
#include "Button.h"
#include "TextField.h"
#include <vector>

class TestScreen : public virtual Screen
{
private:
    Orange o;
    std::vector<Kiwi*> k;

    std::vector<Button*> buttons;
    std::vector<TextField*> textFields;

public:
    TestScreen(void);
    ~TestScreen(void) override;

    void initialize() override;
    void update(float) override;
    void draw() override;
    void handleEvents(SDL_Event &event) override;
    void reset() override;
};

#endif /* TESTSCREEN_H_ */
