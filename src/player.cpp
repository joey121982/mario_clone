#include "definitions.hpp"

void MarioClone::Player::move(Orientation dir, int speed)
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

void MarioClone::Player::jump(int speed)
{
    verticalVelocity = -speed;
    grounded = false;   
}

bool MarioClone::Player::onGround()
{
    return grounded;
}

MarioClone::Player::Player()
{
    position.x = 0;
    position.y = 0;
}

MarioClone::Player::~Player()
{
}