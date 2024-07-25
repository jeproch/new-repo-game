#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdbool.h>
#include <stdio.h>

SDL_Rect Inventory = {30, 200, 30, 30};
bool bShowInventory = false;

void toggleInventory() {
  if (event.key.keysym.sym == SDLK_F2) {
    SDL_Delay(100);
    bShowInventory = !bShowInventory;
  }
}
