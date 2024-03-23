#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#ifdef _WIN32
#define SDL_MAIN_HANDLED
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utilities.hpp"

using std::string;

const int           GAME_WIDTH      = 1920;
const int           GAME_HEIGHT     = 1080;
const int           TILEBOX_SIZE    = 100;
const float         PLAYER_WIDTH    = 45;
const float         PLAYER_HEIGHT   = 90;
const string        ASSET_PATH      = "assets/";

const bool          DEBUG_MODE      = true;

namespace MarioClone
{
    const float   GRAVITY           = 0.003;
    const float   PLAYER_SPEED      = 0.75;
    const float   MAX_PLAYER_SPEED  = 0.45;
    const float   FRICTION_CONSTANT = 0.4;

    class Player
    {
        private:
            Orientation orientation = RIGHT;
            SDL_Rect playerRect;

        public:
            Player();
            ~Player();
            void move(Orientation direction, float speed);
            void jump(float speed);
            SDL_Rect getRect();

            float verticalVelocity      = 0;
            float horizontalVelocity    = 0;
            bool grounded = true;

            Vector2 position;
            float width  = PLAYER_WIDTH;
            float height = PLAYER_HEIGHT;
    };

    class Tilebox
    {
        private:
            SDL_Rect TileboxRect;
        public:
            Tilebox(float x, float y);
            ~Tilebox();
            SDL_Rect getRect();
            Vector2 position;
    };

    class Game
    {
    private:
        void clean();

        float   screensizeadjust;
        bool    isRunning;

        SDL_Window*     window;
        SDL_Renderer*   renderer;

        Player player = Player();
        std::vector<SDL_Rect> collisionObjects;

    public:
        Game();
        ~Game();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        bool running();
        float deltaTime;
    };
}

#endif // DEFINITIONS_HPP