#include "PausedState.hpp"
#include "Game.hpp"
#include <iostream>

PausedState::PausedState()
{
    std::cout << "Creating Paused state" << std::endl;
}

PausedState::~PausedState()
{
    std::cout << "Destroying Paused state" << std::endl;
}

void PausedState::Enter(Game &game)
{
    if (game.IsRunning())
        std::cout << "Entering Paused State" << std::endl;
}

void PausedState::Exit(Game &game)
{
    if (game.IsRunning())
        std::cout << "Exiting Paused State" << std::endl;
}
void PausedState::HandleEvent(Game &game)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT ||
            (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
        {
            game.running = false;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                game.running = false;
                break;
                
            case SDLK_p:
                if (dynamic_cast<PlayingState *>(game.currentState.get()))
                {
                    game.ChangeState(game.pausedState);
                }
                else if (dynamic_cast<PausedState *>(game.currentState.get()))
                {
                    game.ChangeState(game.playingState);
                }
                break;

            case SDLK_r:
                game.ChangeState(game.playingState);
                break;

            default:
                break;
            }
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.clicks >= 2)
                game.ChangeState(game.menuState);
        }
    }
}

void PausedState::Update(Game &game)
{
    if (game.IsRunning())
        return;
}

void PausedState::Render(Game &game)
{
    if (game.IsRunning())
        return;
}
