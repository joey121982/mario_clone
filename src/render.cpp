#include "definitions.hpp"
#include <math.h>

/**
 * @brief Renders text to a part of the screen
 * 
 * @param renderer 
 * @param text 
 * @param font 
 * @param textColor 
 * @param position 
 */
void render_text(SDL_Renderer *renderer, string text, TTF_Font *font, SDL_Color textColor, Vector2 position)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int text_width = textSurface->w;
    int text_height = textSurface->h;
    SDL_FreeSurface(textSurface);
    SDL_Rect renderQuad = { position.x, position.y, text_width, text_height };
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
    SDL_DestroyTexture(texture);
}

/**
 * @brief Renders the game
*/
void MarioClone::Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // This is where we would add stuff to render.

    /// IMPORTANT: REMEMBER TO USE THE ADJUSTED SCALE WHEN RENDERING

    // Player is rendered in the middle of the screen at all times.
    SDL_Rect playerRect = player.getRect();
    playerRect.x = GAME_WIDTH / 2 * screensizeadjust;
    playerRect.y = GAME_HEIGHT / 2 * screensizeadjust;
    playerRect.w = player.width * screensizeadjust;
    playerRect.h = player.height * screensizeadjust;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &playerRect);

    // How to render relative to player position:
    //      objectRect.x = (object.x - player.position.x + GAME_WIDTH / 2) * screensizeadjust;
    //      objectRect.y = (object.y - player.position.y + GAME_HEIGHT / 2) * screensizeadjust;
    
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

    if(DEBUG_MODE)
    {
        // show useful data
        // std::cout << player.position.x << " " << player.position.y << " " << player.horizontalVelocity << " " << player.verticalVelocity << std::endl;
    
        string pos_data = "Position (X, Y): " 
            + std::to_string(player.position.x)
            + " | "
            + std::to_string(player.position.y);

        string velocity_data = "Velocity (hor, vert): "
            + std::to_string(player.horizontalVelocity)
            + " | "
            + std::to_string(player.verticalVelocity);

        SDL_Color textColor = {255, 255, 255, 0};

        render_text(renderer, pos_data, fonts.sans, textColor, Vector2(20, screenheight - 40));
        render_text(renderer, velocity_data, fonts.sans, textColor, Vector2(20, screenheight - 70));
    }

    SDL_RenderPresent(renderer);
}