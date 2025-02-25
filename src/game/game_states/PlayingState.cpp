#include "PlayingState.hpp"
#include "Transform.hpp"
#include "Collider.hpp"
#include "Game.hpp"
#include <iostream>

SDL_Rect PlayingState::camera = {0, 0, Window_W, Window_H};
MapManager *PlayingState::mapManager = new MapManager();
CollisionManager *collisions = new CollisionManager();
auto &players(Game::manager.GetGroup(Game::players));
auto &enemy(Game::manager.GetGroup(Game::enemies));
auto &tiles(Game::manager.GetGroup(Game::maps));
auto &collidables(Game::manager.GetGroup(Game::collidable));
auto &projectiles(Game::manager.GetGroup(Game::projectiles));
ecs::Entity *Player;

PlayingState::PlayingState()
{
    std::cout << "ajout de la map\n"
              << std::endl;
    mapManager->AddMap("LobbyMap", "assets/maps/TMLobby.txt", 25, 20);
    std::cout << "\nmap ajouté" << std::endl;
    mapManager->LoadMap("LobbyMap", "LobbyTileSet");
    // TODO: bien faire les initialisations nécessaire ici
}

PlayingState::~PlayingState()
{
    Game::manager.ClearEntities(-1);
    delete mapManager;
    delete collisions;
    std::cout << "score : " << score << std::endl
              << "Destroying Playing state" << std::endl;
}

void PlayingState::Enter(Game &game)
{
    // TODO: quelques initialisation devraient peut-être apparaître ici
    if (game.IsRunning())
    {
        std::cout << "Entering Playing State" << std::endl;
        Player = Game::gobjs->CreatePlayer();
        Game::gobjs->CreateEnemy(Vector2(400.0f, 600.0f), ecs::spider);
    }
}

void PlayingState::Exit(Game &game)
{
    // TODO: sûrement des trucs à faire ici aussi
    Game::manager.ClearEntities(Game::players);
    Game::manager.ClearEntities(Game::enemies);
    Game::manager.ClearEntities(Game::projectiles);
    std::cout << "Exiting Playing State" << std::endl;
    if (game.IsRunning())
        return;
}

void PlayingState::HandleEvent(Game &game)
{
    // TODO: implémenter les gestions d'evenements ici
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT ||
            (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
        {
            game.running = false;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                game.running = false;
                break;

            case SDLK_p:
                if (dynamic_cast<PlayingState *>(game.currentState.get()))
                {
                    game.ChangeState(game.pausedState);
                }
                else if (dynamic_cast<PausedState *>(game.currentState.get()))
                {
                    game.ChangeState(game.playingState);
                }
                break;

            case SDLK_r:
                game.ChangeState(game.playingState);
                break;

            default:
                break;
            }
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.clicks >= 2)
                game.ChangeState(game.pausedState);
        }
    }
}

void PlayingState::Update(Game &game)
{
    // TODO: ajouter la logique d'update ici
    if (game.IsRunning())
    {
        collisions->Update(Game::manager);
        Game::manager.Refresh();
        Game::manager.Update();
        if (!Player->IsActive())
        {
            game.ChangeState(game.playingState);
        }
        // else
        // {
        //     Player->Update();
        // }

        // Caméra centrée sur le joueur
        camera.x = Player->GetComponent<ecs::Transform>().GetPos().x - (Window_W - Player->GetComponent<ecs::Transform>().GetSize().x) / 2; // camera.w/2
        camera.y = Player->GetComponent<ecs::Transform>().GetPos().y - (Window_H - Player->GetComponent<ecs::Transform>().GetSize().y) / 2;

        // Caméra limitée par la bordure de la map
        if (camera.x < 0)
            camera.x = 0;
        if (camera.y < 0)
            camera.y = 0;
        if (camera.x > mapManager->GetCurrentMap()->GetBounds().x - camera.w)
            camera.x = mapManager->GetCurrentMap()->GetBounds().x - camera.w;
        if (camera.y > mapManager->GetCurrentMap()->GetBounds().y - camera.h)
            camera.y = mapManager->GetCurrentMap()->GetBounds().y - camera.h;
    }
}

void PlayingState::Render(Game &game)
{
    // TODO: ajouter les affichages ici (l'ordre est important)
    if (game.IsRunning())
    {
        for (auto &t : tiles)
        {
            t->Render();
        }
        for (auto &p : players)
        {
            p->Render();
        }
        for (auto &e : enemy)
        {
            e->Render();
        }
        for (auto &p : projectiles)
        {
            p->Render();
        }

        // for (auto &c : collidables)
        // {
        //     c->Render();
        // }
    }
}
