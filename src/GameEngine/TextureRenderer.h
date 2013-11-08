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
#include <map>
#include <iostream>
#include <string>

class TextureRenderer
{
    public:
        ~TextureRenderer();

        static TextureRenderer * getInstance();
        void setRenderer(SDL_Renderer *renderer);
        void loadAllTextures();

        SDL_Texture* getTexture(std::string textureName);

        void drawTexture(std::string textureName, int x, int y);
        void drawTexture(std::string textureName, int x, int y, int w, int h);
        void drawTexture(std::string textureName, SDL_Rect * pos, SDL_Rect * clip);
        void drawTextureClip(std::string textureName, int x, int y, SDL_Rect * clip);

    private:
        TextureRenderer();
        static TextureRenderer * instance;
        SDL_Renderer* renderer;
        std::map<std::string, SDL_Texture*> textureMap;
        SDL_Texture* loadTexture(const std::string &file);
};

#endif /* TEXTURES_H_ */
