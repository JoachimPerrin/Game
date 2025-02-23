/**
 * @file Component.hpp
 * @author Joachim Perrin (joachimperrin1@gmail.com)
 * @brief This file contains the definition of the Component class, which is the most basic unit in the ECS logic.
 * @version 0.1
 * @date 2025-02-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

namespace ecs
{
    class Entity;

    /**
     * @brief A Component is meant to define a specific behavior or property of an Entity.
     * It has a reference to the Entity it is attached to, and can be updated and rendered.
     *
     */
    class Component
    {
    public:
        Entity *entity;

        virtual void Init() {}
        virtual void Update() {}
        virtual void Render() {}

        virtual ~Component() {}
    };
}

#endif