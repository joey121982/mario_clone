#include "definitions.hpp"

bool isInLine(SDL_Rect a, SDL_Rect b)
{
    int marginoferror = 4;
    if(a.x + a.w < b.x + marginoferror)
        return false;
    if(a.x + marginoferror > b.x + b.w)
        return false;
    return true;
}

void MarioClone::Game::update()
{
    player.grounded = false;

    SDL_Rect playerRect = player.getRect();

    playerRect.x = player.position.x;
    playerRect.y = player.position.y;
    playerRect.w = PLAYER_WIDTH;
    playerRect.h = PLAYER_HEIGHT;

    for (auto &objectRect : collisionObjects)
    {
        if (Utilities::checkCollision(playerRect, objectRect))
        {
            if (isInLine(objectRect, playerRect))
            {
                if (player.verticalVelocity > 0)
                {
                    player.position.y = objectRect.y - playerRect.h;
                    player.verticalVelocity = 0;
                    player.grounded = true;
                }
                else if (player.verticalVelocity < 0)
                {
                    player.position.y = objectRect.y + objectRect.h;
                    player.verticalVelocity = 0;
                }
            }
            else
            {
                if (player.position.x < objectRect.x)
                {
                    player.position.x = objectRect.x - playerRect.w;
                }
                else
                {
                    player.position.x = objectRect.x + objectRect.w;
                }
            }
        }
    }
    
    if(!player.grounded)
    {
        player.position.y       += player.verticalVelocity  * deltaTime;
        player.verticalVelocity += GRAVITY                  * deltaTime;
    }
}