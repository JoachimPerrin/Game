#ifndef PAUSEDSTATE_HPP
#define PAUSEDSTATE_HPP

#include "GameState.hpp"
#include <memory>

class Game;

class PausedState : public GameState
{
public:
    PausedState();
    ~PausedState() override;

    void Enter(Game &game) override;
    void Exit(Game &game) override;
    void HandleEvent(Game &game) override;
    void Update(Game &game) override;
    void Render(Game &game) override;

private:
};

#endif
