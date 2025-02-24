/**
 * @file Collider.hpp
 * @author Dilhan Emir (dilhan77120@gmail.com)
 * @author Joachim Perrin (joachimperrin1@gmail.com)
 * @brief This file contains the definition of the Collider class, which is a component that allows entities to have a collision box.
 * @version 0.1
 * @date 2025-02-24
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef COLLIDERS_HPP
#define COLLIDERS_HPP

#include "ECS.hpp"
#include "Transform.hpp"
#include <SDL2/SDL.h>
#include <string>

namespace ecs
{
    /**
     * @brief The Collider class is a component that allows entities to have a collision box. This is the base for different shapes of colliders.
     *
     */
    class Collider : public Component
    {
    public:
        virtual void Init() override;
        virtual void Update() override;
        virtual bool IsColliding(Collider &other) = 0;

        std::string tag;
        Transform *transform;
    };

    /**
     * @brief The AABBCollider class is a collider that represents an Axis-Aligned Bounding Box.
     *
     */
    class AABBCollider : public Collider
    {
    public:
        AABBCollider(const std::string &t);

        void Init() override;

        float GetWidth() const { return width; }
        float GetHeight() const { return height; }

        void SetWidth(float wid) { width = wid; }
        void SetHeight(float hei) { height = hei; }

        bool IsColliding(Collider &other) override;

    private:
        float width = -1;
        float height = -1;
    };

    /**
     * @brief The CircularCollider class is a collider that represents a circle.
     *
     */
    class CircularCollider : public Collider
    {
    public:
        CircularCollider(const std::string &t);

        void Init() override;

        float GetRadius() const { return radius; }
        void SetRadius(float rad) { radius = rad; }

        bool IsColliding(Collider &other) override;

    private:
        float radius = -1;
    };
}
#endif
