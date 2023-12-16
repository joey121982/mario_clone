#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#ifdef _WIN32
#define SDL_MAIN_HANDLED
#endif

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "utilities.hpp"

const int     GAME_WIDTH        = 1920;
const int     GAME_HEIGHT       = 1080;
const float   PLAYER_WIDTH      = 45;
const float   PLAYER_HEIGHT     = 90;

namespace MarioClone
{
    class Player
    {
        private:
            Orientation orientation = RIGHT;
            SDL_Rect playerRect;

        public:
            Player();
            ~Player();
            void move(Orientation dir, float speed);
            void jump(float speed);
            SDL_Rect getRect();

            float verticalVelocity = 0;
            bool grounded = true;

            Vector2 position;
            float width  = PLAYER_WIDTH;
            float height = PLAYER_HEIGHT;
    };

    class Platform
    {
        private:
            SDL_Rect platformRect;
        public:
            Platform();
            Platform(float x, float y, float w, float h);
            ~Platform();
            SDL_Rect getRect();

            Vector2 position    = Vector2();
            float width         = GAME_WIDTH;
            float height        = GAME_HEIGHT;
    };

    class Game
    {
    private:
        void clean();

        std::vector<Platform> platformList;

        float   screensizeadjust;
        bool    isRunning;
        
        const float   GRAVITY           = 0.003;
        const float   PLAYER_SPEED      = 0.75;

        SDL_Window*     window;
        SDL_Renderer*   renderer;

        Player player = Player();

    public:
        Game();
        ~Game();
        /**
         * @brief Initializes the game window and renderer
         * @param title The title of the window
         * @param xpos The x position of the window
         * @param ypos The y position of the window
         * @param width The width of the window
         * @param height The height of the window
         * @param fullscreen Whether or not the window should be fullscreen
        */
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        
        /**
         * @brief Handles events such as key presses and checks for movement
        */
        void handleEvents();
        
        /**
         * @brief Updates the game state
        */
        void update();
        
        /**
         * @brief Renders the game
        */
        void render();
        
        /**
         * @brief Checks if the game is running
        */
        bool running();

        /**
         * @brief The amount of time it took to render the last frame
        */
        float deltaTime = 0.0f;
    };
}

#endif // DEFINITIONS_HPP