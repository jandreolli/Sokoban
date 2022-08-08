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
    // there is nothing in front of the player's current position
    if(grille->game_grid[next_x][next_y] == NONE){
        // write in the game_grid array the player's new position
        grille->game_grid[next_x][next_y] = PLAYER;
        // delete the player's former position
        grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = NONE;
        // update the player's new position in the playerPosition structure
        grille->playerPosition.x = next_x;
        grille->playerPosition.y = next_y;
    }
    // if the position in front is a GOAL and the player is not already on a GOAL
    else if(grille->game_grid[next_x][next_y] == GOAL && grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] == PLAYER){
        grille->game_grid[next_x][next_y] = PLAYER_GOAL;
        grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = NONE;
        grille->playerPosition.x = next_x;
        grille->playerPosition.y = next_y;
    }
    // if there is a box in front of the player's current position but the player is on a GOAL
    else if(grille->game_grid[next_x][next_y] == BOX && grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] == PLAYER_GOAL && grille->game_grid[next_next_x][next_next_y] == NONE){
        grille->game_grid[next_x][next_y] = PLAYER;
        grille->game_grid[next_next_x][next_next_y] = BOX;
        grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = GOAL;
        grille->playerPosition.x = next_x;
        grille->playerPosition.y = next_y;
    }
    // if there is nothing in front of the player's current position but the player is on a GOAL
    else if(grille->game_grid[next_x][next_y] == NONE && grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] == PLAYER_GOAL){
        grille->game_grid[next_x][next_y] = PLAYER;
        grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = GOAL;
        grille->playerPosition.x = next_x;
        grille->playerPosition.y = next_y;
    }
    // if there is a box in front of the player's current position and the player is not on a GOAL
    else if(grille->game_grid[next_x][next_y] == BOX && grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] == PLAYER){
        // if there is nothing in front of the box, we push the box
        if(grille->game_grid[next_next_x][next_next_y] == NONE){
            grille->game_grid[next_x][next_y] = PLAYER;
            grille->game_grid[next_next_x][next_next_y] = BOX;
            grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = NONE;
            grille->playerPosition.x = next_x;
            grille->playerPosition.y = next_y;
        }
        // if there is a box in front of the GOAL then we increment the cible ponts covered
        else if(grille->game_grid[next_next_x][next_next_y] == GOAL){
            grille->game_grid[next_x][next_y] = PLAYER;
            grille->game_grid[next_next_x][next_next_y] = BOX_OK;
            grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = NONE;
            grille->playerPosition.x = next_x;
            grille->playerPosition.y = next_y;
            // increment the cible points covered
            grille->nbCiblePoints_covered += 1;
        }
    }
    // if we want to move a box which is on a GOAL
    else if(grille->game_grid[next_x][next_y] == BOX_OK){
         // if there is nothing in front of the box, we push the box
        if(grille->game_grid[next_next_x][next_next_y] == NONE && grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] == PLAYER){
            grille->game_grid[next_x][next_y] = PLAYER_GOAL;
            grille->game_grid[next_next_x][next_next_y] = BOX;
            grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = NONE;
            grille->playerPosition.x = next_x;
            grille->playerPosition.y = next_y;
            // we decrement the cible points covered
            grille->nbCiblePoints_covered -= 1;
        }
         // if there is nothing in front of the box but the player is on a GOAL
        else if(grille->game_grid[next_next_x][next_next_y] == NONE && grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] == PLAYER_GOAL){
            grille->game_grid[next_x][next_y] = PLAYER_GOAL;
            grille->game_grid[next_next_x][next_next_y] = BOX;
            grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = GOAL;
            grille->playerPosition.x = next_x;
            grille->playerPosition.y = next_y;
            // decrement the cible points covered
            grille->nbCiblePoints_covered -= 1;
        }
        // if in front of the box there is still a GOAL and the player is not in a GOAL
        else if(grille->game_grid[next_next_x][next_next_y] == GOAL && grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] == PLAYER){
            grille->game_grid[next_x][next_y] = PLAYER_GOAL;
            grille->game_grid[next_next_x][next_next_y] = BOX_OK;
            grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = NONE;
            grille->playerPosition.x = next_x;
            grille->playerPosition.y = next_y;
        }
        // if in front of the bow there is still a GOAL but the player is on a GOAL
        else if(grille->game_grid[next_next_x][next_next_y] == GOAL && grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] == PLAYER_GOAL){
            grille->game_grid[next_x][next_y] = PLAYER_GOAL;
            grille->game_grid[next_next_x][next_next_y] = BOX_OK;
            grille->game_grid[grille->playerPosition.x][grille->playerPosition.y] = GOAL;
            grille->playerPosition.x = next_x;
            grille->playerPosition.y = next_y;
        }
    }
}