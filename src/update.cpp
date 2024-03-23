#include "definitions.hpp"

/**
 * @brief Checks if two rectangles are in line with each other
 * 
 * @param a The first rectangle
 * @param b The second rectangle
 * @return true 
 * @return false 
 */

/**
 * @brief Updates the game state
*/
void MarioClone::Game::update()
{
    player.grounded = false;

    SDL_Rect playerRect = player.getRect();

    playerRect.x = player.position.x;
    playerRect.y = player.position.y;
    playerRect.w = PLAYER_WIDTH;
    playerRect.h = PLAYER_HEIGHT;

    if(player.horizontalVelocity > 0)
        player.horizontalVelocity -= GRAVITY * FRICTION_CONSTANT * deltaTime;
    else
        player.horizontalVelocity += GRAVITY * FRICTION_CONSTANT * deltaTime;

    if (std::abs(player.horizontalVelocity) > 0.03) {
        player.position.x += player.horizontalVelocity;
        playerRect.x = player.position.x;
        for(auto &objectRect : collisionObjects) {
            if(Utilities::isIntersectingOnlyHorizontally(playerRect, objectRect)) {
                player.position.x -= player.horizontalVelocity;
                playerRect.x = player.position.x;
                player.horizontalVelocity = 0;
                break;
            }
        }

    }

    for (auto &objectRect : collisionObjects)
    {
        if(!Utilities::isInLine(playerRect, objectRect)) continue;
        if(Utilities::checkCollision(playerRect, objectRect)) {
            if(player.verticalVelocity = 0) continue;
            else if(player.verticalVelocity > 0 ) {
                player.position.y = objectRect.y - playerRect.h;
                player.verticalVelocity = 0;
                player.grounded = true;
            }
            else {
                player.grounded = false;
            }
        }
    }
    
    // player jump physics
    if(!player.grounded)
    {
        player.verticalVelocity += GRAVITY * deltaTime;
        if(std::abs(player.verticalVelocity) > 0.04)
            player.position.y += player.verticalVelocity * deltaTime;
    }

    if(player.grounded)
    {
    }
}