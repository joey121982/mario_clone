#include "definitions.hpp"
#include <iostream>


/**
 * @brief The amount of time it took to render the last frame
*/
float deltaTime = 0.0f;

MarioClone::Game::Game()
{
    isRunning = false;
}

MarioClone::Game::~Game()
{
    clean();
}

/**
 * @brief Initializes the game window and renderer
 * @param title The title of the window
 * @param xpos The x position of the window
 * @param ypos The y position of the window
 * @param width The width of the window
 * @param height The height of the window
 * @param fullscreen Whether or not the window should be fullscreen
*/
void MarioClone::Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems initialized!..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created!" << std::endl;
        }
        else
        {
            std::cerr << "Window failed to create with the following error: " << SDL_GetError() << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            std::cout << "Renderer created!" << std::endl;
        }
        else
        {
            std::cerr << "Renderer failed to create with the following error: " << SDL_GetError() << std::endl;
        }

        isRunning = true;
    }
    else
    {
        std::cerr << "Initialization failed with the following error: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    if (TTF_Init())
    {
        std::cout << "TTF initialized successfully!" << std::endl;

        string sans_font_path = ASSET_PATH + "sans.ttf";
        TTF_Font *sans_font = TTF_OpenFont(sans_font_path.c_str(), 24);
        if(sans_font == NULL) {
            std::cerr << "TTF: Sans font not loaded.";
            if(DEBUG_MODE) isRunning = false;
        }
    }
    else
    {
        std::cerr << "TTF failed to initialize with the following error: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    player.position.x = 0;
    player.position.y = 300;
    
    screensizeadjust = (float)width / GAME_WIDTH; // referenced in render.cpp

    // TODO: load map here

    for(int i = 0 ; i < 10; i++)
    {
        Tilebox tilebox = Tilebox(i * TILEBOX_SIZE, GAME_HEIGHT - TILEBOX_SIZE);
        collisionObjects.push_back(tilebox.getRect());
    }
    Tilebox tilebox = Tilebox(6 * TILEBOX_SIZE, GAME_HEIGHT - 2 * TILEBOX_SIZE);
        collisionObjects.push_back(tilebox.getRect());
    

}

void MarioClone::Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

/**
 * @brief Checks if the game is running
*/
bool MarioClone::Game::running() 
{ 
    return isRunning;
}