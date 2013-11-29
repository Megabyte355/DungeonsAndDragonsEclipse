/*
 * EditorMenuScreen.cpp
 *
 *  Created on: Nov 28, 2013
 *      Author: Gary
 */

#include "EditorMenuScreen.h"

EditorMenuScreen::EditorMenuScreen() :
        Screen("EditorMenuScreen")
{
}

EditorMenuScreen::~EditorMenuScreen()
{
    reset();
}

void EditorMenuScreen::initialize()
{
    active = true;

    MenuOption * opt;
    opt = new MenuOption(300, 200, 25, "Character Editor");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&EditorMenuScreen::goToCharacterEditorScreen, this));
    editorOptions.push_back(opt);
    opt = new MenuOption(300, 300, 25, "Map Editor");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&EditorMenuScreen::goToMapEditorScreen, this));
    editorOptions.push_back(opt);
    opt = new MenuOption(300, 400, 25, "Back");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&EditorMenuScreen::goToMainMenuScreen, this));
    editorOptions.push_back(opt);
    opt = nullptr;
}

void EditorMenuScreen::reset()
{
    for (auto o : editorOptions)
    {
        delete o;
    }
    editorOptions.clear();
}

void EditorMenuScreen::update(float deltaTime)
{
}

void EditorMenuScreen::draw()
{
    TextureRenderer * textures = TextureRenderer::getInstance();
    TextRenderer * texts = TextRenderer::getInstance();

    textures->drawTexture("menu_screen", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);

    texts->setSettings("retganon", 45, TextRenderer::white, TextRenderer::blue);
    texts->renderTextWithShadow(220, 39, "EDITOR MENU");

    texts->setSettings("retganon", 40, TextRenderer::white, TextRenderer::blue);
    for (auto option : editorOptions)
    {
        option->draw();
    }

    textures = nullptr;
    texts = nullptr;
}

void EditorMenuScreen::handleEvents(SDL_Event& event)
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
            for (auto option : editorOptions)
            {
                option->handleEvents(event);
            }
            break;
        default:
            break;
    }
}

void EditorMenuScreen::goToCharacterEditorScreen()
{
    // TODO Finish Character Editor screen
}

void EditorMenuScreen::goToMapEditorScreen()
{
    // TODO Finish Map Editor screen
}

void EditorMenuScreen::goToMainMenuScreen()
{
    ScreenManager::requestScreenChange("EditorMenuScreen", "MainMenuScreen");
}
