#include "definitions.hpp"
#include <iostream>

MarioClone::Game::Game()
{
    isRunning = false;
}

MarioClone::Game::~Game()
{
    clean();
}

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
            std::cerr << "Window failed to create with the following error: "<< SDL_GetError() << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            std::cout << "Renderer created!" << std::endl;
        }
        else
        {
            std::cerr << "Renderer failed to create with the following error: "<< SDL_GetError() << std::endl;
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    player.position.x = 0;
    player.position.y = 300;
    
    screensizeadjust = (float)width / GAME_WIDTH; // referenced in render.cpp

    platformList.push_back(Platform());
}

void MarioClone::Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

bool MarioClone::Game::running() { return isRunning; }