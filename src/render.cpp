#include "definitions.hpp"

void MarioClone::Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // This is where we would add stuff to render.

    // IMPORTANT: REMEMBER TO USE THE ADJUSTED SCALE WHEN RENDERING

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // get reference to playerRect
    SDL_Rect playerRect = player.getRect();
    playerRect.x = player.position.x * screensizeadjust;
    playerRect.y = player.position.y * screensizeadjust;
    playerRect.w = PLAYER_WIDTH * screensizeadjust;
    playerRect.h = PLAYER_HEIGHT * screensizeadjust;
    SDL_RenderFillRect(renderer, &playerRect);

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);

    for(Platform &platform : platformList)
    {
        SDL_Rect platformRect;
        platformRect.x = platform.position.x * screensizeadjust;
        platformRect.y = platform.position.y * screensizeadjust;
        platformRect.w = platform.width * screensizeadjust;
        platformRect.h = platform.height * screensizeadjust;
        SDL_RenderFillRect(renderer, &platformRect);
    }


    SDL_RenderPresent(renderer);
}