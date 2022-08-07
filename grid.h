/**
 * @file grid.h
 * @author Justine Andreolli
 */

#ifndef GRID_HEADER
#define GRID_HEADER
enum CaseType{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' '
};

/**
 * @struct Player
 * @brief This structure contains x and y position of the player
 */
struct Player{
	int x; // x Player position (row)
	int y; // y Player position (column)
};

/**
 * @struct Grid
 * @brief This structure contains information
 * about the game grid and its content
 */
struct Grid{
	enum CaseType** game_grid; ///< Array containing the entities present in the game
	int column_number; ///< Number of columns in game_grid
	int row_number; ///< Number of lines in game_grid
	struct Player playerPosition; ///< Structure containing the player's position
};

/**
 * @brief function writing the enum CaseType in the game_grid array
 * @param file_path the .txt file corresponding to the level 
 * @param grille the Grid structure
 */
void init_level(const char* file_path, struct Grid *grille);

/**
 * @brief function freeing the Grid structure array
 * @param grille the Grid structure
 */
void freeArray(struct Grid *grille);

/**
 * @brief function displaying the level
 * @param grille the Grid structure
 */
void display(struct Grid *grille);


#endif
