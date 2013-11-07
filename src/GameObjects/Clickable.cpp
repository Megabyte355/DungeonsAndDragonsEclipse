/*
 * Clickable.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: Gary
 */

#include "Clickable.h"

Clickable::Clickable()
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    renderer = nullptr;
    texture = nullptr;
    text = nullptr;
    click = false;
}

Clickable::Clickable(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    width = w;
    height = h;
    renderer = nullptr;
    texture = nullptr;
    text = nullptr;
    click = false;
}

Clickable::~Clickable()
{
    // This class is not the main owner of the renderer. It won't be destroyed here.
    observers.clear();
    renderer = nullptr;
}

void Clickable::setRenderers(SDL_Renderer * ren, TextureRenderer * texture, TextRenderer * text)
{
    this->renderer = ren;
    this->texture = texture;
    this->text = text;
}

bool Clickable::isClicked()
{
    bool copy = click;
    click = false;
    return copy;
}
