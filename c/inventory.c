#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_timer.h>
#include <stdbool.h>
// #include <stdio.h>

SDL_Rect Inventory = {100, 30, 700, 400};
bool bShowInventory = false;

void toggleInventory() {
  if (event.key.keysym.sym == SDLK_i) {
    SDL_Delay(100);
    bShowInventory = !bShowInventory;
  } else if (event.key.keysym.sym == SDLK_ESCAPE) {
    bShowInventory = !bShowInventory;
  }
}
