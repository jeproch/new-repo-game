#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <stdbool.h>
#include <stdio.h>
// the window's W = 1366, H =700
SDL_Rect Inventory = {30, 200, 30, 30};

bool bShowInventory = false;

void openInventory() {

  if (event.key.keysym.sym == SDLK_F2 && bShowInventory == false) {
    bShowInventory = true;
    while (bShowInventory) {
      SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue inventory
      SDL_RenderFillRect(renderer, &Inventory);         // render

      if (event.key.keysym.sym == SDLK_F2 && bShowInventory == true) {
        bShowInventory = false;
        printf("broke the display loop");
        break;
      }
      SDL_Delay(100);
    }
  }
}
