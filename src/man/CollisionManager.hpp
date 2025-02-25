/**
 * @file CollisionManager.hpp
 * @author Dilhan Emir (dilhan77120@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-02-24
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include "ECS.hpp"
#include "Collider.hpp"
#include "EntitiesManager.hpp"
#include "Entity.hpp"
#include "Game.hpp"
#include "PlayingState.hpp"
#include "Stat.hpp"

class CollisionManager
{
public:
    void Update(ecs::EntitiesManager &EMan);
    void ReboundCollision(ecs::Entity *entity, Vector2 vec);
    void GlideCollision(ecs::Entity *entity, Vector2 vec);
    void ProjectileCollision(ecs::Entity *entity);
};
#endif