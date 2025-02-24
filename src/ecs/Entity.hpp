/**
 * @file Entity.hpp
 * @author Joachim Perrin (joachimperrin1@gmail.com)
 * @brief This file contains the definition of the Entity class, which is the main object in the ECS logic.
 * @version 0.1
 * @date 2025-02-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component.hpp"
#include <bitset>
#include <array>
#include <vector>
#include <memory>

#define MaxComponents 32
#define MaxGroups 32

namespace ecs
{
    /** @brief A group is a way to categorize entities. */
    using Group = std::size_t;

    constexpr std::size_t maxGroups = MaxGroups;
    constexpr std::size_t maxComponents = MaxComponents;

    /** @brief A bitset representing the groups an entity belongs to. */
    using GroupBitSet = std::bitset<maxGroups>;

    /** @brief A bitset representing the components an entity has. */
    using ComponentBitSet = std::bitset<maxComponents>;

    /** @brief An array of components. */
    using ComponentArray = std::array<Component *, maxComponents>;

    /** @brief A unique identifier for a component. */
    using ComponentID = std::size_t;

    class EntitiesManager;
    class Component;

    ComponentID GetNewComponentTypeID();

    /**
     * @brief Get a new component type id.
     * @note Because this function use a static variable, it will only get a new id the first time it is called for a certain type T.
     *
     * @tparam T The type of the component.
     * @return ComponentID The new component type id.
     */
    template <typename T>
    ComponentID GetComponentTypeID() noexcept
    {
        // static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component"); FIXME: is this line necessary?
        static ComponentID typeID = GetNewComponentTypeID();
        return typeID;
    }

    /**
     * @brief An Entity is the main object in the ECS logic. It contains a list of components and a list of groups it belongs to.
     *
     */
    class Entity
    {
    public:
        Entity(EntitiesManager &eManager);

        void Update();
        void Render();

        bool IsActive() const;
        void Destroy();

        bool HasGroup(Group mGroup);
        void AddGroup(Group mGroup);
        void DelGroup(Group mGroup);

        /**
         * @brief Check if the entity has a component of type T.
         *
         * @tparam T The type of the component to check.
         * @return true
         * @return false
         */
        template <typename T>
        bool HasComponent() const
        {
            return componentBitSet[GetComponentTypeID<T>()];
        }

        /**
         * @brief Add a component of type T to the entity.
         *
         * @tparam T The type of the component to add.
         * @tparam TArgs The type of the arguments to pass to the constructor of the component.
         * @param mArgs The arguments to pass to the constructor of the component.
         * @return T& A reference to the newly created component.
         */
        template <typename T, typename... TArgs>
        T &AddComponent(TArgs &&...mArgs)
        {
            T *c = new T(std::forward<TArgs>(mArgs)...);
            c->entity = this;
            std::unique_ptr<Component> uPtr{c};
            components.emplace_back(std::move(uPtr));

            componentArray[GetComponentTypeID<T>()] = c;
            componentBitSet[GetComponentTypeID<T>()] = true;

            c->Init();
            return *c;
        }

        /**
         * @brief Get the Component object
         *
         * @tparam T The type of the component to get.
         * @return T& A reference to the component of type T.
         */
        template <typename T>
        T &GetComponent() const
        {
            auto ptr = componentArray[GetComponentTypeID<T>()];
            return *static_cast<T *>(ptr);
        }

    private:
        bool active = true;
        EntitiesManager &manager;
        std::vector<std::unique_ptr<Component>> components;
        ComponentArray componentArray;
        ComponentBitSet componentBitSet;
        GroupBitSet groupBitSet;
    };
}

#endif
