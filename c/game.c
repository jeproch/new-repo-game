#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>

SDL_Texture *backgroundTexture = NULL;
SDL_Rect player = {220, 560, 50, 50};
SDL_Rect ground = {0, 610, 1366, 90};
SDL_Rect healthBar = {10, 10, 1000, 70};

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

void render() {
  // Update game state (positions, game logic, etc.)
  keepPlayerOnWindow(); // Adjust player position to stay within window bounds

  // Clear the screen
  SDL_RenderClear(renderer);

  // Render background
  SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

  // Render other elements
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set color to red
  SDL_RenderFillRect(renderer, &player);            // Draw the player

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set color to green
  SDL_RenderFillRect(renderer, &healthBar);         // Draw the health bar

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set color to green
  SDL_RenderFillRect(renderer, &ground);            // Draw the ground

  // keep this here so that it's rendered semi correctly

  if (bShowInventory) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue inventory
    SDL_RenderFillRect(renderer, &Inventory);         // render
  }

  handleEvents();

  // Update screen
  SDL_RenderPresent(renderer);

  // Add a small delay to reduce CPU usage
  SDL_Delay(10);
}
