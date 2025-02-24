#include "AssetsManager.hpp"
#include "TextureManager.hpp"
#include <iostream>

using namespace ecs; // à retirer éventuellement
/**
 * @brief Construct a new Asset Manager:: Asset Manager object
 *
 */
AssetManager::AssetManager() {}

/**
 * @brief Destroy the Asset Manager:: Asset Manager object.
 * Clean the textures and fonts maps
 */
AssetManager::~AssetManager()
{
    for (auto &pair : textures)
    {
        std::cout << "Libération de la texture " << pair.first << std::endl;
        SDL_Texture *texture = pair.second;
        SDL_DestroyTexture(texture);
    }
    textures.clear();
    for (auto &pair : fonts)
    {
        std::cout << "Libération de la police " << pair.first << std::endl;
        TTF_Font *font = pair.second;
        TTF_CloseFont(font);
    }
    fonts.clear();
}

/**
 * @brief Add a texture to the asset manager
 *
 * @param id string ID to be given to the texture
 * @param path string path from the root folder to the image file
 */
void AssetManager::AddTexture(std::string id, std::string path)
{
    textures.emplace(id, TextureManager::LoadTexture(path));
    std::cout << "allocation de la texture " << id << std::endl;
}

/**
 * @brief Get the texture object
 *
 * @param id string ID of the texture to be retrieved
 * @return SDL_Texture*
 */
SDL_Texture *AssetManager::GetTexture(std::string id)
{
    if (textures.find(id) != textures.end())
    {
        return textures[id];
    }
    std::cout << "sprite not found" << std::endl;
    return nullptr;
}

/**
 * @brief Add a font to the asset manager
 *
 * @param id string ID to be given to the font
 * @param path string path from the root folder to the font file
 * @param fontSize int size of the font
 */
void AssetManager::AddFont(std::string id, const std::string path, int fontSize)
{
    TTF_Font *font = TTF_OpenFont(path.c_str(), fontSize);
    if (font == NULL)
    {
        std::cout << "error loading font" << std::endl;
    }
    fonts.emplace(id, font);
    std::cout << "allocation de la police " << id << std::endl;
}

/**
 * @brief Get the font object
 *
 * @param id string ID of the font to be retrieved
 * @return TTF_Font*
 */
TTF_Font *AssetManager::GetFont(std::string id)
{
    return fonts[id];
}
