#include "CollisionManager.hpp"
#include "ComponentManager.hpp"
#include "Game.hpp"

void CollisionManager::GlideCollision(ecs::Entity *entity, Vector2 vec)
{
    // std::cout << "vec : " << vec << std::endl;
    if (entity->HasComponent<ecs::Transform>())
    {
        // std::cout << vec << std::endl;
        Vector2 normal = vec.Normal();
        // std::cout << normal << std::endl;
        Vector2 vel = entity->GetComponent<ecs::Transform>().GetVel();
        // std::cout << vel << std::endl;
        // std::cout << "Projection  : " << vel.Project(vel, vec) << std::endl;
        if (vel.Project(vel, vec).x * vec.x > 0 || vel.Project(vel, vec).y * vec.y > 0)
        {
            // std::cout << "Vel :" << vel << "Vel projeté" << vel.Project(vel, normal) << std::endl;
            ecs::ComponentManager::EntitySetVelocity(*entity, vel.Project(vel, normal));
            // entity->GetComponent<ecs::Transform>().SetVel(vel.Project(vel, normal));
        }
    }
}

void CollisionManager::ReboundCollision(ecs::Entity *entity, Vector2 vec)
{
    if (entity->HasComponent<ecs::Transform>())
    {
        // Reverse the velocity based on the normal
        if ((vec * Vector2(0.01, 0.01)).magnitude() > 0.3)
        {
            //TODO: ComponentManager
            entity->GetComponent<ecs::Transform>().SetVel(vec * Vector2(0.005, 0.005));
        }
        // else
        // {
        //     entity->GetComponent<ecs::Transform>().SetVel(Vector2(0, 0));
        // }
    }
}

void CollisionManager::ProjectileCollision(ecs::Entity *entity)
{
    if (entity->HasComponent<ecs::Stat>())
    {
        entity->Destroy();
    }
}

void CollisionManager::Update(ecs::EntitiesManager &EMan)
{
    std::vector<ecs::Entity *> colidable = EMan.GetGroup(Game::collidable);
    std::vector<ecs::Entity *> players = EMan.GetGroup(Game::players);
    std::vector<ecs::Entity *> enemies = EMan.GetGroup(Game::enemies);
    std::vector<ecs::Entity *> projectiles = EMan.GetGroup(Game::projectiles);
    Vector2 nullvect = Vector2(0, 0);
    Vector2 vec;

    for (auto &player : players)
    {
        if (!player)
            continue; // Check if player is valid
        for (auto &col : colidable)
        {
            if (player->HasComponent<ecs::CircularCollider>() && col->HasComponent<ecs::AABBCollider>())
            {
                vec = player->GetComponent<ecs::CircularCollider>().IsColliding(col->GetComponent<ecs::AABBCollider>());
                if (vec != nullvect)
                {

                    // std::cout << "Collision" << std::endl;
                    GlideCollision(player, vec);
                }
            }
        }
        for (auto &enemy : enemies)
        {
            if (player->HasComponent<ecs::CircularCollider>() && enemy->HasComponent<ecs::CircularCollider>())
            {
                vec = player->GetComponent<ecs::CircularCollider>().IsColliding(enemy->GetComponent<ecs::CircularCollider>());
                if (vec != nullvect)
                {
                    ReboundCollision(player, vec);
                }
            }
        }
    }
    for (auto &enemy : enemies)
    {
        for (auto &player : players)
        {
            if (!enemy)
                continue; // Check if enemy is valid
            if (enemy->HasComponent<ecs::CircularCollider>() && player->HasComponent<ecs::CircularCollider>())
            {
                vec = enemy->GetComponent<ecs::CircularCollider>().IsColliding(player->GetComponent<ecs::CircularCollider>());
                if (vec != nullvect)
                {
                    ReboundCollision(enemy, vec);
                    if (player->HasComponent<ecs::Stat>())
                    {
                        player->GetComponent<ecs::Stat>().Hurt(1);
                    }
                }
            }
        }
        for (auto &col : colidable)
        {
            if (enemy->HasComponent<ecs::CircularCollider>() && col->HasComponent<ecs::AABBCollider>())
            {
                vec = enemy->GetComponent<ecs::CircularCollider>().IsColliding(col->GetComponent<ecs::AABBCollider>());
                if (vec != nullvect)
                {
                    // std::cout << "Collision" << std::endl;
                    GlideCollision(enemy, vec);
                }
            }
        }
    }
    for (auto &projectile : projectiles)
    {
        for (auto &enemy : enemies)
        {
            if (projectile->HasComponent<ecs::CircularCollider>() && enemy->HasComponent<ecs::CircularCollider>())
            {
                vec = projectile->GetComponent<ecs::CircularCollider>().IsColliding(enemy->GetComponent<ecs::CircularCollider>());
                if (vec != nullvect)
                {
                    projectile->Destroy();
                    if (enemy->HasComponent<ecs::Stat>())
                    {
                        enemy->GetComponent<ecs::Stat>().Hurt(10);
                    }
                }
            }
        }
        for (auto &col : colidable)
        {
            if (projectile->HasComponent<ecs::CircularCollider>() && col->HasComponent<ecs::AABBCollider>())
            {
                vec = projectile->GetComponent<ecs::CircularCollider>().IsColliding(col->GetComponent<ecs::AABBCollider>());
                if (vec != nullvect)
                {
                    projectile->Destroy();
                }
            }
        }
    }
}
