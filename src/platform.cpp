#include "definitions.hpp"

/**
 * @brief Construct a new Platform:: Platform object
 * Can take the following:
 * @param x The x position of the platform
 * @param y The y position of the platform
 * @param w The width of the platform
 * @param h The height of the platform
*/
MarioClone::Platform::Platform()
{
    width       = GAME_WIDTH;
    height      = GAME_HEIGHT / 10;
    position.x  = 0;
    position.y  = GAME_HEIGHT - height;
}

SDL_Rect MarioClone::Platform::getRect()
{
    return platformRect;
}

/**
 * @brief Construct a new Platform:: Platform object
 * @param x The x position of the platform
 * @param y The y position of the platform
 * @param w The width of the platform
 * @param h The height of the platform
*/
MarioClone::Platform::Platform(float x, float y, float w, float h)
{
    position.x = x;
    position.y = y;
    width = w;
    height = h;
}

MarioClone::Platform::~Platform()
{
}
