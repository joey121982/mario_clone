#include "definitions.hpp"

/**
 * @brief Moves the player in a given direction with a given speed
 * 
 * @param direction 
 * @param speed 
 */
void MarioClone::Player::move(Orientation direction, float speed)
{
    orientation = direction;

    if(std::abs(horizontalVelocity) > MAX_PLAYER_SPEED) return;

    if (direction == LEFT)
    {
        horizontalVelocity -= speed * 0.002;
    }
    else if (direction == RIGHT)
    {
        horizontalVelocity += speed * 0.002;
    }
}

/**
 * @brief Makes the player jump with a given speed
 * 
 * @param speed
 */
void MarioClone::Player::jump(float speed)
{
    verticalVelocity = -speed * 1.5;
    grounded = false;   
}

/**
 * @brief Returns the player's rectangle
 * 
 * @return SDL_Rect 
 */
SDL_Rect MarioClone::Player::getRect()
{
    return playerRect;
}

MarioClone::Player::Player()
{
    position.x = 0;
    position.y = 0;
}

MarioClone::Player::~Player()
{
}