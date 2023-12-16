#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <SDL2/SDL.h>

const int   FPS               = 60;
const int   frameDelay        = 1000 / FPS;

struct Vector2
{
    float x;
    float y;
};

enum Orientation
{
    LEFT,
    RIGHT
};

namespace MarioClone
{
    class Player
    {
        private:
            Orientation orientation = RIGHT;
            bool grounded = true;

        public:
            Player();
            ~Player();
            void move(Orientation dir, int speed);
            void jump(int speed);
            bool onGround();

            float verticalVelocity = 0;

            Vector2 position;
    };

    class Game
    {
    private:

        float   GRAVITY           = 0.1;
        float   PLAYER_SPEED      = 5;
        float   PLAYER_WIDTH      = 32;
        float   PLAYER_HEIGHT     = 32;

        void clean();
        
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;

        Player player = Player();

    public:
        Game();
        ~Game();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        bool running();
    };
}

#endif