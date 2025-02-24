#ifndef PLAYINGSTATE_HPP
#define PLAYINGSTATE_HPP

#include "GameState.hpp"
#include "MapManager.hpp"
#include "CollisionManager.hpp"
#include <memory>

class Game;

class PlayingState : public GameState
{
public:
    PlayingState();
    ~PlayingState();

    void Enter(Game &game) override;
    void Exit(Game &game) override;
    void HandleEvent(Game &game) override;
    void Update(Game &game) override;
    void Render(Game &game) override;

    static MapManager *mapManager;
    static SDL_Rect camera;

private:
    int score = 0;
};

#endif
