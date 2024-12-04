#include "Label.hpp"
#include "Vector2.hpp"
#include "AssetsManager.hpp"
#include "Game.hpp"

#include <SDL2/SDL_ttf.h>

namespace ecs
{
    Label::Label(SDL_Rect dst, std::string text, std::string font, SDL_Color color)
        : dstRect(dst), labelText(text), labelFont(font), textColor(color)
    {
        SetLabelText();
    }

    void Label::SetLabelText()
    {
        SDL_Surface *surface = TTF_RenderText_Blended(Game::assets->GetFont(labelFont), labelText.c_str(), textColor);
        if (surface == NULL)
        {
            std::cout << "Erreur de render du text : " << SDL_GetError() << std::endl;
            return;
        }
        labelTexture = SDL_CreateTextureFromSurface(Game::renderer, surface);
        if (labelTexture == NULL)
        {
            std::cout << "Erreur de création de texture à partir du text : " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
            return;
        }
        int width, height;
        if (SDL_QueryTexture(labelTexture, nullptr, nullptr, &width, &height))
        {
            std::cout << "Erreur de récupération des dimensions du text : " << SDL_GetError() << std::endl;
        }
        srcRect = {0, 0, width, height};
        SDL_FreeSurface(surface);
    }

    void Label::Render()
    {
        SDL_RenderCopy(Game::renderer, labelTexture, &srcRect, &dstRect);
    }

    void TimerLabel::Update()
    {
        labelText = "Chrono : " + std::to_string(SDL_GetTicks() / 1000);
        SetLabelText();
    }
    
    void PositionLabel::Update()
    {
        //TODO: update selon la position du joueur
    }
}