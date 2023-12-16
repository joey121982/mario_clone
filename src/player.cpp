#include "definitions.hpp"

void MarioClone::Player::move(Orientation dir)
{
    orientation = dir;
    if (dir == LEFT)
    {
        position.x -= PLAYER_SPEED;
    }
    else if (dir == RIGHT)
    {
        position.x += PLAYER_SPEED;
    }
}

void MarioClone::Player::jump()
{
    verticalVelocity = -5;
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