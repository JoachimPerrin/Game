#ifndef __PROJECTILE__
#define __PROJECTILE__

#include "ECS.hpp"
#include "Vector2.hpp"
#include "Transform.hpp"

namespace ecs
{
    // À remplacer par un délire classe dériviées etc ?
    enum ProjectileType
    {
        allyProjectile,
        hostileProjectile,
        chargedProjectile
    };

    class Projectile : public Component
    {
    public:
        Projectile(int rng = 10.0f, Vector2 vel = {1.0f, 1.0f}, ProjectileType t = allyProjectile);

        void Init() override;
        void Update() override;

        ProjectileType GetType();

    private:
        Transform *transform;
        Vector2 velocity;
        ProjectileType type;
        int range;
        int distance;
        int speed;
    };

    // TODO: se poser la question de ça serieusement
    // class AllyProjectile : public Projectile
    // {};
    // class HostileProjectile : public Projectile
    // {};
}
#endif