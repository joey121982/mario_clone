#include "definitions.hpp"

int main(int argc, char* argv[])
{
    uint32_t frameStart;
    
    int     screenwidth     = 1280;
    int     screenheight    = 720;
    bool    fullscreen      = false;

    MarioClone::Game game = MarioClone::Game();
    game.init("Mario Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenwidth, screenheight, fullscreen);

    while(game.running())
    {
        frameStart = SDL_GetTicks();

        game.handleEvents();
        game.update();
        game.render();

        game.deltaTime = SDL_GetTicks() - frameStart;
    }

    return 0;
}