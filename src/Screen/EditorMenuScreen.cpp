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
    premadeSlot = 0;
    fileSlot = 0;
    widthText = nullptr;
    heightText = nullptr;
}

EditorMenuScreen::~EditorMenuScreen()
{
    reset();
}

void EditorMenuScreen::initialize()
{
	audio->playMusic(2);
    active = true;
    currentChoices = nullptr;

    // General Editor Menu options
    MenuOption * opt;
    opt = new MenuOption(300, 200, 10, "Character Editor");
    opt->setCallback(std::bind(&EditorMenuScreen::characterEditorMenu, this));
    generalEditorChoices.push_back(opt);
    opt = new MenuOption(300, 300, 10, "Map Editor");
    opt->setCallback(std::bind(&EditorMenuScreen::mapEditorMenu, this));
    generalEditorChoices.push_back(opt);
    opt = new MenuOption(300, 450, 10, "Back");
    opt->setCallback(std::bind(&EditorMenuScreen::goToMainMenuScreen, this));
    generalEditorChoices.push_back(opt);

    // Map Editor Menu options
    opt = new MenuOption(175, 200, 10, "Create new map");
    opt->setCallback(std::bind(&EditorMenuScreen::goToMapEditorScreen, this));
    mapEditorChoices.push_back(opt);
    opt = new MenuOption(175, 275, 10, "Load pre-made map");
    opt->setCallback(std::bind(&EditorMenuScreen::goToMapEditorScreenWithPremade, this));
    mapEditorChoices.push_back(opt);
    opt = new MenuOption(175, 350, 10, "Load saved map");
    opt->setCallback(std::bind(&EditorMenuScreen::goToMapEditorScreenWithSaved, this));
    mapEditorChoices.push_back(opt);
    opt = new MenuOption(175, 450, 10, "Back");
    opt->setCallback(std::bind(&EditorMenuScreen::generalEditorMenu, this));
    mapEditorChoices.push_back(opt);

    // Character Editor options
    opt = new MenuOption(175, 200, 10, "Create new character");
    opt->setCallback(std::bind(&EditorMenuScreen::goToCharacterEditorScreen, this));
    characterEditorChoices.push_back(opt);
    opt = new MenuOption(175, 275, 10, "Load pre-made character");
    opt->setCallback(std::bind(&EditorMenuScreen::goToCharacterEditorScreenWithPremade, this));
    characterEditorChoices.push_back(opt);
    opt = new MenuOption(175, 350, 10, "Load saved character");
    opt->setCallback(std::bind(&EditorMenuScreen::goToCharacterEditorScreenWithSaved, this));
    characterEditorChoices.push_back(opt);
    opt = new MenuOption(175, 450, 10, "Back");
    opt->setCallback(std::bind(&EditorMenuScreen::generalEditorMenu, this));
    characterEditorChoices.push_back(opt);

    opt = nullptr;

    // Buttons
    TextRenderer::getInstance()->setSettings("arial", 25, TextRenderer::white, TextRenderer::blue);
    Button * b;
    b = new Button(700, 285, 25, 25, "+");
    b->setVisibility(true);
    b->setCallback(std::bind(&EditorMenuScreen::premadeSlotUp, this));
    mapIncrementButtons.push_back(b);
    b = new Button(700, 310, 25, 25, "-");
    b->setVisibility(true);
    b->setCallback(std::bind(&EditorMenuScreen::premadeSlotDown, this));
    mapIncrementButtons.push_back(b);
    b = new Button(700, 363, 25, 25, "+");
    b->setVisibility(true);
    b->setCallback(std::bind(&EditorMenuScreen::fileSlotUp, this));
    mapIncrementButtons.push_back(b);
    b = new Button(700, 388, 25, 25, "-");
    b->setVisibility(true);
    b->setCallback(std::bind(&EditorMenuScreen::fileSlotDown, this));
    mapIncrementButtons.push_back(b);
    b = nullptr;

    // Numeric Textfields
    widthText = new NumericTextField(605, 215, 35, 35, 2);
    heightText = new NumericTextField(670, 215, 35, 35, 2);

    changeMenu(GeneralEditorMenu);
}

void EditorMenuScreen::reset()
{
    currentChoices = nullptr;
    for (auto g : generalEditorChoices)
    {
        delete g;
    }
    generalEditorChoices.clear();

    for (auto m : mapEditorChoices)
    {
        delete m;
    }
    mapEditorChoices.clear();

    for (auto c : characterEditorChoices)
    {
        delete c;
    }
    characterEditorChoices.clear();

    for (auto b : mapIncrementButtons)
    {
        delete b;
    }
    mapIncrementButtons.clear();

    delete widthText;
    delete heightText;
    widthText = nullptr;
    heightText = nullptr;
}

void EditorMenuScreen::update(float deltaTime)
{
    widthText->update();
    heightText->update();
}

