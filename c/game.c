#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

SDL_Texture *backgroundTexture = NULL;
SDL_Texture *playerTexture = NULL;

void loadMedia() {
  // Load background image (replace with your actual image path)
  SDL_Surface *loadedSurface = IMG_Load("../assets/Unsaved Image 2.jpg");
  SDL_Surface *playerSurface = IMG_Load("../assets/new-player.png");

  if (loadedSurface == NULL) {
    printf("Failed to load background image! SDL_image Error: %s\n",
           IMG_GetError());
    return;
  }

  if (playerSurface == NULL) {
    printf("Failed to load player image! SDL_image ERROR: %s\n",
           IMG_GetError());
    return;
  }

  // TEXTURES
  backgroundTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);

  // free the surfaces here
  SDL_FreeSurface(loadedSurface);
  SDL_FreeSurface(playerSurface);
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
