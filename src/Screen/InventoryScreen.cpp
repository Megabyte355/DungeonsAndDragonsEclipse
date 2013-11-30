/*
 * InventoryScreen.cpp
 *
 *  Created on: Nov 30, 2013
 *      Author: Tim
 */


#include "InventoryScreen.h"

InventoryScreen::InventoryScreen() :
        Screen("InventoryScreen")
{
}

InventoryScreen::~InventoryScreen()
{
    reset();
}

void InventoryScreen::initialize()
{
    active = true;


    audio->playMusic(2);
    MenuOption * opt;
    opt = new MenuOption(650, 15, 25, "Back");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&InventoryScreen::goBack, this));
    menuOptions.push_back(opt);


    opt = nullptr;
}

void InventoryScreen::reset()
{
    for (auto o : menuOptions)
    {
        delete o;
    }
    menuOptions.clear();
}

void InventoryScreen::update(float deltaTime)
{
}

void InventoryScreen::draw()
{
    TextureRenderer * textures = TextureRenderer::getInstance();
    TextRenderer * texts = TextRenderer::getInstance();

    textures->drawTexture("menu_screen", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);

    texts->setSettings("retganon", 45, TextRenderer::white, TextRenderer::blue);
    texts->renderTextWithShadow(229, 39, "Inventory");


    texts->setSettings("retganon", 20, TextRenderer::white, TextRenderer::blue);

    textures->drawTexture("black_button_clicked",160,155,60,60);
    texts->renderTextWithShadow(170,170,"Helmet");

    textures->drawTexture("black_button_clicked",160,235,60,60);
    texts->renderTextWithShadow(170,250,"Armor");

    textures->drawTexture("black_button_clicked",160,315,60,60);
    texts->renderTextWithShadow(170,330,"Belt");

    textures->drawTexture("black_button_clicked",160,395,60,60);
    texts->renderTextWithShadow(170,410,"Boots");

    textures->drawTexture("black_button_clicked",240,190,60,60);
    texts->renderTextWithShadow(250,205,"Weapon");

    textures->drawTexture("black_button_clicked",240,270,60,60);
    texts->renderTextWithShadow(250,285,"Shield");

    textures->drawTexture("black_button_clicked",80,190,60,60);
    texts->renderTextWithShadow(90,205,"Gloves");

    textures->drawTexture("black_button_clicked",80,270,60,60);
    texts->renderTextWithShadow(90,285,"Ring");

    texts->setSettings("retganon", 40, TextRenderer::white, TextRenderer::blue);

    texts->renderTextWithShadow(80,465,"STR:");

    texts->renderTextWithShadow(75,520,"MODS");

    texts->renderTextWithShadow(185,465,"DEX:");
    texts->renderTextWithShadow(290,465,"CON:");
    texts->renderTextWithShadow(395,465,"INT:");
    texts->renderTextWithShadow(500,465,"WIS:");
    texts->renderTextWithShadow(605,465,"CHA:");


    texts->renderTextWithShadow(320,150,"HP:");
    texts->renderTextWithShadow(320,300,"AC:");


    textures->drawTexture("black_button_clicked",375,150,360,300);

    for (auto option : menuOptions)
    {
        option->draw();
    }

    textures = nullptr;
    texts = nullptr;
}

void InventoryScreen::handleEvents(SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_QUIT:
            GameConfig::getInstance()->gameIsRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                active = false;
            }
            break;
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEMOTION:
            // TODO Testing code to be removed
            //std::cout << "Moving at : (" << event.motion.x << ", " << event.motion.y << ")" << std::endl;
            for (auto option : menuOptions)
            {
                option->handleEvents(event);
            }
            break;
        default:
            break;
    }
}

void InventoryScreen::goBack()
{
    // TODO When new screen is complete, fix this, should change to main game screen... or something
//    ScreenManager::requestScreenChange("", "");
    std::cout << "goback" << std::endl;
}



