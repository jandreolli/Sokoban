#include "grid.h"
#include "sdl2.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	// retrieve the temrinal input
	int number_arguments = argc;
	char *argv0 = argv[0];
	char *argv1 = argv[1];
	char *sdl2 = "--sdl2";
	char *console ="--console";
	char *sokoban = "./sokoban";

	// c for console and s for sdl2
	char gameDisplay = 'c';

	// initialize the function pointers
	void (*handle_display)(struct Grid *grille) =  NULL;
	Event (*handle_event)() = NULL;
	
	// check if user wants to use console/sdl2
	if(number_arguments == 1){
		if(strcmp(argv0, sokoban) == 0){
		handle_display = &display;
		handle_event = &event;
		}
		else{
		printf("To launch the game : ./sokoban --console or in graphic mode : ./sokoban --sdl2\n");
		}
	}
	else if(number_arguments == 2){
		if(strcmp(argv0, sokoban) == 0 && strcmp(argv1, sdl2) == 0){
			gameDisplay = 's';
			// initialize sdl2
			sdl_init();
			handle_display = &display_sdl2;
			handle_event = &event_sdl2;
		}
		else if(strcmp(argv0, sokoban) == 0 && strcmp(argv1, console) == 0){
			handle_display = &display;
			handle_event = &event;
		}	
		else{
		printf("To launch the game : ./sokoban --console or in graphic mode : ./sokoban --sdl2\n");
		}
	}
	else{
		printf("To launch the game  : ./sokoban --console or in graphic mode : ./sokoban --sdl2\n");
	}

	// To avoid having "core dumped"
	if(handle_display==NULL)
		handle_display=&display_sdl2;
	if(handle_event==NULL)
		handle_event=&event_sdl2;

	// creation structure of type Grid
	struct Grid grille;
	// call function init_level to allocate the structure array and fill it
	init_level("level1.txt", &grille);
	// display the grid in console or graphic mode
	handle_display(&grille);
	// initialize the key to None
	Event key = None;

	bool run = true;
	while(run){
		// if all the GOALS are covered, we go out of the game loop
		if(grille.nbCiblePoints_covered == grille.nbCiblePoints){
			key = Quit;
		}
		// else we retrieve the keyboard key just entered
		else{
			key = handle_event();
		}
		switch(key){
			case Up:
				move_player(&grille, TOP);
				break;
			case Down:
				move_player(&grille, BOTTOM);
				break;
			case Left:
				move_player(&grille, LEFT);
				break;
			case Right:
				move_player(&grille, RIGHT);
				break;
			case None:
				break;
			case Quit:
				run = false;
				break;
			default: 
				break;
		}
		// display update
		handle_display(&grille);
	}
	// free game_grid array of the Grid structure
	freeArray(&grille);
	
	// quit dl2
	if(gameDisplay == 's'){
		sdl_quit();
	}

	// displays on the terminal if the player won
	if(grille.nbCiblePoints_covered == grille.nbCiblePoints){
		printf("Yay ! You won !\n");
	}
	else{
		printf("Too bad...you didn't complete this level..\n");
	}

	return 0;
}
