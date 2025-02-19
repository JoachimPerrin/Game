#include "Collider.hpp"
#include "Transform.hpp"

namespace ecs
{
    void Collider::Init()
    {
    }

    void Collider::Update()
    {
    }

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
    }

    Vector2 AABBCollider::IsColliding(Collider &other)
    {
        if (AABBCollider *aabb = dynamic_cast<AABBCollider *>(&other))
        {
            if (aabb->transform->GetPos().x + aabb->transform->GetSize().x > transform->GetPos().x)
            {
                Vector2 vec;
                return vec;
            }
            // TODO:Logique de collision entre deux AABBCollider
        }
        else if (CircularCollider *circle = dynamic_cast<CircularCollider *>(&other))
        {
            if (circle->GetRadius() > 0)
            {
                Vector2 vec;
                return vec;
            }
            // TODO:Logique de collision entre un AABBCollider et un CircularCollider
        }
        Vector2 vec;
        return vec;
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
            radius = std::max(transform->GetSize().x, transform->GetSize().y) / 2;
        SetCenter(transform->GetPos().x + transform->GetSize().x / 2, transform->GetPos().y + transform->GetSize().y / 2);
    }

    Vector2 CircularCollider::IsColliding(Collider &other)
    {
        Vector2 posA = transform->GetPos();
        Vector2 sizeA = transform->GetSize();
        if (AABBCollider *aabb = dynamic_cast<AABBCollider *>(&other))
        {
            Vector2 posB = aabb->transform->GetPos();

            return (posA.x < posB.x + aabb->transform->GetSize().x &&
                    posA.x + sizeA.x > posB.x &&
                    posA.y < posB.y + aabb->transform->GetSize().y &&
                    posA.y + transform->GetSize().y > posB.y);
        }
        else if (CircularCollider *circle = dynamic_cast<CircularCollider *>(&other))
        {
            Vector2 posB = circle->transform->GetPos();
            float closestX = std::max(posA.x, std::min(posB.x, posA.x + aabb->transform->GetSize().x));
            float closestY = std::max(posA.y, std::min(posB.y, posA.y + transform->GetSize().y));

            float dx = posB.x - closestX;
            float dy = posB.y - closestY;
            return (dx * dx + dy * dy) < (circle->GetRadius() * circle->GetRadius());
        }

        return false;
    }
}