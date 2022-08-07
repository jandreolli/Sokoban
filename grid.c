#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void init_level(const char* file_path, struct Grid *grille){ // add parameter struct Grid *grille
	// opening of the file in reading mode
	FILE* file = fopen(file_path, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}
	char line[100] = {0};
	int number_column = 0; // number of columns
	int number_row = 0; /// number of lines
	int number_goals = 0;
	// read the first line of the file
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
	
	// write the number of columns and rows in the Grid structure
	grille->column_number = number_column;
	grille->row_number = number_row;

	int current_row = 0;
	//int current_goal = 0;

	// allocate memory for the game_grid array
	grille->game_grid = malloc(sizeof(enum CaseType*)*(grille->row_number));
	for (int i = 0; i < grille->row_number; i++){
		grille->game_grid[i] = malloc(sizeof(enum CaseType*)*(grille->column_number));
	}

	// read the file line by line until the end of the file
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;
		while(*buffer && *buffer != '\n'){
			// fill the game_grid array with the symbols contained in the .txt file
			grille->game_grid[current_row][current_column] = *buffer;

			// if meet the player symbol then (x,y) = [current_row][current_column] 
			if(*buffer == '@'){
				grille->playerPosition.x = current_row;		// x = row
				grille->playerPosition.y = current_column;	// y = column
			}

			// increment to access the next symbol
			current_column += 1;
			buffer += 1;
		}		
		current_row += 1;
	}
	// file closing
	fclose(file);
}

void freeArray(struct Grid *grille){
	for(int i = 0; i < grille->row_number; i++){
		free(grille->game_grid[i]);
	}
	free(grille->game_grid);
}

void display(struct Grid *grille){
	for(int i = 0; i < grille->row_number; i++){
		for(int j = 0; j < grille->column_number; j++){
			printf("%c", grille->game_grid[i][j]);
		}
		printf("\n");
	}
}

