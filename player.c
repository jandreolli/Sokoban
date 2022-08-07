#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void move_player(struct Grid *grille, enum Direction dir){
    // declaration of the new variables x and y which we initialize to the current position
    int next_x = grille->playerPosition.x;
    int next_y = grille->playerPosition.y;

    if(dir == TOP){
        next_x -= 1;
    }
    else if(dir == LEFT){
        next_y -= 1;
    }
    else if(dir == RIGHT){
        next_y += 1;
    }
    else if(dir == BOTTOM){
        next_x +=1;
    }

    if(grille->game_grid[next_x][next_y] == NONE){
        // write in the game_grid array the player's new position
        grille->game_grid[next_x][next_y] = PLAYER;
        // erase the player's old position
        grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = NONE;
        // update the player's new position in the playerPosition structure
        grille->playerPosition.x = next_x;
        grille->playerPosition.y = next_y;
    }

}
