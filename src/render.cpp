#include "definitions.hpp"

void MarioClone::Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);


    // This is where we would add stuff to render.
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect playerRect;
    playerRect.x = player.position.x;
    playerRect.y = player.position.y;
    playerRect.w = PLAYER_WIDTH;
    playerRect.h = PLAYER_HEIGHT;
    SDL_RenderFillRect(renderer, &playerRect);


    SDL_RenderPresent(renderer);
}