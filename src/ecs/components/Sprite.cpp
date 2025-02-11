#include "Sprite.hpp"
#include "Transform.hpp"
#include "TextureManager.hpp"
#include "PlayingState.hpp"
#include "Game.hpp"

namespace ecs
{
    Sprite::Sprite(std::string id, bool isAnimated = false)
    : animated(isAnimated)
    {
        if(isAnimated)
        {
            if (id == "Robot")
            {
                Animation walk = Animation(0, 20, 50);
                Animation idle = Animation(1, 20, 150);
                animations.emplace("Idle", idle);
                animations.emplace("Walk", walk);
                Play("Idle");
            }
            else if (id == "projectile")
            {
                Animation allyBullet = Animation(0, 10, 40);
                Animation hostileBullet = Animation(1, 10, 40);
                Animation chargedBullet = Animation(2, 8, 40);
                animations.emplace("AllyBullet", allyBullet);
                animations.emplace("HostileBullet", hostileBullet);
                animations.emplace("ChargedBullet", chargedBullet);
                Play("ChargedBullet");
            }
            else if (id == "enemy")
            {
                Animation bat = Animation(0, 4, 100);
                Animation spider = Animation(1, 5, 100);
                Animation snake = Animation(2, 7, 100);
                Animation purple = Animation(3, 7, 100);
                animations.emplace("Bat", bat);
                animations.emplace("Spider", spider);
                animations.emplace("Snake", snake);
                animations.emplace("Purple", purple);
                Play("Bat");
            }
        }
        SetTexture(id);
    }

    void Sprite::Init()
    {
        transform = &entity->GetComponent<Transform>();
        srcRect = { 0,
                    0,
                    static_cast<int>(transform->GetSize().x),
                    static_cast<int>(transform->GetSize().y) };
    }

    void Sprite::Update()
    {
        if (animated)
        {
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frame);
            srcRect.y = animIndex * transform->GetSize().y;
        }
        destRect.x = static_cast<int>(transform->GetPos().x) - PlayingState::camera.x;
        destRect.y = static_cast<int>(transform->GetPos().y) - PlayingState::camera.y;
        destRect.w = transform->GetSize().x * transform->GetScale().x;
        destRect.h = transform->GetSize().y * transform->GetScale().y;
    }

    void Sprite::SetTexture(std::string id)
    {
        std::cout << id << std::endl;
        texture = Game::assets->GetTexture(id);
        if (texture == nullptr)
            std::cout << "attention, le sprite de " << id << " n'est pas chargé" << std::endl;
    }

    void Sprite::Render()
    {
        TextureManager::Render(texture, srcRect, destRect, spriteflip);
    }

    void Sprite::Play(const std::string animName)
    {
        frame = animations[animName].frame;
        speed = animations[animName].speed;
        animIndex = animations[animName].index;
    }
}