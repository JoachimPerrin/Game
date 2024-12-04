#ifndef __UILABELS__
#define __UILABELS__

#include "ECS.hpp"
#include "Transform.hpp"
#include <SDL2/SDL.h>
#include <string>

// static SDL_Color _black = {  0,   0,   0, 255};
// static SDL_Color _red   = {255,   0,   0, 255};
// static SDL_Color _green = {  0, 255,   0, 255};
// static SDL_Color _blue  = {  0,   0, 255, 255};

namespace ecs
{
    /**
     * @brief This component describe a label, it depends on a Transform component
     * @note This class depends on a Transform component, so it is recommended to initialize one first.
     * 
     */
    class Label : public Component
    {
    public:
        Label(SDL_Rect dst, 
              std::string text, 
              std::string font = "Dundalk", 
              SDL_Color color = {255, 255, 255, 255});

        void SetLabelText();

        void Render() override;
        void Update() override {}

        SDL_Rect dstRect;
        SDL_Rect srcRect;
        std::string labelText;
        std::string labelFont;
        SDL_Color textColor;
        SDL_Texture *labelTexture;
    };

    /**
     * @brief Class derived from a Label component specifically to display the score
     * TODO: associer le game pour en extraire le compte du score (ou juste le score est public ou friend?)
     */
    class ScoreLabel : public Label
    {
    public:
        ScoreLabel();
        void Update() override;
    };

    /**
     * @brief Class derived from a Label component specifically to display the game timer
     * 
     */
    class TimerLabel : public Label
    {
    public:
        TimerLabel();
        void Update() override;
    };

    /**
     * @brief Class derived from a Label component specifically to display the player position
     * TODO: associer le joueur pour récupérer la position
     */
    class PositionLabel : public Label
    {
    public:
        PositionLabel();
        void Update() override;
    private:
        Transform *transform;
    };
}
#endif