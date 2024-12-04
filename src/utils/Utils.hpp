#ifndef UTILS_HPP
#define UTILS_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>


// ==================== FSM =============================

// ...


// ----------- PLAYINGSTATE -----------

const int nbGeneralInputs = 7;
enum GeneralInputs { //Commun à, et utilisé par, tous les handleevent des state globaux (playingState, menuState...). (Keyboard inputs ou autre)
    I_SPACE = 0,
    I_T = 1, //Test 
    I_MOVE_P1 = 2,    
    I_MOVE_P2 = 3,    
    I_LEFT = 4,
    I_E1 = 5,
    I_E2 = 6,
    // I_TIMER = 7
};

// Définition des états de PlayingState
enum PlayingStates { //TODO: METTRE A JOUR pr l'instant se fier uniquement au tableau
    S_SOLO = 0,
    S_MULTI = 1,
    S_IDLE = 2, //Inventaire dans la fsm du joueur
};

// Il faut rajouter les inputs + action pour changer les states de Playing States (OPTIONEL)
// Il faut rajouter matric transition pour Playingstate + matrice action (OPTIONEL)

// enum PlayingInputs { // Pour changer les etats de Playing State
//     I_PAUSE = 0,
//     I_QUIT = 1,
//     I_SWITCH_DAY = 2, 
//     
// };

enum PlayingActions {   // Actions qui son pour les entites (pas pour playing State)
    A_NONE = -1,
    A_MOVE_P1 = 0,
    A_MOVE_P2 = 1,
    A_ATTACK = 4,
    A_JUMP = 5,
    A_RUN = 6,
    A_USE_ITEM = 7,
    A_INVENTORY_OPEN = 8,
    A_INVENTORY_CLOSE = 9
    // A_CRAFT = 11 ...
};

//Il faut avoir acces aux entrées que prend les machines a etat des joueurs (et compononents avec machine a etat)


// ------------ ENTITIES ------------
// États du Joueur
const int nbPlayerStates = 3;
enum PlayerState { S_IDLE_JOUEUR, S_RUNNING_JOUEUR, S_INVENTORY_JOUEUR };

// Entrées du Joueur
const int nbPlayerInputs = 3;
enum PlayerInput { I_MOVE, I_INVENTORY, I_NONE};

// Actions du Joueur
enum PlayerAction { };

// ----------- BOUTTON -----------
// ...
extern SDL_Scancode keysP1[5];

void ExitWithError(const std::string errorMessage, SDL_Window *activeWindow = nullptr, SDL_Renderer *activeRenderer = nullptr);

std::ostream &operator<<(std::ostream &stream, const SDL_Rect &rect);
std::ostream &operator<<(std::ostream &stream, const SDL_FRect &rect);

SDL_Rect FRectToRect(const SDL_FRect &fRect);

#endif