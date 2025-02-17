# URGENT (avant de se lancer dans le projet)

Refaire et tester :
    Projectiles
    Lable
    Enemies
    Colliders (collisions en rebonds pour circular-circular et en glissement pour circular-AABB)

Revoir TOUS les fichiers pour :
    laisser uniquement les includes nécessaires
    les faire fonctionner

# À faire au début du projet

Trouver un titre, thème
Graphique : palette + efforts pyxeledit, 
Gameplay cool etc

# Idées de tâches à se répartir

- Machine à état (FSM)

- Système de collisions: 

    Cirular pour player et enemies ->  collision avec rebond (force normale sur les deux entitées (ajout d'une masse dans les stats?))
    AABB pour l'environnement -> collisions Circular:AABB avec glissement (force projeté tangeante (amortissement visqueux?))

- Multijoueur:

    Deux joueurs asymétriques ie les mouvements sont basés sur l'un, l'autre gravite autour
        
    Exemple : P1 est un robot, P2 est un drone de support
    
    Deux joueurs symétriques ie la camera dézoom pour les inclure tout les deux
    Écran Scyndé
    si deter, faire en sorte que P2 puisse être en réseau

- Système de son avec SDL_mixer

    component
    manager
    ...

- Enemies

    Créer une sorte d'ia basique pour les enemies
    Leur donner une zone (cercle autour d'un point)
    Possible d'en faire des meutes

- Système de widgets (UI)

    Button/Toggle/Slider/Dropdown components (dérivés de Widget?)
    manager pour les utiliser facilement (création du menu etc)

- Différents états de jeu

    Menu
    Pause
    éventuellement d'autres jeux en fait

- Propreté du projet

    Application des conventions, renommage pour cohérence
    Commentaires propres
    
    Diagrammes UML avec plantUml + intégration dans le README
        de classes pour décrire tout le system d'ecs
        de séquence pour décrire le déroulement du jeu
        d'état pour décrire la fsm
    
    Rédaction du README.md
    
    Maintenance du repo github (important pour le mettre en publique super propre)
    
    Debugging avec valgrind/gdb pour checker les memleaks
    
    Messages de debug claire, envoyer
    
    Licence pour SDL2?

- Tests

    Boost.Test ??
    
- Un logger in game???
- La DA


# Pour aller loiinnn
- Statistiques de performances
- Utiliser des threads pour bien comprendre (pour quels usages?)
- Publier le jeu??? (ultra propre et brillerait cv)
- Faire en sorte qu'avec docker on puisse tester sur plus de platforms (ajouter des dockerfiles, et des services dans le docker-compose)
- Faire ça en réseau pour multijoueur ??? Réseau avec SDL_net ????
(docker) Créer un stage git ou je récup le projet depuis github et install les dépendances communes aux stages build et devel pour plus rapide
- L'optimiser si vraiment il y a le temps