/*
 * TextRenderer.cpp
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#include "TextRenderer.h"

SDL_Renderer * TextRenderer::renderer;
std::map<std::string, std::string> TextRenderer::fontMap;

SDL_Color TextRenderer::black = {0, 0, 0};
SDL_Color TextRenderer::white = {255, 255, 255};
SDL_Color TextRenderer::red = {255, 0, 0};
SDL_Color TextRenderer::green = {0, 255, 0};
SDL_Color TextRenderer::blue = {0, 0, 255};

TextRenderer::TextRenderer()
{
}

TextRenderer::~TextRenderer()
{
}

void TextRenderer::setRenderer(SDL_Renderer * ren)
{
    renderer = ren;
}

void TextRenderer::loadFontPaths()
{
    fontMap["starcraft_font"] = "assets/starcraft_font.ttf";

    fontMap["arial"] = "assets/arial.ttf";
    fontMap["arial_bold"] = "assets/arialbd.ttf";
    fontMap["arial_bold_italic"] = "assets/arialbi.ttf";
    fontMap["arial_italic"] = "assets/ariali.ttf";
    fontMap["arial_narrow"] = "assets/ARIALN.TTF";
    fontMap["arial_narrow_bold"] = "assets/ARIALNB.TTF";
    fontMap["arial_narrow_bold_italic"] = "assets/ARIALNBI.TTF";
    fontMap["arial_narrow_italic"] = "assets/ARIALNI.TTF";
    fontMap["arial_black"] = "assets/ariblk.ttf";

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
        //Open the font with custom fontSize
        TTF_Font *font = nullptr;
        font = TTF_OpenFont(fontMap[fontName].c_str(), fontSize);

        if (font == nullptr)
        {
            throw std::runtime_error("Failed to load font: " + fontName + TTF_GetError());
        }
        //Render the message to an SDL_Surface, as that's what TTF_RenderText_X returns
        SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);

        //Clean up unneeded stuff
        SDL_FreeSurface(surf);
        TTF_CloseFont(font);

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
    font = TTF_OpenFont(fontFile.c_str(), GameConfig::DEFAULT_FONT_SIZE);
    if (font == nullptr)
    {
        throw std::runtime_error("Failed to load font: " + fontFile + TTF_GetError());
    }
    return font;
}
