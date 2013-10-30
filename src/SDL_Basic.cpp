//============================================================================
// Name        : SDL_Basic.cpp
// Author      : Gary Chang
// Version     :
// Copyright   : Free Software
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!


    // C++11 test
    std::unique_ptr<int> i;

    // SDL_image test
    SDL_Texture * texture = nullptr;

    return 0;
}
