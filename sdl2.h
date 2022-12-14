/**
 * @file sdl2.h
 * @author Justine Andreolli
 */

#ifndef SDL2_HEADER
#define SDL2_HEADER

#pragma once
#include "install_dir/include/SDL2/SDL.h" 

typedef struct SDLContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} SDLContext;
/* @brief 
 * Initializes a global variable `context` of SDLContext type
 *
 * If there is an error during initialization:
 *  context.window = NULL
 *  or
 *  context.renderer = NULL
 *
 * tou have to test the two !
 * 
 */

void sdl_init();
/**
 * cleans the global variable context
 */

void sdl_quit();

/**
 * @brief function displaying the level with sdl2
 * @param grille structure Grid
 */
void display_sdl2(struct Grid *grid);

/**
 * @enum Event
 * @brief This enum contains the events corresponding to the keyboard keys
 */
typedef enum Event{
  Quit,
  Left,
  Right,
  Up,
  Down,
  None
}Event;

/**
 * @brief function returning the type of action that has to be done
 * @return an enum Event
 */
Event event_sdl2();

/**
 * @brief function returning the type of action that we have to make for the keyboard management
 * @return an enum Event
 */
Event event();


#endif