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
        void renderTextWithShadow(int x, int y, std::string message);
        SDL_Rect queryTextSize(int x, int y, std::string message);

        // Preset colors
        static SDL_Color black;
        static SDL_Color white;
        static SDL_Color red;
        static SDL_Color green;
        static SDL_Color blue;

        void setCurrentColor(SDL_Color);
        void setShadowColor(SDL_Color);
        void setCurrentFont(std::string);
        void setCurrentFontSize(int);
        void setSettings(std::string font, int size, SDL_Color color);
        void setSettings(std::string font, int size, SDL_Color color, SDL_Color shadow);
        SDL_Color getCurrentColor() const;
        const std::string& getCurrentFont() const;
        int getCurrentFontSize() const;
        SDL_Color getShadowColor() const;

    private:
        TextRenderer();
        static TextRenderer * instance;
        static const int DEFAULT_FONT_SIZE = 22;
        SDL_Renderer* renderer;
        SDL_Color currentColor;
        SDL_Color shadowColor;
        std::string currentFont;
        int currentFontSize;
        std::map<std::string, std::string> fontPathMap;
        std::map<std::string, std::map<int, TTF_Font*> > fontMap;

        TTF_Font* loadPath(const std::string &file, int fontSize);
        TTF_Font* getFont(std::string font, int size);
};

#endif /* TEXTRENDERER_H_ */
