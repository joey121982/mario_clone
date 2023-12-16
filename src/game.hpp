#include <SDL2/SDL.h>
#ifndef GAME_HPP
#define GAME_HPP

namespace MarioClone
{
    class Game
    {
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running();

    private:
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
    };
}

#endif