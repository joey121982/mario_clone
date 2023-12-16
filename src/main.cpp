#include "game.hpp"

int main(int argc, char* argv[])
{
    MarioClone::Game game;
    game.init("Mario Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, true);
    return 0;
}