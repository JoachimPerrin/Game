#ifndef KEYBOARD_CONTROLLER_HPP
#define KEYBOARD_CONTROLLER_HPP

#include "ECS.hpp"
#include <SDL2/SDL.h>
#include "Stat.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"

namespace ecs
{
    class KeyboardController : public Component
    {
    public:
        unsigned int lastAction = SDL_GetTicks();
        unsigned int actionDelay = 500;
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        void Init() override;
        void Update() override;

    private:
        Transform *transform;
        Sprite *sprite;
        Stat *stat;
        int dir;
    };
}
#endif