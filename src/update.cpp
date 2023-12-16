#include "definitions.hpp"

void MarioClone::Game::update()
{
    player.grounded = false;

    SDL_Rect playerRect = player.getRect();

    playerRect.x = player.position.x;
    playerRect.y = player.position.y;
    playerRect.w = PLAYER_WIDTH;
    playerRect.h = PLAYER_HEIGHT;

    int i = 0;
    for (Platform &platform : platformList)
    {
        SDL_Rect platformRect = platform.getRect();

        platformRect.x = platform.position.x;
        platformRect.y = platform.position.y;
        platformRect.w = platform.width;
        platformRect.h = platform.height;

        if(Utilities::checkCollision(platformRect, playerRect))
        {
            player.position.y       = platform.position.y - player.height;
            player.verticalVelocity = 0;
            player.grounded         = true;
            break;
        }
    }
    
    if(!player.grounded)
    {
        player.position.y       += player.verticalVelocity  * deltaTime;
        player.verticalVelocity += GRAVITY                  * deltaTime;
    }
}