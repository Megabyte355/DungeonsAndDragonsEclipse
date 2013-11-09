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

void TextRenderer::loadFontPaths()
{
    // Font from one of my favorite games
    fontPathMap["starcraft_font"] = "assets/starcraft_font.ttf";

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
    if (renderer != nullptr && !fontPathMap[fontName].empty())
    {
        if (fontMap.find(fontName) == fontMap.end())
        {
            std::map<int, TTF_Font*> fontSizeMap;
            fontMap[fontName] = fontSizeMap;
            fontMap[fontName][fontSize] = loadPath(fontPathMap[fontName].c_str(), fontSize);
        }
        else if (fontMap[fontName].find(fontSize) == fontMap[fontName].end())
        {
            fontMap[fontName][fontSize] = loadPath(fontPathMap[fontName].c_str(), fontSize);
        }

        // Open the font with custom font size
        TTF_Font *font = nullptr;
        font = fontMap[fontName][fontSize];
        if (font == nullptr)
        {
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
