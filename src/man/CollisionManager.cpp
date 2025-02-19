#include "CollisionManager.hpp"

void CollisionManager::GlideCollision(ecs::Collider &col1, ecs::Collider &col2)
{
    
}

void CollisionManager::Update(ecs::EntitiesManager &EMan)
{
    std::vector<Entity *> colidable = EMan.GetGroup(Game::collidable);
    std::vector<Entity *> players = EMan.GetGroup(Game::players);
    std::vector<Entity *> enemies = EMan.GetGroup(Game::enemies);
    for (auto &player : players)
    {
        for (auto &col : colidable)
        {
            if (player->GetComponent<Collider>().IsColliding(col->GetComponent<Collider>()))
            {
                GlideCollision(player->GetComponent<Collider>(), col->GetComponent<Collider>());
            }
        }
        for (auto &ennemy : enemies)
        {
            if (player->GetComponent<Collider>().IsColliding(ennemy->GetComponent<Collider>()))
            {
                ReboundCollision(player->GetComponent<Collider>(), ennemy->GetComponent<Collider>());
            }
        }
    }
}
