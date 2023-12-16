#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <SDL2/SDL.h>

#define GRAVITY         0.1
#define PLAYER_SPEED    5
#define PLAYER_WIDTH    32
#define PLAYER_HEIGHT   32

const int FPS           = 60;
const int frameDelay    = 1000 / FPS;

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
            void move(Orientation dir);
            void jump();
            bool onGround();

            float verticalVelocity = 0;

            struct PositionStruct
            {
                int x;
                int y;
            } position;
    };

    class Game
    {
    private:
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