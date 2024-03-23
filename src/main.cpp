#include "definitions.hpp"

int main(int argc, char* argv[])
{
    uint32_t frameStart;

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

    if(DEBUG_MODE) SDL_Delay(20000);
    return 0;
}