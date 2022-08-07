# Development Techniques Project - Sokoban

Project in C langage done for the course "Development Techniques" at the UFR Mathématique et Informatique in Strasbourg.

[Subject of the project in French](https://techdevprintemps2022.pages.unistra.fr/TP_TechDevEnonce/sokoban/enonce_tp1.html)

### Version gcc
+ gcc version 9.4.0

## Getting Started

### Installation

- **To compile the projet, launch this command in the terminal:**

```
make
```

- **To launch the program with a console interface type this command in the terminal:**

```
./sokoban
```

### Program Flow

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


### Some commands

## To generate the html documentation

```
make doc
```

## To clean the project directory

```
make clean
```

**NB** : deletes the binary files, executable, html repository, .tar.gz file.

## To generate an archive

```
make archive
```

**NB** : An archive containing the c, h and txt files, Makefile, README and Doxyfile will be created.


## Author

**Justine Andreolli**  _alias_ [@jandreolli](https://github.com/jandreolli)


