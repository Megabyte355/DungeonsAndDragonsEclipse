/*
* CharacterEditorScreen.cpp
* Author: TIFFANY
* Created on Nov 29, 2013
*/

#include "CharacterEditorScreen.h"

CharacterEditorScreen::CharacterEditorScreen() :
                Screen("CharacterEditorScreen")
{
    levelSlot = 1;
    hpSlot = 1;
    strSlot = 0;
    dexSlot = 0;
    conSlot = 0;
    intSlot = 0;
    wisSlot = 0;
    chaSlot = 0;
    nameTextField = nullptr;

}

CharacterEditorScreen::~CharacterEditorScreen()
{
    reset();
}

void CharacterEditorScreen::initialize()
{
    active = true;
    //Menu Options

    TextRenderer::getInstance()->setSettings("triforce", 25, TextRenderer::white, TextRenderer::blue);
    MenuOption * opt;
    opt = new MenuOption(250, 500, 10, "Back");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&CharacterEditorScreen::returnToMenu, this));
    characterEditorChoices.push_back(opt);

    opt = new MenuOption(500, 500, 10, "Save");
    opt->setVisibility(true);
    opt->setCallback(std::bind(&CharacterEditorScreen::gotoSaveCharacterScreen, this));
    characterEditorChoices.push_back(opt);

    //Name TextField
    nameTextField = new TextField(200,175,150,35);  // TextField( x coord, y coord, width, height)

    //Level + / - Buttons
    TextRenderer::getInstance()->setSettings("arial", 25, TextRenderer::white, TextRenderer::blue);
    Button * b;
    b = new Button(600, 160, 25, 25, "+"); //Button( x coord, y coord, width, height, text in button)
    b->setVisibility(true);
    b->setCallback(std::bind(&CharacterEditorScreen::levelUp, this));
    levelIncrementButtons.push_back(b);
    b = new Button(600, 200, 25, 25, "-");
    b->setVisibility(true);
    b->setCallback(std::bind(&CharacterEditorScreen::levelDown, this));
    levelIncrementButtons.push_back(b);


    TextRenderer::getInstance()->setSettings("retganon", 25, TextRenderer::white, TextRenderer::blue);
    //Fighter Type Buttons
    b = new Button(475, 350, 130, 25, "Bully");
    b->setVisibility(true);
    b->setCallback(std::bind(&CharacterEditorScreen::rollScores1, this)); //1 = Bully
    typeButtons.push_back(b);
    b = new Button(475, 400, 130, 25, "Nimble");
    b->setVisibility(true);
    b->setCallback(std::bind(&CharacterEditorScreen::rollScores2, this)); //2 = Nimble
    typeButtons.push_back(b);
    b = new Button(475, 450, 130, 25, "Tank");
    b->setVisibility(true);
    b->setCallback(std::bind(&CharacterEditorScreen::rollScores3, this)); //3 = Tank
    typeButtons.push_back(b);

    b = new Button(475, 250, 130, 75, "ROLL");
    b->setVisibility(true);
    b->setCallback(std::bind(&CharacterEditorScreen::reroll, this)); //reroll the array of ability scores
    typeButtons.push_back(b);
    b = nullptr;


}

void CharacterEditorScreen::reset()
{
    for (auto l : levelIncrementButtons )
    {
        delete l;
    }
    levelIncrementButtons.clear();

    for (auto t : typeButtons )
    {
        delete t;
    }
    typeButtons.clear();

    delete nameTextField;
    nameTextField = nullptr;

}

void CharacterEditorScreen::update(float deltaTime)
{
    nameTextField->update();
}

