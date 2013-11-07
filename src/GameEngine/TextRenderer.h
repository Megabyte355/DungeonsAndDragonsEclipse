/*
 * TextRenderer.h
 *
 *  Created on: Nov 2, 2013
 *      Author: Gary
 */

#ifndef TEXTRENDERER_H_
#define TEXTRENDERER_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map>
#include <iostream>
#include <string>

class TextRenderer
{
    public:
        ~TextRenderer();

        static TextRenderer * getInstance();
        void setRenderer(SDL_Renderer *renderer);
        void loadFontPaths();
        void renderText(int x, int y, std::string message, std::string fontName, SDL_Color color, int fontSize);

        // Preset colors
        static SDL_Color black;
        static SDL_Color white;
        static SDL_Color red;
        static SDL_Color green;
        static SDL_Color blue;

    private:
        TextRenderer();
        static TextRenderer * instance;
        static const int DEFAULT_FONT_SIZE = 20;
        SDL_Renderer* renderer;
        std::map<std::string, std::string> fontMap;

        TTF_Font* loadPath(const std::string &file);
};

#endif /* TEXTRENDERER_H_ */
