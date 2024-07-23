#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>
#include <stdio.h>
// the window's W = 1366, H =700
SDL_Rect Inventory = {30, 200, 30, 30};

bool bShowInventory = false;

/*
if (event.key.keysym.sym == SDLK_DOWN) {
    if (player.y < ground.y - player.h) {
      player.y += player.h;
    }
*/

void openInventory() {
  if (event.key.keysym.sym == SDLK_F2 && bShowInventory == false) {
    bShowInventory = true;
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue inventory
    SDL_RenderFillRect(renderer, &Inventory);
  } else if (event.key.keysym.sym == SDLK_F2 && bShowInventory == true) {
    bShowInventory = false;
  }
}
