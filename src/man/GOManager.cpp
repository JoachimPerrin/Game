#include "GOManager.hpp"
#include "Game.hpp"
#include "Transform.hpp"
#include "Collider.hpp"
#include "Sprite.hpp"
#include "Projectile.hpp"
#include "Stat.hpp"
#include "Label.hpp"
#include "KeyboardController.hpp"

void GOManager::CreatePlayer(Entity &player)
{
    player.AddComponent<ecs::Transform>(Vector2(500.0f, 700.0f), Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2(3.0f, 3.0f));
    player.AddComponent<ecs::Sprite>("Player", true);
    player.AddComponent<ecs::KeyboardController>();
    player.AddComponent<ecs::Stat>();
    player.AddComponent<ecs::CircularCollider>("Player");
    player.AddGroup(Game::players);
}

void GOManager::CreateProjectile(Vector2 position, Vector2 velocity, int range, int speed, ProjectileType type)
{
    auto &projectile(manager->AddEntity());
    projectile.AddComponent<Transform>(Vector2(position.x, position.y), Vector2(speed, speed), Vector2(32, 32), Vector2(1, 1));
    projectile.AddComponent<Sprite>("projectile", true);
    if (type == hostileProjectile)
    {
        projectile.GetComponent<Sprite>().Play("HostileBullet");
    }
    else if (type == allyProjectile)
    {
        projectile.GetComponent<Sprite>().Play("AllyBullet");
    }
    else if (type == chargedProjectile)
    {
        projectile.GetComponent<Sprite>().Play("ChargedBullet");
    }
    projectile.AddComponent<CircularCollider>("projectile");
    projectile.AddComponent<Projectile>(range, velocity, type);
    projectile.AddGroup(Game::projectiles);
}

void GOManager::CreateEnemy(Vector2 position, EnemyType type)
{
    auto &enemy(manager->AddEntity());
    enemy.AddComponent<Transform>(Vector2(position.x, position.y), Vector2(0.0f, 0.0f), Vector2(3.0f, 3.0f));
    enemy.AddComponent<Sprite>("enemy", true);
    enemy.AddComponent<Stat>();
    if (type == bat)
    {
        enemy.GetComponent<Sprite>().Play("Bat");
        enemy.AddComponent<CircularCollider>("Bat");
    }
    else if (type == spider)
    {
        enemy.GetComponent<Sprite>().Play("Spider");
        enemy.AddComponent<CircularCollider>("Spider");
    }
    else if (type == snake)
    {
        enemy.GetComponent<Sprite>().Play("Snake");
        enemy.AddComponent<CircularCollider>("Snake");
    }
    enemy.AddGroup(Game::enemies);
}

void GOManager::CreateLabel(SDL_Rect bbox, std::string text, std::string font)
{
    auto &label(manager->AddEntity());
    label.AddComponent<Label>(bbox, text, font);
    label.AddGroup(Game::labels);
}