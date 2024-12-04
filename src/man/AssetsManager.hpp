#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "ECS.hpp"

using namespace ecs;
class AssetManager
{
public:
    AssetManager();
    ~AssetManager();

    void AddTexture(std::string id, const std::string path);
    SDL_Texture *GetTexture(std::string id);

    void AddFont(std::string id, const std::string path, int fontSize);
    TTF_Font *GetFont(std::string id);

private:
    std::map<std::string, SDL_Texture *> textures;
    std::map<std::string, TTF_Font *> fonts;
};

#endif