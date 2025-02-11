# Game Title
Joachim Perrin - Rami Aridi - Grigor Pelibossian

Licenses : SDL2

## Installation

First install SDL2 + image + ttf + mix ...

### Installation de SDL2

#### MacOs
```bash
brew install sdl2 sdl2_ttf sdl2_image sdl2_mixer
```

#### Ubuntu

```bash
apt-get update && apt-get install g++ build-essential make
```

```bash
apt-get update && apt-get install libsdl2-2.0-0 libsdl2-image-2.0-0 libsdl2-ttf-2.0-0 libsdl2-mixer-2.0-0
```

### Binary
En gros, juste installer le binaire correspondant à la distro cible?

#### MacOs
#### Linux

### From sources

```bash
    cd /Path/to/the/folder/you/want/this/project/in
    git clone https://github.com/JoachimPerrin/Game.git
    cd Game
    make run
```

## Explication du projet
Texte explicatif du projet

![imageClasse](out/uml/classe/classes.png?raw=true  "diagramme uml de classe pour expliquer l'ECS")  

(il faudra probablement représenter l'ECS, puis les manager, puis un exemple comme player dans des diagrammes séparés)

![imageSequence](out/uml/sequence/Players.png?raw=true  "diagramme uml de séquences pour expliquer le déroulement du jeu")  

Pas la bonne image, juste pour montrer que c'est possible


![imageEtat](out/uml/etat/Players.png?raw=true  "diagramme uml d'etat pour expliquer les GameStates")  
Explication de l'image ci-dessus


## Gameplay