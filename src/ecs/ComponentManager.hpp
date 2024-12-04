#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP

#include "Entity.hpp"
#include "Transform.hpp"
#include "Stat.hpp"
#include "Sprite.hpp"
#include <functional>
#include <vector>

namespace ecs {

    // Le gestionnaire des actions de composants
    class ComponentManager {
    public:

        // Actions générales
        // =============== JOUEUR ===============================
        static void JoueurMouvement(const SDL_Scancode keys[], Entity &entity);

        static void JoueurStopMouvement(Entity &entity);

        static void InventaireOpen(Entity &entity);

        static void InventaireClose(Entity &entity);

        // Ajout d'autres actions selon les besoins
    };

}

#endif // COMPONENTMANAGER_HPP