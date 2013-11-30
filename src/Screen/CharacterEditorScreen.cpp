/*
* CharacterEditorScreen.cpp
* Author: TIFFANY
* Created on Nov 29, 2013
*/

#include "CharacterEditorScreen.h"
#include <vector>

CharacterEditorScreen::CharacterEditorScreen() :
        Screen("CharacterEditorScreen")
{
    levelSlot = 1;
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
    newFighter = new Fighter("Demo", 1);

    levelSlot = newFighter->getLevel();
    strSlot = newFighter->getStr();
    dexSlot = newFighter->getDex();
    conSlot = newFighter->getCon();
    intSlot = newFighter->getInt();
    wisSlot = newFighter->getWis();
    chaSlot = newFighter->getCha();
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
    b->setCallback(std::bind(&CharacterEditorScreen::sortForBully, this)); //1 = Bully
    typeButtons.push_back(b);
    b = new Button(475, 400, 130, 25, "Nimble");
    b->setVisibility(true);
    b->setCallback(std::bind(&CharacterEditorScreen::sortForNimble, this)); //2 = Nimble
    typeButtons.push_back(b);
    b = new Button(475, 450, 130, 25, "Tank");
    b->setVisibility(true);
    b->setCallback(std::bind(&CharacterEditorScreen::sortForTank, this)); //3 = Tank
    typeButtons.push_back(b);

    b = new Button(475, 250, 130, 75, "ROLL");
    b->setVisibility(true);
    b->setCallback(std::bind(&CharacterEditorScreen::reroll, this)); //reroll the array of ability scores
    typeButtons.push_back(b);
    b = nullptr;


}

void CharacterEditorScreen::reset()
{
    for (auto c : characterEditorChoices)
    {
        delete c;
    }
    characterEditorChoices.clear();
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

    ss << newFighter->getStr();
    texts->renderTextWithShadow(100, 255, "Strength:");
    texts->renderTextWithShadow(270, 255, ss.str());
    ss.str("");

    ss << newFighter->getDex();
    texts->renderTextWithShadow(100, 295, "Dexterity:");
    texts->renderTextWithShadow(270, 295, ss.str());
    ss.str("");

    ss << newFighter->getCon();
    texts->renderTextWithShadow(100, 335, "Constitution:");
    texts->renderTextWithShadow(270, 335, ss.str());
    ss.str("");

    ss << newFighter->getInt();
    texts->renderTextWithShadow(100, 375, "Intelligence:");
    texts->renderTextWithShadow(270, 375, ss.str());
    ss.str("");

    ss << newFighter->getWis();
    texts->renderTextWithShadow(100, 415, "Wisdom:");
    texts->renderTextWithShadow(270, 415, ss.str());
    ss.str("");

    ss << newFighter->getCha();
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
            //strcat(text, event.text.text);
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
            for (auto button : levelIncrementButtons)
            {
                button->handleEvents(event);
            }

            for (auto type : typeButtons)
            {
                type->handleEvents(event);
            }
            for (auto c : characterEditorChoices)
            {
                c->handleEvents(event);
            }

            nameTextField->handleEvents(event);

            break;
        default:
            break;
    }
}



void CharacterEditorScreen::returnToMenu()
{
    ScreenManager::requestScreenChange(getScreenName(), "EditorMenuScreen");
}


void CharacterEditorScreen::gotoSaveCharacterScreen()
{
    //ScreenManager::requestScreenChange();
    // Simply save
    PersistentData * temp = PersistentData::getInstance();
    temp->setCharLoadSlot(0);
    temp->saveCharToCurrentSlot(newFighter);
    cout << "Character has been saved!" << endl;
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


void CharacterEditorScreen::sortForBully()
{
    //sorted from lowest ===> highest ability score
   std::sort(newFighter->rolls.begin(), newFighter->rolls.end());
   newFighter->setWis(newFighter->getRolls().at(0));
   newFighter->setCha(newFighter->getRolls().at(1));
   newFighter->setInt(newFighter->getRolls().at(2));
   newFighter->setDex(newFighter->getRolls().at(3));
   newFighter->setCon(newFighter->getRolls().at(4));
   newFighter->setStr(newFighter->getRolls().at(5));

}

void CharacterEditorScreen::sortForNimble()
{
   //sorted from lowest ===> highest ability score
	std::sort(newFighter->rolls.begin(), newFighter->rolls.end());
   newFighter->setWis(newFighter->getRolls().at(0));
   newFighter->setCha(newFighter->getRolls().at(1));
   newFighter->setInt(newFighter->getRolls().at(2));
   newFighter->setStr(newFighter->getRolls().at(3));
   newFighter->setCon(newFighter->getRolls().at(4));
   newFighter->setDex(newFighter->getRolls().at(5));
}

void CharacterEditorScreen::sortForTank()
{
   //sorted from lowest ===> highest ability score
   std::sort(newFighter->rolls.begin(), newFighter->rolls.end());
   newFighter->setWis(newFighter->getRolls().at(0));
   newFighter->setCha(newFighter->getRolls().at(1));
   newFighter->setInt(newFighter->getRolls().at(2));
   newFighter->setStr(newFighter->getRolls().at(3));
   newFighter->setDex(newFighter->getRolls().at(4));
   newFighter->setCon(newFighter->getRolls().at(5));

   //newFighter->setCon(newFighter->getHighestAbilityScore());
   //newFighter->setDex(newFighter->getHighestAbilityScore());
   //newFighter->setStr(newFighter->getHighestAbilityScore());
   //newFighter->setInt(newFighter->getHighestAbilityScore());
   //newFighter->setCha(newFighter->getHighestAbilityScore());
   //newFighter->setWis(newFighter->getHighestAbilityScore());
}

void CharacterEditorScreen::reroll()
{
    newFighter->rolls.clear();
    newFighter->generateAbilityScores();
    newFighter->assignRandomScores();
}
