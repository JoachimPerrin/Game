#ifndef COMPONENT_HPP
#define COMPONENT_HPP

namespace ecs
{
    class Entity;
    
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