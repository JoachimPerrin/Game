#include "Collider.hpp"
#include "Transform.hpp"
#include <cmath>

namespace ecs
{
    void Collider::Init()
    {

    }

    // TODO: Is there something to update?
    void Collider::Update()
    {}

    AABBCollider::AABBCollider(const std::string &t)
    {
        tag = t;
    }
    
    void AABBCollider::Init()
    {
        if (!entity->HasComponent<Transform>())
        {
            entity->AddComponent<Transform>();
        }
        transform = &entity->GetComponent<Transform>();
        if (width == -1)
        {
            width = transform->GetSize().x;
            height = transform->GetSize().y;
        }
    }

    bool AABBCollider::IsColliding(Collider& other)
    {
        if (AABBCollider* aabb = dynamic_cast<AABBCollider*>(&other))
        {
            if (aabb->GetWidth() > 0)
                return false;
            // TODO:Logique de collision entre deux AABBCollider
        }
        else if (CircularCollider* circle = dynamic_cast<CircularCollider*>(&other))
        {
            if (circle->GetRadius() > 0)
                return false;
            // TODO:Logique de collision entre un AABBCollider et un CircularCollider
        }
        return false;
    }

    CircularCollider::CircularCollider(const std::string &t)
    {
        tag = t;
    }
    
    void CircularCollider::Init() 
    {
        if (!entity->HasComponent<Transform>())
        {
            entity->AddComponent<Transform>();
        }
        transform = &entity->GetComponent<Transform>();
        if (radius == -1)
            radius = std::sqrt(std::pow(transform->GetSize().x, 2) + std::pow(transform->GetSize().y, 2));
    }

    bool CircularCollider::IsColliding(Collider& other)
    {
        if (AABBCollider* aabb = dynamic_cast<AABBCollider*>(&other))
        {
            if (aabb->GetWidth() > 0)
                return false;
            // TODO:Logique de collision entre deux AABBCollider
        }
        else if (CircularCollider* circle = dynamic_cast<CircularCollider*>(&other))
        {
            if (circle->GetRadius() > 0)
                return false;
            // TODO:Logique de collision entre un AABBCollider et un CircularCollider
        }
        return false;
    }
}