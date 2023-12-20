#include "definitions.hpp"

void MarioClone::Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // This is where we would add stuff to render.

    // IMPORTANT: REMEMBER TO USE THE ADJUSTED SCALE WHEN RENDERING

    // Player is rendered in the middle of the screen at all times.
    SDL_Rect playerRect = player.getRect();
    playerRect.x = GAME_WIDTH / 2 * screensizeadjust;
    playerRect.y = GAME_HEIGHT / 2 * screensizeadjust;
    playerRect.w = player.width * screensizeadjust;
    playerRect.h = player.height * screensizeadjust;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &playerRect);

    // Platforms are rendered relative to the player's position.
    for (auto &platform : platformList)
    {
        SDL_Rect platformRect = platform.getRect();
        // The player's position is subtracted from the platform's position to get the relative position.
        platformRect.x = (platform.position.x - player.position.x + GAME_WIDTH / 2) * screensizeadjust;
        platformRect.y = (platform.position.y - player.position.y + GAME_HEIGHT / 2) * screensizeadjust;
        platformRect.w = platform.width * screensizeadjust;
        platformRect.h = platform.height * screensizeadjust;
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderFillRect(renderer, &platformRect);
    }

    SDL_RenderPresent(renderer);
}