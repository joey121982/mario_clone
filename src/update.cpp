#include "definitions.hpp"

/**
 * @brief Checks if two rectangles are in line with each other
 * 
 * @param a The first rectangle
 * @param b The second rectangle
 * @return true 
 * @return false 
 */
bool isInLine(SDL_Rect a, SDL_Rect b)
{
    int marginoferror = 4;
    
    // a is always the wider Rect
    if(a.w > b.w) std::swap(a,b);

    if(a.x + a.w + marginoferror < b.x) return false; // if a is to the left of b
    if(a.x > b.x + b.w + marginoferror) return false; // if a is to the right of b

    return true;
}

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

    // dont let player fall through object
    for (auto &objectRect : collisionObjects)
    {
        if(!isInLine(playerRect, objectRect)) continue;
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
        player.verticalVelocity += GRAVITY                  * deltaTime;
        player.position.y       += player.verticalVelocity  * deltaTime;
    }

    if(player.grounded)
    {
    }

    if(player.horizontalVelocity > 0)
        player.horizontalVelocity -= GRAVITY * FRICTION_CONSTANT * deltaTime;
    else
        player.horizontalVelocity += GRAVITY * FRICTION_CONSTANT * deltaTime;

    player.position.x += player.horizontalVelocity;
}