#include "EntitiesManager.hpp"
#include "ECS.hpp"

#include <algorithm>
#include "Game.hpp"

namespace ecs
{
    /**
     * @brief Update all the entities.
     *
     */
    void EntitiesManager::Update()
    {
        for (auto &e : entities)
            if (e)
            {
                e->Update();
            }
    }

    /**
     * @brief Render all the entities.
     *
     */
    void EntitiesManager::Render()
    {
        for (auto &e : entities)
            if (e)
            {
                e->Render();
            }
    }

    /**
     * @brief Refresh the entities. Remove the entities that are not active or that do not belong to a group.
     *
     */
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

    /**
     * @brief Add an entity to a group.
     *
     * @param mEntity
     * @param mGroup
     */
    void EntitiesManager::AddToGroup(Entity *mEntity, Group mGroup)
    {
        groupedEntities[mGroup].emplace_back(mEntity);
    }

    /**
     * @brief Get a group of entities.
     *
     * @param mGroup
     * @return std::vector<Entity *>&
     */
    std::vector<Entity *> &EntitiesManager::GetGroup(Group mGroup)
    {
        return groupedEntities[mGroup];
    }

    /**
     * @brief Add an entity to the entities list.
     *
     * @return Entity&
     */
    Entity &EntitiesManager::AddEntity()
    {
        Entity *e = new Entity(*this);
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }

    /**
     * @brief Clear all the entities.
     *
     */
    void EntitiesManager::ClearEntities(int mGroup)
    {
        if (mGroup == -1)
        {
            for (auto &e : entities)
            {
                e->Destroy();
            }
        }
        else
        {
            for (auto &e : groupedEntities[mGroup])
            {
                e->Destroy();
            }
        }
        Refresh();
    }
}