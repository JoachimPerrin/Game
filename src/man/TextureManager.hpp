#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <string>
#include <SDL2/SDL.h>

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const std::string imagePath);
    static void Render(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip);
};

#endif