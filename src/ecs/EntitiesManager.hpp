/**
 * @file EntitiesManager.hpp
 * @author Joachim Perrin (joachimperrin1@gmail.com)
 * @brief This file contains the definition of the EntitiesManager class, which is responsible for managing all the entities in the ECS logic.
 * @version 0.1
 * @date 2025-02-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef ENTITIES_MANAGER_HPP
#define ENTITIES_MANAGER_HPP

#include "Entity.hpp"
#include <vector>
#include <memory>

namespace ecs
{
    using Group = std::size_t;
    class Entity;

    /**
     * @brief The EntitiesManager is responsible for managing all the entities in the ECS logic.
     * It contains a list of entities and a list of groups of entities.
     *
     */
    class EntitiesManager
    {
    public:
        void Update();
        void Render();
        void Refresh();

        void AddToGroup(Entity *mEntity, Group mGroup);
        std::vector<Entity *> &GetGroup(Group mGroup);

        Entity &AddEntity();
        void ClearEntities(int mGroup);

    private:
        std::vector<std::unique_ptr<Entity>> entities;
        std::array<std::vector<Entity *>, maxGroups> groupedEntities;
    };
}

#endif
