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
    fontMap["starcraft_font"] = "assets/starcraft_font.ttf";

    // Arial fonts
    fontMap["arial"] = "assets/arial.ttf";
    fontMap["arial_bold"] = "assets/arialbd.ttf";
    fontMap["arial_bold_italic"] = "assets/arialbi.ttf";
    fontMap["arial_italic"] = "assets/ariali.ttf";
    fontMap["arial_narrow"] = "assets/ARIALN.TTF";
    fontMap["arial_narrow_bold"] = "assets/ARIALNB.TTF";
    fontMap["arial_narrow_bold_italic"] = "assets/ARIALNBI.TTF";
    fontMap["arial_narrow_italic"] = "assets/ARIALNI.TTF";
    fontMap["arial_black"] = "assets/ariblk.ttf";

    // Calibri fonts
    fontMap["calibri"] = "assets/calibri.ttf";
    fontMap["calibri_bold"] = "assets/calibrib.ttf";
    fontMap["calibri_italic"] = "assets/calibrii.ttf";
    fontMap["calibri_light"] = "assets/calibril.ttf";
    fontMap["calibri_light_italic"] = "assets/calibrili.ttf";
    fontMap["calibri_bold_italic"] = "assets/calibriz.ttf";
}

void TextRenderer::renderText(int x, int y, std::string message, std::string fontName, SDL_Color color, int fontSize)
{
    /*
     * This function is currently very inefficient since it keeps re-reading the font files.
     * A solution will be implemented in the near future.
     */

    if (renderer != nullptr)
    {
        // Open the font with custom font size
        TTF_Font *font = nullptr;
        font = TTF_OpenFont(fontMap[fontName].c_str(), fontSize);
        if (font == nullptr)
        {
            std::cout << "Failed to load font: " << fontName.c_str() << TTF_GetError() << std::endl;
        }

        // Render the message to an SDL_Surface
        SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);

        // Clean up
        SDL_FreeSurface(surf);
        TTF_CloseFont(font);

        // Position and size setup
        SDL_Rect pos;
        pos.x = x;
        pos.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
        SDL_RenderCopy(renderer, texture, NULL, &pos);
    }
}

TTF_Font * TextRenderer::loadPath(const std::string &fontFile)
{
    /*
     * This function will be used as part of the optimized font-loading algorithm later.
     */
    TTF_Font *font = nullptr;
    font = TTF_OpenFont(fontFile.c_str(), DEFAULT_FONT_SIZE);
    if (font == nullptr)
    {
        std::cout << "Failed to load font: " << fontFile.c_str() << TTF_GetError() << std::endl;
    }
    return font;
}
