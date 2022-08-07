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
	
	
	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'h' :{
				move_player(&grille, entry);
				display(&grille);
				break;
			}
			case 'j' :{
				move_player(&grille, entry);
				display(&grille);
				break;
			}
			case 'k' :{
				move_player(&grille, entry);
				display(&grille);
				break;
			}
			case 'l' :{
				move_player(&grille, entry);
				display(&grille);
				break;
			}
			case 'q' :{
				// free the game_grid array of the Grid structure 
				freeArray(&grille);
				run = false;
				break;
			}
		}
	}
}


