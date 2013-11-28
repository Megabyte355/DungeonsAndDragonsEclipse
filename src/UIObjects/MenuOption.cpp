/*
 * MenuOption.cpp
 *
 *  Created on: Nov 28, 2013
 *      Author: Gary
 */

#include "MenuOption.h"

MenuOption::MenuOption(int x, int y, int padding, std::string label) :
        Clickable(x, y), Button(x, y, padding, label)
{
}

MenuOption::MenuOption(int x, int y, int w, int h, std::string label) :
        Clickable(x, y), Button(x, y, w, h, label)
{
}

MenuOption::~MenuOption()
{
}

void MenuOption::draw()
{
    TextRenderer * texts = TextRenderer::getInstance();

    if (hover)
    {
        int iconSize = texts->getCurrentFontSize();
        TextureRenderer::getInstance()->drawTexture("fairy", labelBoundary.x - iconSize * 2, labelBoundary.y, iconSize, iconSize);
    }

    texts->renderTextWithShadow(labelBoundary.x, labelBoundary.y, label);
    texts = nullptr;
}
