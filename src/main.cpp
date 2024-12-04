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

        // Variables d'évaluation de la durée des frames
        int overTime = 0;
        int nbLoop = 0;
        Uint32 frameLimit = 0;
        std::cout << "\nStarting game loop\n"
                  << std::endl;

        // Boucle principale du jeu
        while (game.IsRunning())
        {
            frameLimit = SDL_GetTicks() + FRAME_DELAY;

            game.HandleEvents();
            game.Update();
            game.Render();

            // Contrôle de la durée des frames
            overTime += limitFPS(frameLimit);
            nbLoop++;
        }

        std::cout << "\nGame loop ended\n Proportion of frames that took too long: "
                  << (overTime / nbLoop) << "\n"
                  << std::endl;

        // Libération des ressources
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
 * @brief Fonction de contrôle de la vitesse du programme (FPS)
 *
 * @param frameLimit temps attendu en fin de la boucle actuelle
 * @return 1 si la boucle à durée plus que prévu
 */
int limitFPS(Uint32 frameLimit)
{
    Uint32 now = SDL_GetTicks();
    if (now >= frameLimit) // La boucle à pris trop de temps
    {
        return 1; // Renvoie 1 pour comptabiliser l'erreur
    }
    else if (frameLimit > now + FRAME_DELAY) // Desynchronisation
    {
        SDL_Delay(FRAME_DELAY); // Re-sync
        return 0;
    }
    else
    {
        SDL_Delay(frameLimit - now); // On attends pour passer à la boucle suivante
        return 0;
    }
}
