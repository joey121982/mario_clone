#include "definitions.hpp"

int main(int argc, char* argv[])
{
    uint32_t frameStart;


    int     screenwidth     = 1600;
    int     screenheight    = 900;
    bool    fullscreen      = false;

    // int         FPS         = 120;
    // const int   frameDelay  = 1000 / FPS;

    MarioClone::Game game = MarioClone::Game();
    game.init("Mario Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenwidth, screenheight, fullscreen);

    while(game.running())
    {
        frameStart = SDL_GetTicks();

        game.handleEvents();
        game.update();
        game.render();

        game.deltaTime = SDL_GetTicks() - frameStart;

        // Replaced by using deltaTime for movement and gravity
        // if(frameDelay > game.deltaTime)
        // {
        //     SDL_Delay(frameDelay - game.deltaTime);
        // }
    }

    return 0;
}