#include "grid.h"
#include "install_dir/include/SDL2/SDL.h"
#include "sdl2.h"

// Structure context
SDLContext context;

void sdl_init() {
  int const width = 1280;
  int const height = 720;
  context = (SDLContext){NULL, NULL, .width = 0, .height = 0};
  if (SDL_Init(SDL_INIT_VIDEO)) {
    return;
  }

  SDL_Window *window =
      SDL_CreateWindow("Sokoban", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
  if (!window) {
    return;
  }
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  context = (SDLContext){
      .window = window, .renderer = renderer, .width = width, .height = height};
}

void sdl_quit() {
  SDL_DestroyWindow(context.window);
  SDL_DestroyRenderer(context.renderer);
  context.window = NULL;
  context.renderer = NULL;
  SDL_Quit();
}

void display_sdl2(struct Grid *grille){
  // origin point
  float positionX = 0;
  float positionY = 0;
  float largeurW = context.width/grille->column_number; // column width
  float hauteurH = context.height/grille->row_number; // row width

  SDL_SetRenderDrawColor(context.renderer, 0, 0, 0, 255); // coulor black
  SDL_RenderClear(context.renderer); // draw the whole window black

  // go through the array and draw according to the enum CaseType
  for(int i = 0; i < grille->row_number; i++){
		for(int j = 0; j < grille->column_number; j++){
      char currentBuffer = grille->game_grid[i][j];
      if(currentBuffer == WALL){
        SDL_Rect rect = { .x = positionX,
                  .y = positionY,
                  .w = largeurW,
                  .h = hauteurH
                };
        SDL_SetRenderDrawColor(context.renderer, 22, 1, 124, 255); // color dark blue
        SDL_RenderFillRect(context.renderer, &rect); // draw the rectangle
      }
      else if(currentBuffer == BOX){
        SDL_Rect rect = { .x = positionX,
                  .y = positionY,
                  .w = largeurW,
                  .h = hauteurH
                };
        SDL_SetRenderDrawColor(context.renderer, 49, 140, 231, 255); // color light blue
        SDL_RenderFillRect(context.renderer, &rect); 
      }
      else if(currentBuffer == BOX_OK){
        SDL_Rect rect = { .x = positionX,
                  .y = positionY,
                  .w = largeurW,
                  .h = hauteurH
                };      
        SDL_SetRenderDrawColor(context.renderer, 102, 51, 0, 255); // color brown
        SDL_RenderFillRect(context.renderer, &rect); 
      }
      else if(currentBuffer == GOAL){
        SDL_Rect rect = { .x = positionX,
                  .y = positionY,
                  .w = largeurW,
                  .h = hauteurH   
                };
        SDL_SetRenderDrawColor(context.renderer, 238, 163, 18, 255); // yellow color
        SDL_RenderFillRect(context.renderer, &rect); 
      }
      else if(currentBuffer == PLAYER || currentBuffer == PLAYER_GOAL){
        SDL_Rect rect = { .x = positionX,
                  .y = positionY,
                  .w = largeurW,
                  .h = hauteurH
                };
        SDL_SetRenderDrawColor(context.renderer, 255, 255, 255, 255); // white color
        SDL_RenderFillRect(context.renderer, &rect); 
      }
      positionX += largeurW; // move up one column
    }
    positionX = 0; // go to the row beneath so x = 0  
    positionY += hauteurH; // go to the row beneath
  }
  SDL_RenderPresent(context.renderer); // display everything
}

Event event_sdl2(){
  SDL_Event ev;
  SDL_WaitEvent(&ev);
  switch(ev.type){
    case SDL_QUIT:
      // pressed on the "quit" window button
      return Quit;
      break;
    case SDL_KEYUP:
      // released a keyboard key
      switch(ev.key.keysym.sym){
        case SDLK_UP:
          return Up;
          break;
        case SDLK_DOWN:
          return Down;
          break;
        case SDLK_LEFT:
          return Left;
          break;
        case SDLK_RIGHT:
          return Right;
          break;
      }
      break;
  }
  return None;
}

Event event(){
  char entry = fgetc(stdin);
  switch(entry){
		case 'q' :{
      return Quit;
			break;
			}
		case 'k' :{
      return Up;
			break;
			}
		case 'j' :{
      return Down;
			break;
			}
		case 'h' :{
      return Left;
			break;
			}
		case 'l' :{
      return Right;
			break;
			}
    default:
      return None;
  } 
}


