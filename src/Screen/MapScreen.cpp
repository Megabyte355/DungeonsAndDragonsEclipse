/*
 * MapScreen.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: Gary
 */

#include "MapScreen.h"

bool MapScreen::pathCheckRequest = false;
int MapScreen::mapWidth = 0;
int MapScreen::mapHeight = 0;

MapScreen::MapScreen() :
        Screen("MapScreen")
{
    initialize();
}

MapScreen::~MapScreen()
{
    reset();
}

void MapScreen::initialize()
{
    firstLoop = true;
    active = true;
    pathCheckRequest = false;
    textures = TextureRenderer::getInstance();
    texts = TextRenderer::getInstance();
    displayGreen = false;
    displayRed = false;
    selectedTile = Cell::CellType::Empty;
}

void MapScreen::update(float deltaTime)
{
    if (pathCheckRequest)
    {
        pathCheckRequest = false;
        validPath = mapModel->getStartToEndPath();
        if (!validPath.empty())
        {
            displayGreen = true;
        }
        else
        {
            displayRed = true;
        }
    }
}

void MapScreen::draw()
{
    textures->drawTexture("background", 0, 0, GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT);
    texts->renderText(25, 25, "Map Editor", "arial", TextRenderer::white, 35);

    for (Button * o : optionLabels)
    {
        if (o->isVisible())
        {
            o->draw();
        }
    }
    for (TileOption * t : tileOptions)
    {
        t->draw();
    }
    for (MapTile * mt : mapTiles)
    {
        mt->draw();
    }
    if (!validPath.empty())
    {
        texts->renderText(25, GameConfig::SCREEN_HEIGHT - 50, "Map is VALID", "calibri_bold", TextRenderer::green, 40);
        if (!validPath.empty())
        {
            // Certainly, the path vector has at least 2 elements
            for (unsigned int i = 1; i < validPath.size() - 1; i++)
            {
                for (auto mt : mapTiles)
                {
                    if (mt != nullptr && (mt->i == validPath[i].x) && (mt->j == validPath[i].y))
                    {
                        // Draw the path
                        textures->drawTexture("dot", mt->x, mt->y, mt->w, mt->h);
                    }
                }
            }
        }
    }
    if (displayRed)
    {
        texts->renderText(25, GameConfig::SCREEN_HEIGHT - 50, "Map is INVALID", "calibri_bold", TextRenderer::red, 40);
    }

}

void MapScreen::handleEvents(SDL_Event &event)
{
    // Hack - only this time
    if (firstLoop)
    {
        firstLoop = false;
        queryMapSize();
        // Weird stuff going on
        initData(mapWidth, mapHeight);
    }

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
        case SDL_MOUSEBUTTONDOWN:
            displayGreen = false;
            displayRed = false;
            validPath.clear();
            for (auto o : optionLabels)
            {
                o->handleEvents(event);
            }
            for (TileOption * t : tileOptions)
            {
                t->handleEvents(event);
            }
            for (MapTile * mt : mapTiles)
            {
                mt->handleEvents(event);
            }
            break;
        case SDL_MOUSEMOTION:
            for (auto o : optionLabels)
            {
                o->handleEvents(event);
            }
            for (TileOption * t : tileOptions)
            {
                t->handleEvents(event);
            }
            for (MapTile * mt : mapTiles)
            {
                mt->handleEvents(event);
            }
            break;
        default:
            break;
    }
}

void MapScreen::reset()
{
    textures = nullptr;
    texts = nullptr;
    //for (auto t : tileOptions)
    //{
    //    delete t;
    //}
}

void MapScreen::queryMapSize()
{
    std::cout << "How many columns?" << std::endl;
    std::cin >> mapWidth;
    std::cout << "How many rows?" << std::endl;
    std::cin >> mapHeight;
}

void MapScreen::initData(int width, int height)
{
    mapModel = new Map(width, height);
    
    // ...
    int tileTextureWidth = 400 / mapWidth;
    int tileTextureHeight = 400 / mapHeight;
    int currentX = 25;
    int currentY = 125;
    MapTile * mt = nullptr;
    for (int i = 0; i < mapWidth; i++)
    {
        for (int j = 0; j < mapHeight; j++)
        {
            mt = new MapTile(mapModel, i, j, currentX, currentY, tileTextureWidth, tileTextureHeight);
            mapTiles.push_back(mt);
            mt->getSelectedCellType = std::bind(&MapScreen::selectedCellType, this);
            mt = nullptr;
            currentY += tileTextureHeight;
        }
        currentX += tileTextureWidth;
        currentY = 125;
    }

    TileOption * tileOption = new TileOption(Cell::CellType::Wall, 600, 100, 200, 50);
    tileOption->functionPointer = std::bind(&MapScreen::selectTileOption, this, std::placeholders::_1);
    tileOptions.push_back(tileOption);
    tileOption = new TileOption(Cell::CellType::Floor, 600, 175, 200, 50);
    tileOption->functionPointer = std::bind(&MapScreen::selectTileOption, this, std::placeholders::_1);
    tileOptions.push_back(tileOption);
    tileOption = new TileOption(Cell::CellType::Start, 600, 250, 200, 50);
    tileOption->functionPointer = std::bind(&MapScreen::selectTileOption, this, std::placeholders::_1);
    tileOptions.push_back(tileOption);
    tileOption = new TileOption(Cell::CellType::End, 600, 325, 200, 50);
    tileOption->functionPointer = std::bind(&MapScreen::selectTileOption, this, std::placeholders::_1);
    tileOptions.push_back(tileOption);
    tileOption = new TileOption(Cell::CellType::Empty, 600, 400, 200, 50);
    tileOption->functionPointer = std::bind(&MapScreen::selectTileOption, this, std::placeholders::_1);
    tileOptions.push_back(tileOption);

    tileOption = nullptr;

//    Button * option = new Button(650, 550, 150, 50, "Validate map");
    Button * option = new Button(650, 550, 15, "Validate map");
    option->toggleVisibility();
    optionLabels.push_back(option);
    option->setOnClick(validatePath);

//    option = new Button(700, 0, 100, 50, "Back");
    option = new Button(700, 0, 15, "Back");
    option->setOnClick(returnToMenu);
    optionLabels.push_back(option);
    option->toggleVisibility();

    option = nullptr;
}

Cell::CellType MapScreen::selectedCellType()
{
    return selectedTile;
}
void MapScreen::selectTileOption(Cell::CellType type)
{
    selectedTile = type;
}

void MapScreen::returnToMenu()
{
    ScreenManager::requestScreenChange("MapScreen", "MenuScreen");
}

void MapScreen::validatePath()
{
    pathCheckRequest = true;
}
