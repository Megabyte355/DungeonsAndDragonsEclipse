/*
 * Textures.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#include "TextureRenderer.h"

TextureRenderer * TextureRenderer::instance;

TextureRenderer::TextureRenderer()
{
    renderer = nullptr;
}

TextureRenderer::~TextureRenderer()
{
    // Note: This class is not the main owner of "renderer".
    for (auto t : textureMap)
    {
        SDL_DestroyTexture(t.second);
        std::cout << "Texture " << t.first.c_str() << " destroyed" << std::endl;
    }
    textureMap.clear();
    renderer = nullptr;
}

TextureRenderer * TextureRenderer::getInstance()
{
    if (instance == nullptr)
    {
        instance = new TextureRenderer();
    }
    return instance;
}

void TextureRenderer::setRenderer(SDL_Renderer * ren)
{
    renderer = ren;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void TextureRenderer::loadAllTextures()
{
    // Load all files here
    textureMap["bizzare_landscape"] = loadTexture("assets/bizzare_landscape.png");
    textureMap["ddlogo"] = loadTexture("assets/ddlogo.png");
    textureMap["background"] = loadTexture("assets/background.png");
    textureMap["floor"] = loadTexture("assets/floor.png");
    textureMap["bricks"] = loadTexture("assets/bricks.png");
    textureMap["start"] = loadTexture("assets/start.png");
    textureMap["stop"] = loadTexture("assets/stop.png");
    textureMap["finish"] = loadTexture("assets/finish.png");
    textureMap["empty"] = loadTexture("assets/empty.png");
    textureMap["dot"] = loadTexture("assets/dot.png");
    textureMap["outer_space"] = loadTexture("assets/outer_space.png");

    // Test
    textureMap["kiwi"] = loadTexture("assets/kiwi.png");
    textureMap["orange"] = loadTexture("assets/orange.png");
}

SDL_Texture* TextureRenderer::getTexture(std::string textureName)
{
    return textureMap[textureName];
}

SDL_Texture* TextureRenderer::loadTexture(const std::string &file)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
    if (texture == nullptr)
    {
        std::cout << "Textures::loadTexture error." << std::endl;
    }
    return texture;
}

void TextureRenderer::drawTexture(std::string textureName, int x, int y)
{
    drawTexture(textureName, x, y, 0, 0);
}

void TextureRenderer::drawTexture(std::string textureName, int x, int y, int w, int h)
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
        std::cout << "Textures::drawTexture error with " << textureName.c_str() << std::endl;
    }
}

void TextureRenderer::drawTexture(std::string textureName, SDL_Rect * pos, SDL_Rect * clip)
{
    SDL_Texture * tex = textureMap[textureName];
    if (renderer != nullptr && pos != nullptr)
    {
        SDL_RenderCopy(renderer, tex, clip, pos);
    }
}

void TextureRenderer::drawTextureClip(std::string textureName, int x, int y, SDL_Rect * clip)
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

void TextureRenderer::drawLine(int x1, int y1, int x2, int y2)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}
