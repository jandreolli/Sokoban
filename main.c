#include <stdio.h>
#include "grid.h"
#include "sdl2.h"
#include <stdbool.h>

int main(void){
	// creation of a Grid type structure
	struct Grid grille;

	// initialize sdl2
	sdl_init();
	
	// call the init_level function to allocate the structure array and fill it 
	init_level("level1.txt", &grille);
	
	// display with sdl2
	//display_sdl2(&grille);

	// display the level
	//display(&grille);

	// call the function display_sdl2(&grille) with the function pointers
	void (*handle_display)(struct Grid *grille) = &display_sdl2;

	// call the function eventsdl2() with the function pointers
	Event (*handle_event)() = &event_sdl2;

	bool run = true;
	while(run){
		Event key = handle_event();
		
		// if all the GOALS have a BOX on them, we get out of the game loop
		if(grille.nbCiblePoints_covered == grille.nbCiblePoints){
			key = Quit;
		}

		switch(key){
			case Up :
				move_player(&grille, TOP);
				break;
			case Down :
				move_player(&grille, BOTTOM);
				break;
			case Left :
				move_player(&grille, LEFT);
				break;
			case Right :
				move_player(&grille, RIGHT);
				break;
			case None:
				break;
			case Quit :
				run = false;
				break;
			default:
				break;
		}
		handle_display(&grille);
		// display the grid on the terminal
		//display(&grille);
		// display the grid with sdl2
		//display_sdl2(&grille);
	}
	// free the game_grid array of the Grid structure 
	freeArray(&grille);
	// quit sdl2
	sdl_quit();
}


