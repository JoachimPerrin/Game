#ifndef COLLIDERS_HPP
#define COLLIDERS_HPP

#include "ECS.hpp"
#include "Transform.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <cmath>
#include "Vector2.hpp"

namespace ecs
{
    class Collider : public Component
    {
    public:
        virtual void Init() override;
        virtual void Update() override;

        virtual Vector2 IsColliding(Collider &other) = 0;

        std::string tag;
        Transform *transform;
    };

    class AABBCollider : public Collider
    {
    public:
        AABBCollider(const std::string &t);

        void Init() override;

        // float GetWidth() const { return width; }
        // float GetHeight() const { return height; }

        // void SetWidth(float wid) { width = wid; }
        // void SetHeight(float hei) { height = hei; }

        Vector2 IsColliding(Collider &other) override;
    };

    class CircularCollider : public Collider
    {
    public:
        CircularCollider(const std::string &t);

        void Init() override;

        float GetRadius() const { return radius; }
        Vector2 GetCenter() const { return center; }
        void SetRadius(float rad) { radius = rad; }
        void SetCenter(float x,float y){
            center.x = x;
            center.y = y;
        }
        Vector2 IsColliding(Collider &other) override;

    private:
        float radius = -1;
        Vector2 center;
    };
}
#endif
