# Development Techniques Project - Sokoban

Project in C langage done for the course "Development Techniques" at the UFR Mathématique et Informatique in Strasbourg.

[Subject of the project in French](https://techdevprintemps2022.pages.unistra.fr/TP_TechDevEnonce/sokoban/enonce_tp1.html)

### Version gcc
+ gcc version 9.4.0

## Getting Started

### Prerequisites

- Install the SDL2:

```
sudo apt-get install libsdl2-dev
```


### Installation

- **To compile the projet, launch this command in the terminal:**

```
make
```

This command compiles the SDL2, installs the library and compiles the project.

- You have the choice between two interface:
    + _Graphic interface_
    + _Console interface_

- **To launch the program with the graphic interface:**

```
./sokoban --sdl2
```

- **To launch the program with a console interface type this command in the terminal:**

```
./sokoban
```
or
```
./sokoban --console
```

## Play Sokoban

### Game principle

- Sokoban is a game of reflexion. The goal is to put the boxes on the goals.
- The player can only push one box at a time.
- The player can go through the goals.
- The level is won when the player put a box on all the goals.


### Program Flow


+ **Graphic Interface**

- Each colored square represent an element:
    + **dark blue square** : wall
    + **white square** : player
    + **light blue square** : box
    + **yellow square** : goal
    + **brown square** : box on a goal

- The player can move the boxes with the arrow keyboard keys.

- To quit the game, click on the red cross on the right up corner of the window.

![sokoban_graphique](https://user-images.githubusercontent.com/95167842/183390196-5e3299ef-de5d-416a-920c-e1330caae6a7.png)

+ **Console Interface**

- Each symbol represents an element :
    + **#** : wall
    + **@** : player
    + **$** : box
    + **.** : goal where to put a box
    + **\*** : box on a goal
    + **+** : player on a goal

- The player can move by pressing the keys : **h** (_left_), **j** (_down_), **k** (_up_) **l** (_right_). 

- To exit the game, press **q**.

![sokoban_console](https://user-images.githubusercontent.com/95167842/183304169-c05e9632-0c95-4493-9b77-8870247240bb.png)

+ **Endgame message**

- If all the goals have a box on them, the player won and a message is displayed on the terminal.

- If the player quits the game without managing to solve the game, a message will be displayed on the terminal.


### Some commands

## To generate the html documentation

```
make doc
```

## To clean the project directory

```
make clean
```

**NB** : deletes the binary files, executable, html repository, .tar.gz file, install_dir file.

## To generate an archive

```
make archive
```

**NB** : An archive containing the c, h and txt files, Makefile, README, Doxyfile and SDL2 directory will be created.


## Author

**Justine Andreolli**  _alias_ [@jandreolli](https://github.com/jandreolli)


