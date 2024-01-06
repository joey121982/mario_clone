#include "definitions.hpp"

/**
 * @brief Renders the game
*/
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

    // How to render relative to player position:
    // platformRect.x = (platform.position.x - player.position.x + GAME_WIDTH / 2) * screensizeadjust;
    // platformRect.y = (platform.position.y - player.position.y + GAME_HEIGHT / 2) * screensizeadjust;
    
    for(auto object : collisionObjects)
    {
        SDL_Rect objectRect;
        objectRect.x = (object.x - player.position.x + GAME_WIDTH / 2) * screensizeadjust;
        objectRect.y = (object.y - player.position.y + GAME_HEIGHT / 2) * screensizeadjust;
        objectRect.w = TILEBOX_SIZE * screensizeadjust;
        objectRect.h = TILEBOX_SIZE * screensizeadjust;
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderFillRect(renderer, &objectRect);
    }
    std::cout << player.position.x << " " << player.position.y << std::endl;

    SDL_RenderPresent(renderer);
}