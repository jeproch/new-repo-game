#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_timer.h>
#include <stdbool.h>
#include <stdio.h>

SDL_Rect Inventory = {100, 30, 700, 400};
bool bShowInventory = false;

void toggleInventory() {
  if (event.key.keysym.sym == SDLK_F2) {
    SDL_Delay(100);
    bShowInventory = true;
  } else if (event.key.keysym.sym == SDLK_F3) {
    bShowInventory = false;
  }
}
