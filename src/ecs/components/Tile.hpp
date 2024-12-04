#ifndef __TILE__
#define __TILE__

#include "ECS.hpp"
#include "Vector2.hpp"
#include <string>
#include <SDL2/SDL.h>

//FIXME: eventuellement passer par un transform component plutôt que position?
namespace ecs
{
    class Tile : public Component
    {
    public:
        SDL_Texture *texture;
        SDL_Rect srcRect;
        SDL_Rect destRect;
        Vector2 position;

        Tile(int srcX, int srcY, int xpos, int ypos, int tSize, int tScale, const std::string id);

        void Update() override;
        void Render() override;
    };
}

#endif