#include "definitions.hpp"

void MarioClone::Player::move(Orientation dir, float speed)
{
    orientation = dir;
    if (dir == LEFT)
    {
        position.x -= speed;
    }
    else if (dir == RIGHT)
    {
        position.x += speed;
    }
}

void MarioClone::Player::jump(float speed)
{
    verticalVelocity = -speed * 1.5;
    grounded = false;   
}

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