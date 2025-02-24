#include "Entity.hpp"
#include "ECS.hpp"

namespace ecs
{

    /**
     * @brief Get a new component type id.
     *
     * @return ComponentID The new component type id.
     */
    ComponentID GetNewComponentTypeID()
    {
        static ComponentID lastID = 0u;
        return lastID++;
    }

    /**
     * @brief Construct a new Entity object.
     *
     * @param eManager The EntitiesManager this entity belongs to.
     */
    Entity::Entity(EntitiesManager &eManager)
        : manager(eManager)
    {
    }

    /**
     * @brief Update all the components of the entity.
     *
     */
    void Entity::Update()
    {
        for (auto &c : components)
            c->Update();
    }

    /**
     * @brief Render all the components of the entity.
     *
     */
    void Entity::Render()
    {
        for (auto &c : components)
            c->Render();
    }

    /**
     * @brief Check if the entity is active.
     *
     * @return true
     * @return false
     */
    bool Entity::IsActive() const
    {
        return active;
    }

    /**
     * @brief Disable the entity.
     *
     */
    void Entity::Destroy()
    {
        active = false;
    }

    /**
     * @brief Check if the entity belongs to a group.
     *
     * @param mGroup The group to check.
     * @return true
     * @return false
     */
    bool Entity::HasGroup(Group mGroup)
    {
        return groupBitSet[mGroup];
    }

    /**
     * @brief Add the entity to a group.
     *
     * @param mGroup The group to add the entity to.
     */
    void Entity::AddGroup(Group mGroup)
    {
        groupBitSet[mGroup] = true;
        manager.AddToGroup(this, mGroup);
    }

    /**
     * @brief Remove the entity from a group.
     *
     * @param mGroup The group to remove the entity from.
     */
    void Entity::DelGroup(Group mGroup) { groupBitSet[mGroup] = false; }
}