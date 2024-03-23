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

bool Utilities::isInLine(SDL_Rect a, SDL_Rect b)
{
    int marginoferror = 4;
    
    // a is always the wider Rect
    if(a.w > b.w) std::swap(a, b);

    if(a.x + a.w + marginoferror < b.x) return false; // if a is to the left of b
    if(a.x > b.x + b.w + marginoferror) return false; // if a is to the right of b

    return true;
}


bool Utilities::isIntersectingOnlyHorizontally(SDL_Rect a, SDL_Rect b)
{
    if(a.y > b.y && a.y < b.y + b.h) return false; // top of a is inside b
    if(a.y + a.h > b.y && a.y + a.h < b.y + b.h) return false; // bottom of a is inside b

    return isInLine(a, b);
}

bool Utilities::checkCollision(const SDL_Rect &A, const SDL_Rect &B )
{
    return SDL_HasIntersection(&A, &B);
}