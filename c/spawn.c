// How will stuff randomly spawn on screen??
#include "game.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <stdio.h>
#include <stdlib.h>
// #include <stdio.h>

int N = 1366;
int randomInt;

void spawnRectangle() { // same level as player
  // SDL_Rect ground = {0, 610, 1366, 90};
  int randomInt = rand() % (N + 1);

  // SDL_Rect player = {220, 560, 50, 50};
  printf("%d \n", randomInt);
  // render here
  //   SDL_SetRenderDrawColor(renderer, 0, 155, 133, 255);
  //   SDL_FillRect(renderer, &newRectangle);
}