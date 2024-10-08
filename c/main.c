#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event; // Define event here
int quit = 0;

void destroyTextures() {
  SDL_DestroyTexture(backgroundTexture);
  SDL_DestroyTexture(playerTexture);
}

void destroySDL() {
  // Cleanup
  destroyTextures();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}

int main() {
  initializeSDL();

  while (!quit) {
    // Render background
    render();
  }

  destroySDL();

  return 0;
}
