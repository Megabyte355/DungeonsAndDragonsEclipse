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
#include <iostream>

class TextRenderer
{
    public:
        TextRenderer();
        ~TextRenderer();

        static void setRenderer(SDL_Renderer *renderer);
        static void loadFontPaths();

        static void renderText(int x, int y, std::string message, std::string fontName, SDL_Color color, int fontSize);

        // Preset colors
        static SDL_Color white;
        static SDL_Color black;
        static SDL_Color red;
        static SDL_Color green;
        static SDL_Color blue;

    private:
        static SDL_Renderer* renderer;
        static std::map<std::string, std::string> fontMap;
        static TTF_Font* loadPath(const std::string &file);
};

#endif /* TEXTRENDERER_H_ */
