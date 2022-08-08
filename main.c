#include <stdio.h>
#include "grid.h"
#include "sdl2.h"
#include <stdbool.h>

int main(void){
	// initialize sdl2
	sdl_init();

	// creation of a Grid type structure
	struct Grid grille;
	
	// call the init_level function to allocate the structure array and fill it 
	init_level("level1.txt", &grille);
	
	// display with sdl2
	display_sdl2(&grille);

	// display the level
	display(&grille);
	
	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		
		// if all the GOALS have a BOX on them, we get out of the game loop
		if(grille.nbCiblePoints_covered == grille.nbCiblePoints){
			entry = 'q';
		}

		switch(entry){
			case 'h' :{
				move_player(&grille, entry);
				display(&grille);
				display_sdl2(&grille);
				break;
			}
			case 'j' :{
				move_player(&grille, entry);
				display(&grille);
				display_sdl2(&grille);
				break;
			}
			case 'k' :{
				move_player(&grille, entry);
				display(&grille);
				display_sdl2(&grille);
				break;
			}
			case 'l' :{
				move_player(&grille, entry);
				display(&grille);
				display_sdl2(&grille);
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
	// quit sdl2
	sdl_quit();
}


