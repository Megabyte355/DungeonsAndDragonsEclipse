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
        void renderText(int x, int y, std::string message);
        SDL_Rect queryTextSize(int x, int y, std::string message);

        // Preset colors
        static SDL_Color black;
        static SDL_Color white;
        static SDL_Color red;
        static SDL_Color green;
        static SDL_Color blue;

        void setColor(SDL_Color);
        void setFont(std::string);
        void setFontSize(int);
        void setSettings(std::string font, int size, SDL_Color color);

    private:
        TextRenderer();
        static TextRenderer * instance;
        static const int DEFAULT_FONT_SIZE = 22;
        SDL_Renderer* renderer;
        SDL_Color currentColor;
        std::string currentFont;
        int currentFontSize;
        std::map<std::string, std::string> fontPathMap;
        std::map<std::string, std::map<int, TTF_Font*>> fontMap;

        TTF_Font* loadPath(const std::string &file, int fontSize);
        TTF_Font* getFont(std::string font, int size);
};

#endif /* TEXTRENDERER_H_ */
