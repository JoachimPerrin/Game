#include "KeyboardController.hpp"
#include "Game.hpp"
#include "Vector2.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include "Stat.hpp"

namespace ecs
{
    void KeyboardController::Init()
    {
        transform = &entity->GetComponent<Transform>();
        stat = &entity->GetComponent<Stat>();
        sprite = &entity->GetComponent<Sprite>();
    }

    void KeyboardController::Update()
    {
        transform->velocity.x = 0;
        transform->velocity.y = 0;
        sprite->spriteflip = SDL_FLIP_NONE;

        // if (keystates[SDL_SCANCODE_ESCAPE])
        // {
        //     Game::isRunning = false;
        //     return;
        // }

        if (Game::event.type == SDL_KEYDOWN && Game::event.key.keysym.sym == SDLK_j)
        {
            stat->speed = 10;
        }
        if (Game::event.type == SDL_KEYUP && Game::event.key.keysym.sym == SDLK_j)
        {
            stat->speed = 6;
        }

        // Gestion des entrée de mouvement (dans la SDL, les touches sont par défault en qwerty, j'ai annoté les correspondances azerty)
        if (keystates[SDL_SCANCODE_W])
        { // Z -> haut
            transform->velocity.y = -1;
        }
        if (keystates[SDL_SCANCODE_S])
        { // S -> bas
            transform->velocity.y = 1;
        }
        if (keystates[SDL_SCANCODE_D])
        { // D -> droite
            if (keystates[SDL_SCANCODE_W])
            {                                // -> droite + haut
                transform->velocity.x = 0.7; // car sqrt(2x^2) = 1 => x ≈ 0,7
                transform->velocity.y = -0.7;
            }
            else if (keystates[SDL_SCANCODE_S])
            { // -> droite + bas
                transform->velocity.x = 0.7;
                transform->velocity.y = 0.7;
            }
            else
                transform->velocity.x = 1;
        }
        if (keystates[SDL_SCANCODE_A])
        { // Q -> gauche
            sprite->spriteflip = SDL_FLIP_HORIZONTAL;
            if (keystates[SDL_SCANCODE_W])
            { // -> gauche + haut
                transform->velocity.x = -0.7;
                transform->velocity.y = -0.7;
            }
            else if (keystates[SDL_SCANCODE_S])
            { // -> gauche + bas
                transform->velocity.x = -0.7;
                transform->velocity.y = 0.7;
            }
            else
                transform->velocity.x = -1;
        }

        // Gestion du choix de l'animation
        if (keystates[SDL_SCANCODE_W] ||
            keystates[SDL_SCANCODE_S] ||
            keystates[SDL_SCANCODE_D] ||
            keystates[SDL_SCANCODE_A])
            sprite->Play("Walk");
        else
            sprite->Play("Idle");

        // Gestion du tir
        if (keystates[SDL_SCANCODE_L] && entity->GetComponent<Stat>().IsShotReady())
        {
            if (transform->velocity.x == 0 && transform->velocity.y == 0) // puisque je définit le projectile en fonction de la vitesse du perso, il faut que je couvre le cas ou il est immobile
                                                                          // + transform->height / 2 * transform->scale.y
                                                                          // + (1 * 8 + transform->width / 2) * transform->scale.x
                Game::gobjs->CreateProjectile(Vector2(transform->position.x, transform->position.y), 
                                               Vector2(20, 0),
                                               10000, 2, entity->GetComponent<Stat>().GetWeapon());
            else
                Game::gobjs->CreateProjectile(Vector2(transform->position.x,  // + (transform->velocity.x * 8 + transform->width/2) * transform->scale,
                                                       transform->position.y), // + (transform->velocity.y * 8 + transform->height/2) * transform->scale),
                                               Vector2(transform->velocity.x * 20,
                                                       transform->velocity.y * 20),
                                               1000, 2, entity->GetComponent<Stat>().GetWeapon());
            entity->GetComponent<Stat>().SetLastShot();

            // sprite->play("Shoot"); // pas encore animé MDRRRRLOOLOLL
        }

        // changement d'arme
        if (keystates[SDL_SCANCODE_K] && SDL_GetTicks() - lastAction > actionDelay)
        {
            std::cout << "changement d'arme" << std::endl;
            entity->GetComponent<Stat>().ChangeWeapon();
            lastAction = SDL_GetTicks();
        }

        // spawn d'araignée et chauve-souris
        // if (keystates[SDL_SCANCODE_SEMICOLON] && SDL_GetTicks() - lastAction > actionDelay)
        // {
        //     std::cout << "spawn enemies" << std::endl;
        //     Game::gobjs->CreateEnemy(transform->position, spider);
        //     lastAction = SDL_GetTicks();
        // }
    }
}