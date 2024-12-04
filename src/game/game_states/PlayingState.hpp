#ifndef PLAYINGSTATE_HPP
#define PLAYINGSTATE_HPP

#include "GameState.hpp"
#include "MapManager.hpp"
#include "CollisionManager.hpp"
#include "Entity.hpp" 
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
    
    bool Execute(const PlayingActions action);

    static MapManager *mapManager;
    static SDL_Rect camera;

    PlayingStates currentState = S_SOLO; //TODO: Voir comment integrer S_IDLE

private:
    int score = 0;
    static const int nbStates = 2; //Propre a playingState TODO: a changer en fonction des modes a rjouter
    // static const int nbInputs = 2; //Propre a playingState
    //TODO: Rajouter variable isDay
    

    //TODO: A remplir en fonction du switch entre jour et nuit et IDLE
    // PlayingStates transitions[nbStates][nbInputs] = {
    //     //I_PAUSE       I_QUIT
    //     {previousState, S_IDLE},    // S_PAUSE
    //     {S_PAUSE,       S_IDLE},    // S_DAY
    //     {S_DAY,         S_IDLE}     // S_IDLE
 
    // };

    PlayingActions actions[nbStates][nbGeneralInputs] = {
    //  I_SPACE     I_P         I_MOVE_P1       I_MOVE_P2       I_LEFT          I_RIGHT         I_E      
        {A_JUMP,    A_NONE,     A_MOVE_P1,      A_NONE,        A_NONE,         A_NONE,         A_NONE}, // S_SOLO
        {A_JUMP,    A_NONE,     A_MOVE_P1,      A_MOVE_P2,        A_NONE,         A_NONE,         A_NONE}  // S_MULTI
    };

};

#endif
