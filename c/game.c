#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mutex.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

SDL_Texture *backgroundTexture = NULL;
SDL_Texture *playerTexture = NULL;

SDL_Texture *playerRightTexture = NULL;
SDL_Texture *playerLeftTexture = NULL;

void showPlayerRight() {
  SDL_Surface *playerSurfaceRight = IMG_Load("../assets/player-right.png");

  if (playerSurfaceRight == NULL) {
    printf("Failed to load playerSurfaceRight image! SDL_image Error: %s \n",
           IMG_GetError());
    return;
  }

  playerRightTexture =
      SDL_CreateTextureFromSurface(renderer, playerSurfaceRight);

  SDL_FreeSurface(playerSurfaceRight);
  SDL_RenderCopy(renderer, playerRightTexture, NULL, &player);
}

void showPlayerLeft() {
  SDL_Surface *playerSurfaceLeft = IMG_Load("../assets/player-left.png");

  if (playerSurfaceLeft == NULL) {
    printf("Failed to load playerSurfaceLeft image! SDL_image Error: %s \n",
           IMG_GetError());
    return;
  }

  playerLeftTexture = SDL_CreateTextureFromSurface(renderer, playerSurfaceLeft);

  SDL_FreeSurface(playerSurfaceLeft);
  SDL_RenderCopy(renderer, playerLeftTexture, NULL, &player);
}

void showPlayer() {
  // in order to not continously render both images together
  SDL_Surface *playerSurface = IMG_Load("../assets/new-player.png");

  if (playerSurface == NULL) {
    printf("Failed to load player image! SDL_image ERROR: %s\n",
           IMG_GetError());
    return;
  }

  playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
  SDL_FreeSurface(playerSurface);
  SDL_RenderCopy(renderer, playerTexture, NULL, &player);
}

void loadMedia() {

  SDL_Surface *loadedSurface = IMG_Load("../assets/Unsaved Image 2.jpg");

  if (loadedSurface == NULL) {
    printf("Failed to load background image! SDL_image Error: %s\n",
           IMG_GetError());
    return;
  }

  // TEXTURES
  backgroundTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

  // free the surfaces here
  SDL_FreeSurface(loadedSurface);
}

void determineFrameTime() {
  // int currentFrameTime = SDL_GetTicks();

  // if (lastFrameTime == 0) {
  //   lastFrameTime = SDL_GetTicks();
  // }

  // if (currentFrameTime - lastFrameTime > 16) { // roughly 60 fps
  //   lastFrameTime = currentFrameTime;
  // }
  lastFrameTime = 0; //why does this read as read only?
  printf("%d \n", lastFrameTime);
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
    determineFrameTime();
  }

  if (quit != 1) {
    showPlayer();
  }
}
