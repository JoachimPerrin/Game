#include "GoManager.hpp"
#include "Game.hpp"
#include "Transform.hpp"
#include "Collider.hpp"
#include "Sprite.hpp"
#include "Projectile.hpp"
#include "Stat.hpp"
#include "Label.hpp"
#include "KeyboardController.hpp"
#include "FSM.hpp"
#include "ComponentManager.hpp"
#include "Utils.hpp"

ecs::Entity * GoManager::CreatePlayer()
{
    auto& player(Game::manager.AddEntity());
    player.AddComponent<ecs::Transform>(Vector2(500.0f, 700.0f), Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2(3.0f, 3.0f));
    player.AddComponent<ecs::Sprite>("Robot", true);
    //player.AddComponent<ecs::KeyboardController>();
    player.AddComponent<ecs::Stat>();
    player.AddComponent<ecs::CircularCollider>("Robot");

    //FSM
    // TODO: Matrice des transitions pour le joueur
    std::array<std::array<PlayerState,nbPlayerInputs>,nbPlayerStates> transitions = {{
        //I_MOVE                           I_INVENTORY                        I_ATTACK                          I_NONE
        { PlayerState::S_RUNNING_JOUEUR,   PlayerState::S_INVENTORY_JOUEUR,   PlayerState::S_IDLE_JOUEUR,       PlayerState::S_IDLE_JOUEUR},    // Etat IDLE
        { PlayerState::S_RUNNING_JOUEUR,   PlayerState::S_INVENTORY_JOUEUR,   PlayerState::S_RUNNING_JOUEUR,    PlayerState::S_IDLE_JOUEUR},    // Etat RUNNING
        { PlayerState::S_INVENTORY_JOUEUR, PlayerState::S_IDLE_JOUEUR,        PlayerState::S_INVENTORY_JOUEUR,  PlayerState::S_INVENTORY_JOUEUR}    // Etat INVENTAIRE 
    }};

    // Table des actions pour le joueur
    //TODO: VOIR SI JOEUR 1 OU 2 PR SAVOIR QUEL KEYS DONNEE
    //Joueur 1

    std::array<std::array<std::function<void()>,nbPlayerInputs>,nbPlayerStates> actions = {{

        { [&player]() { ecs::ComponentManager::JoueurMouvement(keysP1, player); },      [&player]() {ecs::ComponentManager::InventaireOpen(player);},   [&player]() {ecs::ComponentManager::Tir(keysP1,player); }, [&player]() {ecs::ComponentManager::JoueurStopMouvement(player); }},  // IDLE
        { [&player]() { ecs::ComponentManager::JoueurMouvement(keysP1, player); },      [&player]() {ecs::ComponentManager::InventaireOpen(player);},   [&player]() {ecs::ComponentManager::Tir(keysP1,player); }, [&player]() {ecs::ComponentManager::JoueurStopMouvement(player); }},  // RUNNING, /* additional arguments */
        { []() {},                                                                      [&player]() {ecs::ComponentManager::InventaireClose(player); }, []() {},    []() {}}  // INVENTAIRE

    }};
    player.AddComponent<ecs::FSM<PlayerState, PlayerInput, nbPlayerStates, nbPlayerInputs>>(
        PlayerState::S_IDLE_JOUEUR,  // État initial (ici, exemple pour un joueur)
        transitions,        // Matrice des transitions
        actions             // Table des actions
    );

    player.AddGroup(Game::players);
    player.AddGroup(Game::controllables);
    return &player;
}

void GoManager::CreateProjectile(Vector2 position, Vector2 velocity, int range, int speed, ecs::ProjectileType type)
{
    auto &projectile(manager->AddEntity());
    projectile.AddComponent<ecs::Transform>(Vector2(position.x, position.y), Vector2(speed, speed), Vector2(32, 32), Vector2(1, 1));
    projectile.AddComponent<ecs::Sprite>("projectile", true);
    if (type == ecs::hostileProjectile)
    {
        projectile.GetComponent<ecs::Sprite>().Play("HostileBullet");
    }
    else if (type == ecs::allyProjectile)
    {
        projectile.GetComponent<ecs::Sprite>().Play("AllyBullet");
    }
    else if (type == ecs::chargedProjectile)
    {
        projectile.GetComponent<ecs::Sprite>().Play("ChargedBullet");
    }
    projectile.AddComponent<ecs::CircularCollider>("projectile");
    projectile.AddComponent<ecs::Projectile>(range, velocity, type);
    projectile.AddGroup(Game::projectiles);
    projectile.AddGroup(Game::controllables);
}

void GoManager::CreateEnemy(Vector2 position, ecs::EnemyType type)
{
    auto &enemy(manager->AddEntity());
    enemy.AddComponent<ecs::Transform>(Vector2(position.x, position.y), Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2(3.0f, 3.0f));
    enemy.AddComponent<ecs::Sprite>("enemy", true);
    enemy.AddComponent<ecs::Stat>();
    if (type == ecs::bat)
    {
        enemy.GetComponent<ecs::Sprite>().Play("Bat");
        enemy.AddComponent<ecs::CircularCollider>("Bat");
    }
    else if (type == ecs::spider)
    {
        enemy.GetComponent<ecs::Sprite>().Play("Spider");
        enemy.AddComponent<ecs::CircularCollider>("Spider");
    }
    else if (type == ecs::snake)
    {
        enemy.GetComponent<ecs::Sprite>().Play("Snake");
        enemy.AddComponent<ecs::CircularCollider>("Snake");
    }
    enemy.AddGroup(Game::enemies);
    enemy.AddGroup(Game::controllables);
}

void GoManager::CreateLabel(SDL_Rect bbox, std::string text, std::string font)
{
    auto &label(manager->AddEntity());
    label.AddComponent<ecs::Label>(bbox, text, font);
    label.AddGroup(Game::labels);
}