/**
 * @file GOManager.hpp
 * @author Joachim Perrin (joachimperrin1@gmail.com)
 * @brief This file contains the definition of the GOManager class, which is a class that manages the creation of game objects.
 * @version 0.1
 * @date 2025-02-24
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef GOMANAGER__HPP
#define GOMANAGER__HPP

#include "Vector2.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"

/**
 * @brief The GOManager class is a class that manages the creation of game objects.
 *
 */
class GOManager
{
public:
    GOManager(ecs::EntitiesManager *man) : manager(man) {}

    void CreatePlayer(ecs::Entity &player);
    void CreateEnemy(Vector2 position, ecs::EnemyType type);
    void CreateProjectile(Vector2 position, Vector2 velocity, int range, int speed, ecs::ProjectileType type);
    void CreateLabel(SDL_Rect bbox, std::string text, std::string font);

private:
    ecs::EntitiesManager *manager;
};

#endif