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
    using Group = std::size_t;

    constexpr std::size_t maxGroups = MaxGroups;
    constexpr std::size_t maxComponents = MaxComponents;

    using GroupBitSet = std::bitset<maxGroups>;
    using ComponentBitSet = std::bitset<maxComponents>;
    using ComponentArray = std::array<Component *, maxComponents>;

    class EntitiesManager;
    class Component;

    using ComponentID = std::size_t;

    ComponentID GetNewComponentTypeID();

    template <typename T>
    ComponentID GetComponentTypeID() noexcept
    {
        static ComponentID typeID = GetNewComponentTypeID();
        return typeID;
    }

    class Entity
    {
    public:
        Entity(EntitiesManager &mManager);

        void Update();
        void Render();

        bool IsActive() const;
        void Destroy();

        bool HasGroup(Group mGroup);
        void AddGroup(Group mGroup);
        void DelGroup(Group mGroup);

        template <typename T>
        bool HasComponent() const
        {
            return componentBitSet[GetComponentTypeID<T>()];
        }

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
