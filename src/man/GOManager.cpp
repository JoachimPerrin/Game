#include "GoManager.hpp"
#include "Game.hpp"
#include "Transform.hpp"
#include "Collider.hpp"
#include "Sprite.hpp"
#include "Projectile.hpp"
#include "Stat.hpp"
#include "Label.hpp"
#include "KeyboardController.hpp"

void GOManager::CreatePlayer(ecs::Entity &player)
{
    player.AddComponent<ecs::Transform>(Vector2(500.0f, 700.0f), Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2(3.0f, 3.0f));
    player.AddComponent<ecs::Sprite>("Robot", true);
    player.AddComponent<ecs::KeyboardController>();
    player.AddComponent<ecs::Stat>();
    player.AddComponent<ecs::CircularCollider>("Robot");
    player.AddGroup(Game::players);
}

void GOManager::CreateProjectile(Vector2 position, Vector2 velocity, int range, int speed, ecs::ProjectileType type)
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
}

void GOManager::CreateEnemy(Vector2 position, ecs::EnemyType type)
{
    auto &enemy(manager->AddEntity());
    enemy.AddComponent<ecs::Transform>(Vector2(position.x, position.y), Vector2(0.0f, 0.0f), Vector2(3.0f, 3.0f));
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
}

void GOManager::CreateLabel(SDL_Rect bbox, std::string text, std::string font)
{
    auto &label(manager->AddEntity());
    label.AddComponent<ecs::Label>(bbox, text, font);
    label.AddGroup(Game::labels);
}