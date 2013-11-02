/*
 * TextRenderer.cpp
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#include "TextRenderer.h"

SDL_Renderer * TextRenderer::renderer;

TextRenderer::TextRenderer()
{
    

}

TextRenderer::~TextRenderer()
{

}

SDL_Texture* TextRenderer::renderText(std::string message, std::string fontFile, SDL_Color color, int fontSize)
{
    if (renderer != nullptr)
    {
        //Open the font
        TTF_Font *font = nullptr;
        font = TTF_OpenFont(fontFile.c_str(), fontSize);

        if (font == nullptr)
        {
            throw std::runtime_error("Failed to load font: " + fontFile + TTF_GetError());
        }
        //Render the message to an SDL_Surface, as that's what TTF_RenderText_X returns
        SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);

        //Clean up unneeded stuff
        SDL_FreeSurface(surf);
        TTF_CloseFont(font);

        return texture;
    }
    return nullptr;
}

TTF_Font * TextRenderer::loadFont(const std::string &fontFile)
{
    TTF_Font *font = nullptr;
    font = TTF_OpenFont(fontFile.c_str(), GameConfig::DEFAULT_FONT_SIZE);
    if (font == nullptr)
    {
        throw std::runtime_error("Failed to load font: " + fontFile + TTF_GetError());
    }
    return font;
}
