#include "EntitiesManager.hpp"
#include "ECS.hpp"

#include <algorithm>
namespace ecs
{
    void EntitiesManager::Update()
    {
        for (auto &e : entities)
            e->Update();
    }

    void EntitiesManager::Render()
    {
        for (auto &e : entities)
            e->Render();
    }

    void EntitiesManager::Refresh()
    {
        for (auto i(0u); i < maxGroups; i++)
        {
            auto &v(groupedEntities[i]);
            v.erase(
                std::remove_if(
                    std::begin(v),
                    std::end(v),
                    [i](Entity *mEntity)
                    { return !mEntity->IsActive() || !mEntity->HasGroup(i); }),
                std::end(v));
        }
        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                                      [](const std::unique_ptr<Entity> &mEntity)
                                      {
                                          return !mEntity->IsActive();
                                      }),
                       std::end(entities));
    }

    void EntitiesManager::AddToGroup(Entity *mEntity, Group mGroup)
    {
        groupedEntities[mGroup].emplace_back(mEntity);
    }

    std::vector<Entity *> &EntitiesManager::GetGroup(Group mGroup)
    {
        return groupedEntities[mGroup];
    }

    Entity &EntitiesManager::AddEntity()
    {
        Entity *e = new Entity(*this);
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }

    void EntitiesManager::ClearEntities()
    {
        for (auto &e : entities)
        {
            e->Destroy();
        }
        Refresh(); // Appel de Refresh pour supprimer les entités détruites
    }
}