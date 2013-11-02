/*
 * Textures.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Gary
 */

#ifndef TEXTURES_H_
#define TEXTURES_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Util.h"
#include <map>
#include <iostream>

class Textures
{
public:
    Textures(void);
    ~Textures(void);

    static void setRenderer(SDL_Renderer *renderer);
    static void loadAllTextures();

    // Test

    static std::map<std::string, SDL_Texture*> textureMap;

    static SDL_Texture* getTexture(std::string textureName);

    static SDL_Texture* renderText(std::string message, std::string fontFile, SDL_Color color, int fontSize);
    static void renderText(int,int,std::string message, std::string fontFile, SDL_Color color, int fontSize);
    static void drawTexture(std::string textureName, int x, int y);
    static void drawTexture(std::string textureName, int x, int y, int w, int h);
    static void drawTexture(std::string textureName, int x, int y, SDL_Rect * clip);

private:
    static SDL_Renderer* renderer;
    static SDL_Texture* loadTexture(const std::string &file);
};

#endif /* TEXTURES_H_ */
