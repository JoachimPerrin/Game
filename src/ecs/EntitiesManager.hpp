#ifndef ENTITIES_MANAGER_HPP
#define ENTITIES_MANAGER_HPP

#include "Entity.hpp"
#include <vector>
#include <memory>

namespace ecs
{
    class Entity;

    class EntitiesManager
    {
    public:
        void Update();
        void Render();
        void Refresh();

        void AddToGroup(Entity *mEntity, Group mGroup);
        std::vector<Entity *> &GetGroup(Group mGroup);

        Entity &AddEntity();
        void ClearEntities();

    private:
        std::vector<std::unique_ptr<Entity>> entities;
        std::array<std::vector<Entity *>, maxGroups> groupedEntities;
    };
}

#endif
