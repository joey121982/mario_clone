#include "definitions.hpp"

void MarioClone::Game::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        
        default:
            break;
        }
    }

    const uint8_t *currentKeyStates = SDL_GetKeyboardState( NULL );
    if (currentKeyStates[SDL_SCANCODE_LEFT] || currentKeyStates[SDL_SCANCODE_A])
    {
        player.move(LEFT, PLAYER_SPEED * deltaTime);
    }
    if (currentKeyStates[SDL_SCANCODE_RIGHT] || currentKeyStates[SDL_SCANCODE_D])
    {
        player.move(RIGHT, PLAYER_SPEED * deltaTime);
    }
    if (currentKeyStates[SDL_SCANCODE_SPACE] || currentKeyStates[SDL_SCANCODE_UP] || currentKeyStates[SDL_SCANCODE_W])
    {
        if(player.grounded)
            player.jump(PLAYER_SPEED);
    }
}