#ifndef COLLIDERS_HPP
#define COLLIDERS_HPP

#include "ECS.hpp"
#include "Transform.hpp"
#include <SDL2/SDL.h>
#include <string>

namespace ecs
{
    class Collider : public Component
    {
    public:
        virtual void Init() override;
        virtual void Update() override;

        virtual bool IsColliding(Collider& other) = 0;

        std::string tag;
        Transform *transform;
    };

    class AABBCollider : public Collider
    {
    public:
        AABBCollider(const std::string& t);
        
        void Init() override;

        float GetWidth() const { return width; }
        float GetHeight() const { return height; }

        void SetWidth(float wid) { width = wid; }
        void SetHeight(float hei) { height = hei; }

        bool IsColliding(Collider& other) override;

    private:
        float width = -1;
        float height = -1;
    };

    class CircularCollider : public Collider
    {
    public:
        CircularCollider(const std::string& t);

        void Init() override;

        float GetRadius() const { return radius; }
        void SetRadius(float rad) { radius = rad; }

        bool IsColliding(Collider& other) override;


    private:
        float radius = -1;
    };
}
#endif
