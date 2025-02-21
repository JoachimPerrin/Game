#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include "ECS.hpp"
#include "Collider.hpp"
#include "EntitiesManager.hpp"
#include "Entity.hpp"
#include "Game.hpp"
#include "PlayingState.hpp"

class CollisionManager
{
public:
    void Update(ecs::EntitiesManager &EMan);
    void ReboundCollision(ecs::Entity * entity,Vector2 vec);
    void GlideCollision(ecs::Entity * entity,Vector2 vec);
};
#endif