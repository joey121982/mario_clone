#include "definitions.hpp"

void MarioClone::Game::update()
{
    if(!player.onGround())
    {
        player.position.y += player.verticalVelocity;
        player.verticalVelocity += GRAVITY;
    }
}