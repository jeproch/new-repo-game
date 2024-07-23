#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>

SDL_Rect Inventory = {220, 560, 50, 50};

void openInventory() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue inventory
  SDL_RenderFillRect(renderer, &Inventory);
}
