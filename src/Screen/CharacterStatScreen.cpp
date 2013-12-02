/*
* CharacterStatScreen.cpp
* Author: TIFFANY
* Created on Nov 29, 2013
*/

#include "CharacterStatScreen.h"
#include <vector>

CharacterStatScreen::CharacterStatScreen() :
        Screen("CharacterStatScreen")
{
    levelSlot = 1;
    hpSlot = 1;
    acSlot = 0;
    strSlot = 0;
    dexSlot = 0;
    conSlot = 0;
    intSlot = 0;
    wisSlot = 0;
    chaSlot = 0;

    attackBonusSlot1 = 0;
    attackBonusSlot2 = 0;
    attackBonusSlot3 = 0;
    attackBonusSlot4 = 0;

    nameTextField = nullptr;

}

CharacterStatScreen::~CharacterStatScreen()
{
    reset();
}

void CharacterStatScreen::initialize()
{
    active = true;

    PersistentData* data = PersistentData::getInstance();
    data->loadCharFromCurrentSlot();
    currentChar = data->getCurrentChar();

    TextRenderer::getInstance()->setSettings("triforce", 25, TextRenderer::white, TextRenderer::blue);
    MenuOption * opt;
    opt = new MenuOption(250, 500, 10, "Back");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&CharacterStatScreen::returnToMenu, this));
    menuOptions.push_back(opt);


    //Name TextField
    nameTextField = new TextField(200,175,150,35);  // TextField( x coord, y coord, width, height

}

void CharacterStatScreen::reset()
{
    for (auto m : menuOptions)
    {
        delete m;
    }
    menuOptions.clear();

    delete nameTextField;
    nameTextField = nullptr;

}

void CharacterStatScreen::update(float deltaTime)
{
    //nothing to update
}

void CharacterStatScreen::draw()
{

    nameTextField->setVisibility(true);
    TextureRenderer * textures = TextureRenderer::getInstance();
    TextRenderer * texts = TextRenderer::getInstance();

    //draw the background
    textures->drawTexture("menu_screen", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);

    //set the text to retganon font & 25 for size + shadow
    texts->setSettings("retganon", 35, TextRenderer::white, TextRenderer::blue);
    texts->renderTextWithShadow(220, 39, "CHARACTER STATS");


    TextRenderer::getInstance()->setSettings("triforce", 25, TextRenderer::white, TextRenderer::blue);
    for (auto opt : menuOptions)
    {
        opt->draw();
    }

    //draw text & fields
    texts->setSettings("retganon", 30, TextRenderer::white, TextRenderer::blue);
    texts->renderTextWithShadow(100, 175, "Name:");

    std::stringstream ss;

    ss << currentChar->getLevel();
    texts->renderTextWithShadow(450, 175, "Level:");
    texts->renderTextWithShadow(550, 175, ss.str());
    ss.str("");

    ss << currentChar->getStr();
    texts->renderTextWithShadow(100, 255, "Strength:");
    texts->renderTextWithShadow(270, 255, ss.str());
    ss.str("");

    ss << currentChar->getDex();
    texts->renderTextWithShadow(100, 295, "Dexterity:");
    texts->renderTextWithShadow(270, 295, ss.str());
    ss.str("");

    ss << currentChar->getCon();
    texts->renderTextWithShadow(100, 335, "Constitution:");
    texts->renderTextWithShadow(270, 335, ss.str());
    ss.str("");

    ss << currentChar->getInt();
    texts->renderTextWithShadow(100, 375, "Intelligence:");
    texts->renderTextWithShadow(270, 375, ss.str());
    ss.str("");

    ss << currentChar->getWis();
    texts->renderTextWithShadow(100, 415, "Wisdom:");
    texts->renderTextWithShadow(270, 415, ss.str());
    ss.str("");

    ss << currentChar->getCha();
    texts->renderTextWithShadow(100, 455, "Charisma:");
    texts->renderTextWithShadow(270, 455, ss.str());
    ss.str("");

    ss << currentChar->getHP();
    texts->renderTextWithShadow(400, 255, "HP:");
    texts->renderTextWithShadow(600, 255, ss.str());
    ss.str("");

    ss << currentChar->getAC();
    texts->renderTextWithShadow(400, 295, "AC:");
    texts->renderTextWithShadow(600, 295, ss.str());
    ss.str("");

    ss << currentChar->getBaseAttackBonus1();
    texts->renderTextWithShadow(400, 335, "AttackBonus1:");
    texts->renderTextWithShadow(600, 335, ss.str());
    ss.str("");

    ss << currentChar->getBaseAttackBonus2();
    texts->renderTextWithShadow(400, 375, "AttackBonus2:");
    texts->renderTextWithShadow(600, 375, ss.str());
    ss.str("");

    ss << currentChar->getBaseAttackBonus3();
    texts->renderTextWithShadow(400, 415, "AttackBonus3:");
    texts->renderTextWithShadow(600, 415, ss.str());
    ss.str("");

    ss << currentChar->getBaseAttackBonus4();
    texts->renderTextWithShadow(400, 455, "AttackBonus4:");
    texts->renderTextWithShadow(600, 455, ss.str());
    ss.str("");

    if (nameTextField->isVisible())
    {
        nameTextField->setText(currentChar->getName());
        nameTextField->draw();
    }

    textures = nullptr;
    texts = nullptr;
}

void CharacterStatScreen::handleEvents(SDL_Event &event)
{
     switch (event.type)
    {
        case SDL_QUIT:
            GameConfig::getInstance()->gameIsRunning = false;
            break;
        case SDL_TEXTINPUT:
            // Add new text to the end of text?
            //strcat(text, event.text.text);
        case SDL_KEYDOWN:
            // if (event.key.keysym.sym == SDLK_ESCAPE)
            // {
            //     active = false;
            // }
            // nameTextField->handleEvents(event);
            break;
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEMOTION:
            for (auto m : menuOptions)
            {
                m->handleEvents(event);
            }
            break;
        default:
            break;
    }
}



void CharacterStatScreen::returnToMenu()
{
    ScreenManager::requestScreenChange("CharacterStatScreen", "EditorMenuScreen");
}
