#include "definitions.hpp"

int main(int argc, char* argv[])
{
    uint32_t frameStart;
    int frameTime;

    MarioClone::Game game = MarioClone::Game();
    game.init("Mario Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 2560, 1440, true);

    while(game.running())
    {
        frameStart = SDL_GetTicks();

        game.handleEvents();
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    return 0;
}