#include "definitions.hpp"

MarioClone::Tilebox::Tilebox(float x, float y)
{
    this->position.x = x;
    this->position.y = y;
    this->TileboxRect.x = x;
    this->TileboxRect.y = y;
    this->TileboxRect.w = TILEBOX_SIZE;
    this->TileboxRect.h = TILEBOX_SIZE;
}

MarioClone::Tilebox::~Tilebox()
{
}

SDL_Rect MarioClone::Tilebox::getRect()
{
    return this->TileboxRect;
}