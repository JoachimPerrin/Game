#include "Tile.hpp"
#include "TextureManager.hpp"
#include "PlayingState.hpp"
#include "Game.hpp"

namespace ecs
{
    Tile::Tile(int srcX, int srcY, int xpos, int ypos, int tSize, int tScale, const std::string id)
        : srcRect({srcX, srcY, tSize, tSize}), destRect({xpos, ypos, tSize * tScale, tSize * tScale}), position(xpos, ypos)
    {
        texture = Game::assets->GetTexture(id);
    }

    void Tile::Update()
    {
        destRect.x = position.x - PlayingState::camera.x;
        destRect.y = position.y - PlayingState::camera.y;
    }

    void Tile::Render()
    {
        TextureManager::Render(texture, srcRect, destRect, SDL_FLIP_NONE);
    }
}