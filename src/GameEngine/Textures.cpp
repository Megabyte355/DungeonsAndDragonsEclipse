/*
 * Textures.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "Textures.h"

SDL_Renderer * Textures::renderer;
std::map<std::string, SDL_Texture*> Textures::textureMap;

Textures::Textures()
{
}

Textures::~Textures()
{
    // TO DO: Free all textures in textureMap
}

void Textures::destroy()
{
    for (auto t : textureMap)
    {
        SDL_DestroyTexture(t.second);
        std::cout << "Texture " << t.first << " destroyed" << std::endl;
    }
}

void Textures::setRenderer(SDL_Renderer * ren)
{
    renderer = ren;
}
void Textures::loadAllTextures()
{
    // Load all files here
    textureMap["orange"] = loadTexture("assets/orange.png");
    textureMap["kiwi"] = loadTexture("assets/kiwi.png");

    // Test
    textureMap["background"] = loadTexture("assets/background.png");
    textureMap["floor"] = loadTexture("assets/floor.png");

}

SDL_Texture* Textures::getTexture(std::string textureName)
{
    return textureMap[textureName];
}

SDL_Texture* Textures::loadTexture(const std::string &file)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
    if (texture == nullptr)
    {
        Util::logSDLError(std::cout, "LoadTexture");
    }
    return texture;
}

void Textures::drawTexture(std::string textureName, int x, int y)
{
    drawTexture(textureName, x, y, 0, 0);
}

void Textures::drawTexture(std::string textureName, int x, int y, int w, int h)
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

void Textures::drawTextureClip(std::string textureName, int x, int y, SDL_Rect * clip)
{
    SDL_Texture * tex = textureMap[textureName];
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    if (clip != nullptr)
    {
        pos.y = clip->w;
        pos.h = clip->h;
    }
    else
    {
        SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    }
    SDL_RenderCopy(renderer, tex, clip, &pos);
}