void CharacterEditorScreen::draw()
{

	nameTextField->setVisibility(true);
    TextureRenderer * textures = TextureRenderer::getInstance();
    TextRenderer * texts = TextRenderer::getInstance();

    //draw the background
    textures->drawTexture("menu_screen", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);

    //set the text to retganon font & 25 for size + shadow
    texts->setSettings("retganon", 35, TextRenderer::white, TextRenderer::blue);
    texts->renderTextWithShadow(220, 39, "CHARACTER CREATION");


    TextRenderer::getInstance()->setSettings("triforce", 25, TextRenderer::white, TextRenderer::blue);
    for (auto opt : characterEditorChoices)
    {
    	opt->draw();
    }
    texts->setSettings("arial", 25, TextRenderer::white, TextRenderer::blue);
    for (auto button : levelIncrementButtons)
    {
        button->draw();
    }

    texts->setSettings("retganon", 25, TextRenderer::white, TextRenderer::blue);
    for (auto type : typeButtons)
    {
        type->draw();
    }

    //draw text & fields
    texts->setSettings("retganon", 30, TextRenderer::white, TextRenderer::blue);
    texts->renderTextWithShadow(100, 175, "Name:");

    std::stringstream ss;
    ss << levelSlot;
    texts->renderTextWithShadow(450, 175, "Level:");
    texts->renderTextWithShadow(550, 175, ss.str());
    ss.str("");

    ss << hpSlot;
    texts->renderTextWithShadow(100, 215, "HP:");
    texts->renderTextWithShadow(270, 215, ss.str());
    ss.str("");

    ss << strSlot;
    texts->renderTextWithShadow(100, 255, "Strength:");
    texts->renderTextWithShadow(270, 255, ss.str());
    ss.str("");

    ss << dexSlot;
    texts->renderTextWithShadow(100, 295, "Dexterity:");
    texts->renderTextWithShadow(270, 295, ss.str());
    ss.str("");

    ss << conSlot;
    texts->renderTextWithShadow(100, 335, "Constitution:");
    texts->renderTextWithShadow(270, 335, ss.str());
    ss.str("");

    ss << intSlot;
    texts->renderTextWithShadow(100, 375, "Intelligence:");
    texts->renderTextWithShadow(270, 375, ss.str());
    ss.str("");

    ss << wisSlot;
    texts->renderTextWithShadow(100, 415, "Wisdom:");
    texts->renderTextWithShadow(270, 415, ss.str());
    ss.str("");

    ss << chaSlot;
    texts->renderTextWithShadow(100, 455, "Charisma:");
    texts->renderTextWithShadow(270, 455, ss.str());
    ss.str("");

    if (nameTextField->isVisible())
    {
        nameTextField->draw();
    }

    textures = nullptr;
    texts = nullptr;
}

void CharacterEditorScreen::handleEvents(SDL_Event &event)
{
     switch (event.type)
    {
        case SDL_QUIT:
            GameConfig::getInstance()->gameIsRunning = false;
            break;
        case SDL_TEXTINPUT:
            // Add new text to the end of text?
//            strcat(text, event.text.text);
            //break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                active = false;
            }
            nameTextField->handleEvents(event);
            break;
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEMOTION:
            for (auto option : characterEditorChoices)
            {
                option->handleEvents(event);
            }
            for (auto button : levelIncrementButtons)
            {
                button->handleEvents(event);
            }

            for (auto type : typeButtons)
            {
                type->handleEvents(event);
            }

            nameTextField->handleEvents(event);

            std::cout << "Moving at : (" << event.motion.x << ", " << event.motion.y << ")" << std::endl;
            break;
        default:
            break;
    }
}



void CharacterEditorScreen::returnToMenu()
{
    ScreenManager::requestScreenChange("CharacterEditorScreen", "EditorMenuScreen");
}


void CharacterEditorScreen::gotoSaveCharacterScreen()
{
    //ScreenManager::requestScreenChange();
}

void CharacterEditorScreen::levelUp()
{
    if (levelSlot < 20)
    {
        levelSlot++;
    }
}

void CharacterEditorScreen::levelDown()
{
    if (levelSlot > 1)
    {
        levelSlot--;
    }
}


void CharacterEditorScreen::rollScores1()
{
    //roll random scores and assing according to type

}
void CharacterEditorScreen::rollScores2()
{
    //roll random scores and assing according to type

}
void CharacterEditorScreen::rollScores3()
{
    //roll random scores and assing according to type

}

void CharacterEditorScreen::reroll()
{

}

void CharacterEditorScreen::updateHP(int newHP)
{
    if (hpSlot != newHP)
    {
        hpSlot = newHP;
    }
}
void CharacterEditorScreen::updateStr(int newStr)
{
    if (strSlot != newStr)
    {
        strSlot = newStr;
    }
}
void CharacterEditorScreen::updateDex(int newDex)
{
    if (dexSlot != newDex)
    {
        dexSlot = newDex;
    }
}
void CharacterEditorScreen::updateCon(int newCon)
{
    if (conSlot != newCon)
    {
        conSlot = newCon;
    }
}
void CharacterEditorScreen::updateWis(int newWis)
{
    if (wisSlot != newWis)
    {
        wisSlot = newWis;
    }
}
void CharacterEditorScreen::updateInt(int newInt)
{
    if (intSlot != newInt)
    {
        intSlot = newInt;
    }
}
void CharacterEditorScreen::updateCha(int newCha)
{
    if (chaSlot != newCha)
    {
        chaSlot = newCha;
    }
}
