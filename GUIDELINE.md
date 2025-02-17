# Git (note à suivre)
    - Une Branche = une fonctionnalité
    - On ne code jamais dans le main (le main doit être toujours une version fonctionnelle)
    - Quand une branche est prête et testée on merge dans le main actuel (avec un squash, pour réunir tout les commits en un seul sur le main).
    - Une fois qu'une branche a été merge dans le main, toutes les branches doivent merge (pull) le main et résoudre les conflits pour s'actualiser avec le main:

# Convention
    - TODO.md pour les tâches à faire
    - GUIDELINE.md pour les conventions etc...
    - README.md pour installation, explication (le jeu, les règles.¸comment lancer le jeu...), rapport
    - Commentaire finaux en anglais avec Doxygen
    - Language (fonction, variable, prints etc...) : anglais
    - Extension TODO :, FIXME :
    - Nom de variable??
    - Nom de fonction??

# Notes
    - http://tvaira.free.fr/dev/c/automate.pdf (Machine à état FSM explication)

# Architecture et déroulement du jeu
    - Système de profondeur basique avec deux groupes (underlay, overlay) respectivement render avant et après le joueur
    - Système de craft avec ressources collectable
    - inventaire avec livre de recette
    - Cycle d'invasions de monstres (jour/nuit) pour passer de phases de farming à pve
        * farming = cultiver la terre, gestion du temps pour récup de la bouffe
            manger = vie++
            faim critique = vie--
        * enemies tentent de détruire les culture ou le joueur
    - outils : 
        * hache = récolte bois
        * pioche = récolte ST
        * pelle = cultiver
        * épée = damage cac
        * arc = damage distance
    - entitées non hostile
    - ressources divisée en 3 types :
        * pierre
        * bois
        * terre
    - nourriture diviséé en 2 types :
        * plante
        * viande