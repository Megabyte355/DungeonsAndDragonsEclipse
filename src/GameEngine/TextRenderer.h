/*
 * TextRenderer.h
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#ifndef TEXTRENDERER_H_
#define TEXTRENDERER_H_

#include "GameConfig.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map>

class TextRenderer
{
    public:
        TextRenderer();
        ~TextRenderer();

        static void setRenderer(SDL_Renderer *renderer);
        static SDL_Texture* renderText(std::string message, std::string fontFile, SDL_Color color, int fontSize);

    private:
        static SDL_Renderer* renderer;
        static TTF_Font* loadFont(const std::string &file);
    /*
     *
     static void setRenderer(SDL_Renderer *renderer);
    static void loadAllTextures();

    // Test

    static std::map<std::string, SDL_Texture*> textureMap;

    static SDL_Texture* getTexture(std::string textureName);
    static SDL_Texture* renderText(std::string message, std::string fontFile, SDL_Color color, int fontSize);

    static void drawTexture(std::string textureName, int x, int y);
    static void drawTexture(std::string textureName, int x, int y, int w, int h);
    static void drawTexture(std::string textureName, int x, int y, SDL_Rect * clip = nullptr);

private:
    static SDL_Renderer* renderer;
    static SDL_Texture* loadTexture(const std::string &file);
    static TTF_Font* loadFont(const std::string &file);
     */
};

#endif /* TEXTRENDERER_H_ */
