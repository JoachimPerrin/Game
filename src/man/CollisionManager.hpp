#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include "ECS.hpp"
#include "Collider.hpp"
#include "EntitiesManager.hpp"
#include "Entity.hpp"
#include "Game.hpp"

class CollisionManager
{
public:
    void Update(ecs::EntitiesManager &EMan);
    void ReboundCollision(ecs::Collider &col1 , ecs::Collider &col2);
    void GlideCollision(ecs::Collider &col1 , ecs::Collider &col2);
};
#endif