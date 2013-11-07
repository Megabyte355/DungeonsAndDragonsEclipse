/*
 * Orange.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "Orange.h"

Orange::Orange(void)
{
    x = 300;
    y = 300;

    up = false;
    down = false;
    left = false;
    right = false;

    moveSpeed = 0.20f;
}

Orange::~Orange(void)
{
}

void Orange::Move(float gameTime)
{
    if (up)
    {
        y -= moveSpeed * gameTime;
    }
    if (down)
    {
        y += moveSpeed * gameTime;
    }
    if (left)
    {
        x -= moveSpeed * gameTime;
    }
    if (right)
    {
        x += moveSpeed * gameTime;
    }
}

void Orange::moveUp(bool x)
{
    up = x;
}

void Orange::moveDown(bool x)
{
    down = x;
}

void Orange::moveLeft(bool x)
{
    left = x;
}

void Orange::moveRight(bool x)
{
    right = x;
}

void Orange::draw()
{
    TextureRenderer::getInstance()->drawTexture("orange", x, y);
}

void Orange::Update()
{

}

