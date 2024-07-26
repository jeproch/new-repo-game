#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>

SDL_Texture *backgroundTexture = NULL;

void loadMedia() {
  // Load background image (replace with your actual image path)
  SDL_Surface *loadedSurface = IMG_Load("../assets/Unsaved Image 2.jpg");
  if (loadedSurface == NULL) {
    printf("Failed to load background image! SDL_image Error: %s\n",
           IMG_GetError());
    return;
  }
  backgroundTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  SDL_FreeSurface(loadedSurface);
}

void handleEvents() {
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      quit = 1;
    } else if (event.type == SDL_KEYDOWN) {
      if (!bShowInventory) {
        move(); // Add move function call here only if inventory is not shown
      }
    }
    toggleInventory(); //  Check for inventory toggle
  }
}
