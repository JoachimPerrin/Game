#include "CollisionManager.hpp"
#include "Game.hpp"

void CollisionManager::GlideCollision(ecs::Entity *entity, Vector2 vec)
{
    std::cout << "vec : "<< vec << std::endl;
    if (entity->HasComponent<Transform>())
    {
        std::cout << vec << std::endl;
        Vector2 normal = vec.Normal();
        std::cout << normal << std::endl;
        Vector2 vel = entity->GetComponent<Transform>().GetVel();
        std::cout << vel << std::endl;
        std::cout << "Projection  : " <<  vel.Project(vel, vec) << std::endl;
        if (vel.Project(vel, vec).x * vec.x > 0 || vel.Project(vel, vec).y*vec.y > 0)
        {
            std::cout << "Vel :" << vel << "Vel projeté" << vel.Project(vel, normal) <<  std::endl;
            entity->GetComponent<Transform>().SetVel(vel.Reflect(vel, normal));
        }
    }
}

void CollisionManager::ReboundCollision(ecs::Entity *entity, Vector2 vec)
{
    if (entity->HasComponent<Transform>())
    {
        // Reverse the velocity based on the normal
        if ((vec * Vector2(0.01, 0.01)).magnitude() > 0.3)
        {
            entity->GetComponent<Transform>().SetVel(vec * Vector2(0.005, 0.005));
        }
        else
        {
            entity->GetComponent<Transform>().SetVel(Vector2(0, 0));
        }
    }
}

void CollisionManager::Update(ecs::EntitiesManager &EMan)
{
    std::vector<Entity *> colidable = EMan.GetGroup(Game::collidable);
    std::vector<Entity *> players = EMan.GetGroup(Game::players);
    std::vector<Entity *> enemies = EMan.GetGroup(Game::enemies);
    Vector2 nullvect = Vector2(0, 0);
    Vector2 vec;

    for (auto &player : players)
    {
        for (auto &col : colidable)
        {
            if (player->HasComponent<CircularCollider>() && col->HasComponent<AABBCollider>())
            {
                vec = player->GetComponent<CircularCollider>().IsColliding(col->GetComponent<AABBCollider>());
                if (vec != nullvect)
                {
                    std::cout << "Collision" << std::endl;
                    GlideCollision(player, vec);
                }
            }
        }
        for (auto &enemy : enemies)
        {
            if (player->HasComponent<CircularCollider>() && enemy->HasComponent<CircularCollider>())
            {
                vec = player->GetComponent<CircularCollider>().IsColliding(enemy->GetComponent<CircularCollider>());
                if (vec != nullvect)
                {
                    ReboundCollision(player, vec);
                }
            }
        }
        for (auto &enemy : enemies)
        {
            for (auto &player : players)
            {
                if (!enemy)
                    continue; // Check if enemy is valid
                if (enemy->HasComponent<CircularCollider>() && player->HasComponent<CircularCollider>())
                {
                    vec = enemy->GetComponent<CircularCollider>().IsColliding(player->GetComponent<CircularCollider>());
                    if (vec != nullvect)
                    {
                        ReboundCollision(enemy, vec);
                    }
                }
            }
        }
    }
}