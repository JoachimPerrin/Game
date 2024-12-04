#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "ECS.hpp"

// TODO: définir les enemies etc

namespace ecs
{
    typedef enum
    {
        spider,
        snake,
        bat,
    } EnemyType;
    
    class Enemy : public Component
    {
    public:
    private:
    };
    class BatEnemy : public Enemy
    {};
    class SpiderEnemy : public Enemy
    {};
    class SnakeEnemy : public Enemy
    {};
}

#endif  