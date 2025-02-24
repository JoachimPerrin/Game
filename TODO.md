# Objectifs globaux du jeu
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

Revoir TOUS les fichiers pour :
    laisser uniquement les includes nécessaires
    les faire fonctionner

# À faire au début du projet
Trouver un titre, thème
Graphique : palette + efforts pyxeledit,
Gameplay cool etc

# Idées de tâches à se répartir
- Machine à état (FSM) *(À définir en premier lieu)*

- Système de collisions:  
    - Cirular pour player et enemies ->  collision avec rebond (force normale sur les deux entitées (ajout d'une masse dans les stats?))
    - AABB pour l'environnement -> collisions Circular:AABB avec glissement (force projeté tangeante (amortissement visqueux?))

- Système d'inputs  
    - KeyboardTracking component : permet de stocker les touches actives dans un tableau par exemple  
    - InputManager : selon l'objet, réagit aux inputs

- Système de Widgets  
    
- Multijoueur:  
    Écran Scyndé verticalement
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

- Possibilité de sauvegarder et charger les parties

- Diagrammes UML  
    - de classes pour décrire tout le system d'ecs
    - de séquence pour décrire le déroulement du jeu
    - d'état pour décrire la fsm  

*Avec plantUml + intégration dans le README*

- Mise au propre du projet
    - Rédaction du README.md
    - Maintenance du repo github (important pour le mettre en publique super propre)
    - Debugging avec valgrind/gdb pour checker les memleaks
    - Messages de debug propre *(ajouter un logger in game?)*
    - Licence pour SDL2?
    - Tests avec CTest *(Boost.Test ??)*    
    - Améliorer la DA

# Pour aller loiinnn
- Statistiques de performances
- Utiliser des threads pour bien comprendre (pour quels usages?)
- Publier le jeu??? (ultra propre et brillerait cv)
- Faire en sorte qu'avec docker on puisse tester sur plus de platforms (ajouter des dockerfiles, et des services dans le docker-compose)
- Faire ça en réseau pour multijoueur ??? Réseau avec SDL_net ????
(docker) Créer un stage git ou je récup le projet depuis github et install les dépendances communes aux stages build et devel pour plus rapide
- L'optimiser si vraiment il y a le temps