#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <SDL2/SDL.h>

#include "ECS.hpp"
#include "PlayingState.hpp"
#include "PausedState.hpp"
#include "MenuState.hpp"
#include "AssetsManager.hpp"
#include "GOManager.hpp"

const int Window_H = 1200;
const int Window_W = 1600;
class PlayingState;

class Game
{
public:
    Game();
    ~Game() { Cleanup(); }

    void Cleanup();
    void HandleEvents();
    void Update();
    void Render();

    void ChangeState(std::shared_ptr<GameState> newState);

    bool IsRunning() const;

    friend class PlayingState;
    friend class PausedState;
    friend class MenuState;

    // FIXME: à voir pour le passer en PlayingState mais labels/widget utile pour tous en réalité (peut-être possible de le scinder en plusieurs parties)
    enum GroupEnum : std::size_t
    {
        collidable,
        projectiles,
        labels,
        widgets,
        enemies,
        players,
        maps,
    };

    static SDL_Renderer *renderer;
    static AssetManager *assets;
    static GOManager *gobjs;
    static ecs::EntitiesManager manager;
    static SDL_Event event;

private:
    void InitSDL();
    void InitWindow(const std::string &title, int width, int height, SDL_bool fullscreen);
    void InitRenderer();
    void Initialize();

    std::shared_ptr<GameState> currentState;

    std::shared_ptr<PlayingState> playingState;
    std::shared_ptr<PausedState> pausedState;
    std::shared_ptr<MenuState> menuState;

    SDL_Window *window;
    bool running;
};

#endif
