#ifndef UTILITIES_HPP
#define UTILITIES_HPP

class Vector2
{
public:
    /**
     * @brief Default constructor
     * @param X The x value of the vector
     * @param Y The y value of the vector
    */
    Vector2(float X, float Y);

    /**
     * @brief Default constructor
     * If no values are passed, the vector is initialized to (0, 0)
    */
    Vector2();

    float x;
    float y;
};

enum Orientation
{
    LEFT,
    RIGHT
};

namespace Utilities
{
    bool checkCollision(const SDL_Rect &A, const SDL_Rect &B);
}

#endif // UTILITIES_HPP