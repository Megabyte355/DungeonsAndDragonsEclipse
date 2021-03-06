/*
 * Kiwi.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "Kiwi.h"

Kiwi::Kiwi(void)
{
    x = 150;
    y = 100;
    moveSpeed = 0.30f;

    // I feel lazy
    right = 1;
    down = 1;

}

Kiwi::Kiwi(int x, int y, float moveSpeed)
{
    this->x = x;
    this-> y = y;
    this-> moveSpeed = moveSpeed;

    // I feel lazy
    right = 1;
    down = 1;
}

Kiwi::~Kiwi(void)
{
}


void Kiwi::draw()
{
    TextureRenderer::getInstance()->drawTexture("kiwi", x, y, 150, 150);
}

void Kiwi::update(float gameTime)
{
    // ===========================================
    //                 Experiment
    // ===========================================

    if (x > 800)
    {
        right = -1;
    }
    if (x < 0)
    {
        right = 1;
    }

    if (y > 600)
    {
        down = -1;
    }
    if (y < 0)
    {
        down = 1;
    }

    x += moveSpeed * gameTime * right;
    y += moveSpeed * gameTime * down;
    // ===========================================

}

