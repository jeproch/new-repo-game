#include "game.h"

int initializeSDL() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
    return 1;
  }

  window =
      SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 1366, 700, SDL_WINDOW_SHOWN);

  if (!window) {
    fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
    return 1;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
    return 1;
  }

  int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    fprintf(stderr, "SDL_image could not initialize! SDL_image Error: %s\n",
            IMG_GetError());
    return 1;
  }

  int lastFrameTime = SDL_GetTicks(); // outside game loop

  loadMedia();

  return 0;
}