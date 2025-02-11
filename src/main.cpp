/**
 * @file main.cpp
 * @author Joachim Perrin (joachimperrin1@gmail.com)
 * @brief This file is the entry point of this game, it contains the main loop of the program.
 * @version 0.1
 * @date 2025-02-23
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Game.hpp"
#include <iostream>
#include <SDL2/SDL.h>

#define FPS 30
#define FRAME_DELAY (1000 / FPS)

int limitFPS(Uint32 frameLimit);

int main(void)
{
    try
    {
        Game game;

        // Game loop variables
        int overTime = 0;
        int nbLoop = 0;
        Uint32 frameLimit = 0;

        std::cout << "\nStarting game loop\n"
                  << std::endl;

        // Main loop
        while (game.IsRunning())
        {
            frameLimit = SDL_GetTicks() + FRAME_DELAY;

            // Game logic
            game.HandleEvents();
            game.Update();
            game.Render();

            // Time Control
            overTime += limitFPS(frameLimit);
            nbLoop++;
        }

        std::cout << "\nGame loop ended\n Proportion of frames that took too long: "
                  << (overTime / nbLoop) << "\n"
                  << std::endl;

        // Freeing resources
        game.Cleanup();
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/**
 * @brief Function that limits the frame rate of the game
 *
 * @param frameLimit The time at which the frame should end
 * @return int 1 if the loop took too long, 0 otherwise
 */
int limitFPS(Uint32 frameLimit)
{
    Uint32 now = SDL_GetTicks();
    if (now >= frameLimit) // If the loop took too long
    {
        return 1; // return 1 so that the overTime variable can be incremented
    }
    else if (frameLimit > now + FRAME_DELAY) // If the loop gets unsynced somehow
    {
        SDL_Delay(FRAME_DELAY); // Re-sync
        return 0;
    }
    else // If the loop took the right amount of time
    {
        SDL_Delay(frameLimit - now); // Wait until the frame ends
        return 0;
    }
}
