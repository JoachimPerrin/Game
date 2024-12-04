#ifndef GOMANAGER__HPP
#define GOMANAGER__HPP

#include "Vector2.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"

using namespace ecs;
class GOManager
{
public:
    GOManager(EntitiesManager *man) : manager(man) {}

    void CreatePlayer(Entity &player);
    void CreateEnemy(Vector2 position, EnemyType type);
    void CreateProjectile(Vector2 position, Vector2 velocity, int range, int speed, ProjectileType type);
    void CreateLabel(SDL_Rect bbox, std::string text, std::string font);

private:
    EntitiesManager *manager;
};

#endif