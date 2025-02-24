/**
 * @file Transform.hpp
 * @author Joachim Perrin (joachimperrin1@gmail.com)
 * @brief This file contains the definition of the Transform class, which is a component that allows entities to have a position, a velocity, a size, a scale, a rotation and a torque.
 * @version 0.1
 * @date 2025-02-24
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "ECS.hpp"
#include "Vector2.hpp"

#include <SDL2/SDL.h>

namespace ecs
{
    /**
     * @brief The Transform class is a component that allows entities to have a position, a velocity, a size, a scale, a rotation and a torque.
     *
     */
    class Transform : public Component
    {
    public:
        Transform();
        Transform(Vector2 pos, Vector2 vel = {0.0f, 0.0f}, Vector2 siz = {1.0f, 1.0f}, Vector2 sca = {1.0f, 1.0f}, float rot = 0.0f, float tor = 0.0f);

        void Init() override;
        void Update() override;

        Vector2 GetPos() const;
        Vector2 GetVel() const;
        Vector2 GetSize() const;
        Vector2 GetScale() const;
        float GetRot() const;
        float GetTor() const;

        void SetPos(Vector2 pos);
        void SetVel(Vector2 vel);
        void SetSize(Vector2 siz);
        void SetScale(Vector2 sca);
        void SetRot(float rot);
        void SetTor(float tor);

        friend class KeyboardController;
        friend class Projectile;

    private:
        Vector2 position;
        Vector2 velocity;
        Vector2 size;
        Vector2 scale;
        float rotation;
        float torque;
    };
}

#endif