void EditorMenuScreen::draw()
{
    TextureRenderer * textures = TextureRenderer::getInstance();
    TextRenderer * texts = TextRenderer::getInstance();

    textures->drawTexture("menu_screen", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);

    texts->setSettings("retganon", 45, TextRenderer::white, TextRenderer::blue);
    texts->renderTextWithShadow(220, 39, "EDITOR MENU");

    texts->setSettings("retganon", 40, TextRenderer::white, TextRenderer::blue);
    for (auto option : *currentChoices)
    {
        option->draw();
    }

    texts->setSettings("arial", 25, TextRenderer::white, TextRenderer::blue);
    for (auto button : mapIncrementButtons)
    {
        button->draw();
    }

    if (currentState == MapMenu)
    {
        int x = 550;
        int y = 218;
        texts->setSettings("retganon", 30, TextRenderer::white, TextRenderer::blue);
        texts->renderTextWithShadow(x, y, "Size:");
        texts->renderTextWithShadow(x + 100, y, "x");
        texts->renderTextWithShadow(x + 70, y - 35, "H");
        texts->renderTextWithShadow(x + 130, y - 35, "W");

        std::stringstream ss;
        ss << premadeSlot;
        texts->renderTextWithShadow(x, 292, "Map:");
        texts->renderTextWithShadow(x + 100, 292, ss.str());
        ss.str("");
        ss << fileSlot;
        texts->renderTextWithShadow(x, 370, "File:");
        texts->renderTextWithShadow(x + 100, 370, ss.str());

    }

    if (widthText->isVisible() && heightText->isVisible())
    {
        widthText->draw();
        heightText->draw();
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
        case SDL_TEXTINPUT:
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                active = false;
            }
            widthText->handleEvents(event);
            heightText->handleEvents(event);
            break;
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEMOTION:
            for (auto option : *currentChoices)
            {
                option->handleEvents(event);
            }
            for (auto button : mapIncrementButtons)
            {
                button->handleEvents(event);
            }
            if (currentState == MapMenu)
            {
                widthText->handleEvents(event);
                heightText->handleEvents(event);
            }
            std::cout << "Moving at : (" << event.motion.x << ", " << event.motion.y << ")" << std::endl;
            break;
        default:
            break;
    }
}

void EditorMenuScreen::changeMenu(EditorMenuState state)
{
    bool textFieldsVisible = false;
    bool buttonsVisible = false;

    if (currentChoices != nullptr)
    {
        for (auto c : *currentChoices)
        {
            c->setVisibility(false);
        }
    }

    currentState = state;
    if (currentState == CharacterMenu)
    {
        currentChoices = &characterEditorChoices;
    }
    else if (currentState == MapMenu)
    {
        currentChoices = &mapEditorChoices;
        buttonsVisible = true;
        textFieldsVisible = true;
    }
    else
    {
        currentChoices = &generalEditorChoices;
    }
    for (auto c : *currentChoices)
    {
        c->setVisibility(true);
    }

    widthText->setVisibility(textFieldsVisible);
    heightText->setVisibility(textFieldsVisible);
    for (auto button : mapIncrementButtons)
    {
        button->setVisibility(buttonsVisible);
    }
}

void EditorMenuScreen::characterEditorMenu()
{
    changeMenu(CharacterMenu);
}

void EditorMenuScreen::mapEditorMenu()
{
    changeMenu(MapMenu);
}

void EditorMenuScreen::generalEditorMenu()
{
    changeMenu(GeneralEditorMenu);
}

void EditorMenuScreen::goToMainMenuScreen()
{
    ScreenManager::requestScreenChange("EditorMenuScreen", "MainMenuScreen");
}

void EditorMenuScreen::goToMapEditorScreen()
{
}

void EditorMenuScreen::goToMapEditorScreenWithPremade()
{
}

void EditorMenuScreen::goToMapEditorScreenWithSaved()
{
}

void EditorMenuScreen::fileSlotUp()
{
    if (fileSlot < 10)
    {
        fileSlot++;
    }
}

void EditorMenuScreen::fileSlotDown()
{
    if (fileSlot > 0)
    {
        fileSlot--;
    }
}

void EditorMenuScreen::premadeSlotUp()
{
    if (premadeSlot < 10)
    {
        premadeSlot++;
    }
}

void EditorMenuScreen::goToCharacterEditorScreen()
{
	ScreenManager::requestScreenChange("EditorMenuScreen", "CharacterEditorScreen");
}

void EditorMenuScreen::goToCharacterEditorScreenWithPremade()
{
}

void EditorMenuScreen::goToCharacterEditorScreenWithSaved()
{
}

void EditorMenuScreen::premadeSlotDown()
{
    if (premadeSlot > 0)
    {
        premadeSlot--;
    }
}
