#include "definitions.hpp"

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2::Vector2()
{
    x = 0;
    y = 0;
}

bool Utilities::checkCollision(const SDL_Rect &A, const SDL_Rect &B )
{
    return SDL_HasIntersection(&A, &B);
}