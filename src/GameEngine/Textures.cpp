/*
 * Textures.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "Textures.h"

SDL_Renderer * Textures::renderer;

// Texture test
std::map<std::string, SDL_Texture*> Textures::textureMap;
SDL_Texture * Textures::orange;
SDL_Texture * Textures::kiwi;
SDL_Texture * Textures::background;
SDL_Texture * Textures::floor;

Textures::Textures(void)
{
}

Textures::~Textures(void)
{
    // TO DO: Free all textures in textureMap
}

void Textures::setRenderer(SDL_Renderer * ren)
{
    renderer = ren;
}
void Textures::loadAllTextures()
{
    // Load all files here
    orange = LoadTexture("assets/orange.png");
    kiwi = LoadTexture("assets/kiwi.png");
    textureMap["orange"] = orange;
    textureMap["kiwi"] = kiwi;

    // Test
    background = LoadTexture("assets/background.png");
    floor = LoadTexture("assets/floor.png");


}

SDL_Texture* Textures::GetTexture(std::string textureName)
{
    return textureMap[textureName];
}

SDL_Texture* Textures::LoadTexture(const std::string &file)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
    if (texture == nullptr)
        Util::logSDLError(std::cout, "LoadTexture");
    return texture;
}

SDL_Texture* Textures::RenderText(std::string message, std::string fontFile, SDL_Color color, int fontSize)
{
    if (renderer != nullptr)
    {
        //Open the font
        TTF_Font *font = nullptr;
        font = TTF_OpenFont(fontFile.c_str(), fontSize);
        if (font == nullptr)
            throw std::runtime_error("Failed to load font: " + fontFile + TTF_GetError());

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

void Textures::DrawTexture(std::string textureName, int x, int y, int w, int h)
{
    SDL_Texture * tex = textureMap[textureName];
    if (renderer != nullptr && tex != nullptr)
    {
        SDL_Rect pos;
        pos.x = x;
        pos.y = y;

        if (w == 0 || h == 0)
        {
            SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
        }
        else
        {
            pos.w = w;
            pos.h = h;
        }
        SDL_RenderCopy(renderer, tex, NULL, &pos);
    }
    else
    {
        Util::logSDLError(std::cout, std::string("DrawTexture \"").append(textureName).append("\""));
    }
}
