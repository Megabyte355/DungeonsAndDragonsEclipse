/*
 * TextRenderer.cpp
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#include "TextRenderer.h"

TextRenderer * TextRenderer::instance;
SDL_Color TextRenderer::black;
SDL_Color TextRenderer::white;
SDL_Color TextRenderer::red;
SDL_Color TextRenderer::green;
SDL_Color TextRenderer::blue;

TextRenderer::TextRenderer()
{
    // Initialize preset colors
    black.r = 0;
    white.r = 255;
    red.r = 255;
    green.r = 0;
    blue.r = 0;

    black.g = 0;
    white.g = 255;
    red.g = 0;
    green.g = 255;
    blue.g = 0;

    black.b = 0;
    white.b = 255;
    red.b = 0;
    green.b = 0;
    blue.b = 255;

    renderer = nullptr;
    currentColor = this->white;
    currentFont = "arial";
    currentFontSize = DEFAULT_FONT_SIZE;
}

TextRenderer::~TextRenderer()
{
    renderer = nullptr;
    fontPathMap.clear();
    for (std::pair<std::string, std::map<int, TTF_Font*>> currentFont : fontMap)
    {
        for (std::pair<int, TTF_Font*> pair : currentFont.second)
        {
            TTF_CloseFont(pair.second);
            pair.second = nullptr;
        }
        currentFont.second.clear();
        std::cout << "Font " << currentFont.first << " destroyed" << std::endl;
    }
    fontMap.clear();
}

TextRenderer * TextRenderer::getInstance()
{
    if (instance == nullptr)
    {
        instance = new TextRenderer();
    }
    return instance;
}

void TextRenderer::setRenderer(SDL_Renderer * ren)
{
    renderer = ren;
}

void TextRenderer::setCurrentColor(SDL_Color c)
{
    currentColor = c;
}

void TextRenderer::setShadowColor(SDL_Color c)
{
    shadowColor = c;
}

void TextRenderer::setCurrentFont(std::string fontName)
{
    std::map<std::string, std::string>::iterator it = fontPathMap.find(fontName);
    if (it != fontPathMap.end())
    {
        currentFont = fontName;
    }
}

void TextRenderer::setCurrentFontSize(int size)
{
    currentFontSize = size;
}

void TextRenderer::setSettings(std::string font, int size, SDL_Color color)
{
    setCurrentFont(font);
    setCurrentFontSize(size);
    setCurrentColor(color);
}

void TextRenderer::setSettings(std::string font, int size, SDL_Color color, SDL_Color shadow)
{
    setCurrentFont(font);
    setCurrentFontSize(size);
    setCurrentColor(color);
    setShadowColor(shadow);
}


void TextRenderer::loadFontPaths()
{
    // Font from our favorite games
    fontPathMap["starcraft_font"] = "assets/starcraft_font.ttf";
    fontPathMap["triforce"] = "assets/Triforce.ttf";
    fontPathMap["retganon"] = "assets/RetGanon.ttf";

    // Arial fonts
    fontPathMap["arial"] = "assets/arial.ttf";
    fontPathMap["arial_bold"] = "assets/arialbd.ttf";
    fontPathMap["arial_bold_italic"] = "assets/arialbi.ttf";
    fontPathMap["arial_italic"] = "assets/ariali.ttf";
    fontPathMap["arial_narrow"] = "assets/ARIALN.TTF";
    fontPathMap["arial_narrow_bold"] = "assets/ARIALNB.TTF";
    fontPathMap["arial_narrow_bold_italic"] = "assets/ARIALNBI.TTF";
    fontPathMap["arial_narrow_italic"] = "assets/ARIALNI.TTF";
    fontPathMap["arial_black"] = "assets/ariblk.ttf";

    // Calibri fonts
    fontPathMap["calibri"] = "assets/calibri.ttf";
    fontPathMap["calibri_bold"] = "assets/calibrib.ttf";
    fontPathMap["calibri_italic"] = "assets/calibrii.ttf";
    fontPathMap["calibri_light"] = "assets/calibril.ttf";
    fontPathMap["calibri_light_italic"] = "assets/calibrili.ttf";
    fontPathMap["calibri_bold_italic"] = "assets/calibriz.ttf";
}

void TextRenderer::renderText(int x, int y, std::string message, std::string fontName, SDL_Color color, int fontSize)
{
    if (renderer != nullptr && fontPathMap.find(fontName) != fontPathMap.end())
    {
        TTF_Font * font = getFont(fontName, fontSize);
        if (font == nullptr)
        {
            // TODO throw an exception instead
            std::cout << "Failed to load font: " << fontName.c_str() << TTF_GetError() << std::endl;
        }

        // Render the message to an SDL_Surface
        SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);

        // Position and size setup
        SDL_Rect pos;
        pos.x = x;
        pos.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
        SDL_RenderCopy(renderer, texture, NULL, &pos);

        // Clean up
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(texture);
        font = nullptr;
        surf = nullptr;
        texture = nullptr;
    }
    else
    {
        std::cout << "TextRenderer::renderText - renderer or fontMap error" << std::endl;
    }
}

void TextRenderer::renderText(int x, int y, std::string message)
{
    renderText(x, y, message, currentFont, currentColor, currentFontSize);
}


void TextRenderer::renderTextWithShadow(int x, int y, std::string message)
{
    renderText(x + 2, y + 2, message, currentFont, shadowColor, currentFontSize);
    renderText(x, y, message, currentFont, currentColor, currentFontSize);
}


SDL_Rect TextRenderer::queryTextSize(int x, int y, std::string message)
{
    SDL_Rect pos;
    if (renderer != nullptr && fontPathMap.find(currentFont) != fontPathMap.end())
    {
        TTF_Font * font = getFont(currentFont, currentFontSize);
        if (font == nullptr)
        {
            std::cout << "Failed to load font: " << currentFont.c_str() << TTF_GetError() << std::endl;
        }

        // Render the message to an SDL_Surface
        SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), currentColor);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);

        // Position and size setup
        pos.x = x;
        pos.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);

        // Clean up
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(texture);
    }
    else
    {
        std::cout << "TextRenderer::queryTextTexture - renderer or fontMap error" << std::endl;
    }
    return pos;

}

TTF_Font * TextRenderer::loadPath(const std::string &fontFile, int fontSize)
{
    TTF_Font *font = nullptr;
    font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr)
    {
        std::cout << "Failed to load font: " << fontFile.c_str() << TTF_GetError() << std::endl;
    }
    return font;
}

SDL_Color TextRenderer::getCurrentColor() const
{
    return currentColor;
}

const std::string& TextRenderer::getCurrentFont() const
{
    return currentFont;
}

int TextRenderer::getCurrentFontSize() const
{
    return currentFontSize;
}

SDL_Color TextRenderer::getShadowColor() const
{
    return shadowColor;
}

TTF_Font * TextRenderer::getFont(std::string font, int size)
{
    if (fontMap.find(font) == fontMap.end())
    {
        std::map<int, TTF_Font*> * fontSizeMap = new std::map<int, TTF_Font*>();
        fontMap[font] = *fontSizeMap;
        fontMap[font][size] = loadPath(fontPathMap[font].c_str(), size);
    }
    else if (fontMap[font].find(size) == fontMap[font].end())
    {
        fontMap[font][size] = loadPath(fontPathMap[font].c_str(), size);
    }
    return fontMap[font][size];
}
