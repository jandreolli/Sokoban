#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void move_player(struct Grid *grille, enum Direction dir){
    // declaration of the new variables x and y which we initialize to the current position
    int next_x = grille->playerPosition.x;
    int next_y = grille->playerPosition.y;
    // verify that moving the box is allowed
    int next_next_x = grille->playerPosition.x;
    int next_next_y = grille->playerPosition.y;

    if(dir == TOP){
        next_x -= 1;
        next_next_x -= 2;
    }
    else if(dir == LEFT){
        next_y -= 1;
        next_next_y -= 2;
    }
    else if(dir == RIGHT){
        next_y += 1;
        next_next_y += 2;
    }
    else if(dir == BOTTOM){
        next_x += 1;
        next_next_x += 2;
    }

    if(grille->game_grid[next_x][next_y] == NONE){
        // write in the game_grid array the player's new position
        grille->game_grid[next_x][next_y] = PLAYER;
        // delete the player's former position
        grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = NONE;
        // update the player's new position in the playerPosition structure
        grille->playerPosition.x = next_x;
        grille->playerPosition.y = next_y;
    }
    else if(grille->game_grid[next_x][next_y] == BOX){
        // if there is nothing/goal in front of the bow then we push the box
        if((grille->game_grid[next_next_x][next_next_y] == NONE) || grille->game_grid[next_next_x][next_next_y] == GOAL){
            // write in the game_grid array the player's new position
            grille->game_grid[next_x][next_y] = PLAYER;
            // write in the game_grid array the box's new position
            grille->game_grid[next_next_x][next_next_y] = BOX;
            // erase the player's former position
            grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = NONE;
            // update the player's new position in the playerPosition structure
            grille->playerPosition.x = next_x;
            grille->playerPosition.y = next_y;
        }
    }

}
