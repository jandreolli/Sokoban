#pragma once
#include <SDL2/SDL.h>

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
