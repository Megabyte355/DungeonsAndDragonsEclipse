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
#include <vector>

class TestScreen : public Screen
{
private:
    Orange o;
    std::vector<Kiwi*> k;

public:
    TestScreen(void);
    ~TestScreen(void) override;

    void initialize() override;
    void update(float) override;
    void draw() override;
    void handleEvents(SDL_Event * event) override;
};

#endif /* TESTSCREEN_H_ */
