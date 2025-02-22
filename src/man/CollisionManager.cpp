#include "CollisionManager.hpp"
#include "Game.hpp"

void CollisionManager::GlideCollision(ecs::Entity *entity, Vector2 vec)
{
    if (entity->HasComponent<Transform>())
    {
        entity->GetComponent<Transform>().SetVel(entity->GetComponent<Transform>().GetVel().Project(vec));
    }
}

void CollisionManager::ReboundCollision(ecs::Entity *entity, Vector2 vec)
{
    if (entity->HasComponent<Transform>())
    {
        // Reverse the velocity based on the normal
        entity->GetComponent<Transform>().SetVel(vec*Vector2(0.01,0.01));
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
            if (!col)
                continue; // Check if col is valid
            if (player->HasComponent<Collider>() && col->HasComponent<Collider>())
            {
                vec = player->GetComponent<Collider>().IsColliding(col->GetComponent<Collider>());
                if (vec != nullvect)
                {
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
                    std::cout << "Colliding" << std::endl;
                    ReboundCollision(player, vec);
                }
                std::cout << vec << std::endl;
                std::cout << enemy->GetComponent<CircularCollider>().GetCenter() << std::endl;
            }
            else
            {
                std::cout << "No collider" << std::endl;
            }
            
        }
    }
    // for (auto &enemy : enemies)
    // {
    //     for (auto &player : players)
    //     {
    //         if (!enemy)
    //             continue; // Check if enemy is valid
    //         if (enemy->HasComponent<CircularCollider>() && player->HasComponent<CircularCollider>())
    //         {
    //             vec = enemy->GetComponent<CircularCollider>().IsColliding(player->GetComponent<CircularCollider>());
    //             if (vec != nullvect)
    //             {
    //                 std::cout << "Colliding" << std::endl;
    //                 ReboundCollision(enemy, vec);
    //             }
    //             std::cout << vec << std::endl;
    //             std::cout << player->GetComponent<CircularCollider>().GetCenter() << std::endl;
    //         }
    //         else
    //         {
    //             std::cout << "No collider" << std::endl;
    //         }
            
    //     }
    // }

}
