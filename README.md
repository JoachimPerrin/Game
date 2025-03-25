# ByteQuest IV : Piston Pété  
Joachim Perrin - Dilhan Emir - Rami Aridi - Grigor Pelibossian

## Installation

### Essentials
```bash
apt-get update && apt-get install g++ build-essential make
```

### SDL2
#### MacOs
```bash
brew install sdl2 sdl2_ttf sdl2_image sdl2_mixer
```

#### Ubuntu

```bash
apt-get update && apt-get install libsdl2-2.0-0 libsdl2-image-2.0-0 libsdl2-ttf-2.0-0 libsdl2-mixer-2.0-0
```

### Installation du jeu

```bash
    cd /Path/to/the/folder/you/want/this/project/in
    git clone https://github.com/JoachimPerrin/Game.git
    cd Game
    make
```
Puis, il est possible de le lancer avec 
```bash
make run
```

## Explication du projet
Voici ci-dessous les points clefs que nous avons développés

### ECS

![imageEtat](out/.png?raw=true  "diagramme uml d'etat pour expliquer les GameStates")  
Explication de l'image ci-dessus

### FSM
![imageClasse](out/puml/[Classe]FSM_Player/[Classe]FSM_Player.png?raw=true  "diagramme uml de classe pour expliquer l'ECS")  
Explication de l'image ci-dessus

![imageSequence](out/puml/[State]FSM_Player/[State]FSM_Player.png?raw=true  "diagramme uml de séquences pour expliquer le déroulement du jeu")  
Explication de l'image ci-dessus

