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

    moveSpeed = 0.20;
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

void Orange::MoveUp(bool x)
{
    up = x;
}

void Orange::MoveDown(bool x)
{
    down = x;
}

void Orange::MoveLeft(bool x)
{
    left = x;
}

void Orange::MoveRight(bool x)
{
    right = x;
}

void Orange::Draw()
{
    Textures::DrawTexture("orange", x, y);
}

void Orange::Update()
{

}

