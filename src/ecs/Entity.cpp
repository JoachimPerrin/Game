#include "Entity.hpp"
#include "ECS.hpp"

namespace ecs
{

    ComponentID GetNewComponentTypeID()
    {
        static ComponentID lastID = 0u;
        return lastID++;
    }
    
    Entity::Entity(EntitiesManager &mManager)
     : manager(mManager) 
    {}

    void Entity::Update()
    {
        for (auto &c : components)
            c->Update();
    }
    void Entity::Render()
    {
        for (auto &c : components)
            c->Render();
    }

    bool Entity::IsActive() const { return active; }
    void Entity::Destroy() { active = false; }

    bool Entity::HasGroup(Group mGroup) { return groupBitSet[mGroup]; }
    void Entity::AddGroup(Group mGroup)
    {
        groupBitSet[mGroup] = true;
        manager.AddToGroup(this, mGroup);
    }
    void Entity::DelGroup(Group mGroup) { groupBitSet[mGroup] = false; }
}