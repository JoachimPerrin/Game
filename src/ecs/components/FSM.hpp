#ifndef FSM_HPP
#define FSM_HPP

#include <iostream>
#include <functional>
#include <array>
#include "Utils.hpp"
#include "Component.hpp"

namespace ecs{

// Template de Machine à état générique
template <typename State, typename Input, size_t STATE_COUNT, size_t INPUT_COUNT>
class FSM : public Component {
private:
    State currentState;
    std::array<std::array<State, INPUT_COUNT>, STATE_COUNT> transitions;
    std::array<std::array<std::function<void()>, INPUT_COUNT>, STATE_COUNT> actions;

public:
    FSM(State initialState, 
        const std::array<std::array<State, INPUT_COUNT>, STATE_COUNT>& trans, 
        const std::array<std::array<std::function<void()>, INPUT_COUNT>, STATE_COUNT>& acts)
        : currentState(initialState), transitions(trans), actions(acts) {}

    void handleInput(Input input) {
        int stateIndex = static_cast<int>(currentState);
        int inputIndex = static_cast<int>(input);

        // Exécuter l’action associée
        actions[stateIndex][inputIndex]();

        // Changer d’état
        currentState = transitions[stateIndex][inputIndex];
        // printf("%d\n", currentState);
    }

    State getState() const {
        return currentState;
    }

};

}

#endif // FSM_HPP