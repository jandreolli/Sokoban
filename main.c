#include <stdio.h>
#include "grid.h"
#include <stdbool.h>

int main(void){
	// creation of a Grid type structure
	struct Grid grille;
	// call the init_level function to allocate the structure array and fill it 
	init_level("level1.txt", &grille);
	// display the level
	display(&grille);
	// free the game_grid array of the Grid structure 
	freeArray(&grille);
	
	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'q' :{
				run = false;
				break;
			}
		}
	}
}

