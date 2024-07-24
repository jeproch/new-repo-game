#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
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

void keepPlayerOnWindow() {
  // Keep the player on the map by adjusting its coordinates to stay in view
  if (player.y > ground.y - player.h) {
    player.y = ground.y - player.h;
  } else if (player.y < 0) {
    player.y = player.h;
  } else if (player.x < 0) {
    player.x = player.w;
  } else if (player.x > 1366 - player.w) {
    player.x = 1366 - player.w;
  }
}

void handleEvents() {
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      quit = 1;
    } else if (event.type == SDL_KEYDOWN) {
      move(); // Add move function call here
    }
  }
  openInventory();
}

void render() {

  // Update game state (positions, game logic, etc.)
  keepPlayerOnWindow(); // Adjust player position to stay within window bounds

  // Clear the screen
  SDL_RenderClear(renderer);

  // Render background
  SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

  // Handle events (user input, window events, etc.)

  handleEvents();

  // Render other elements
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set color to red
  SDL_RenderFillRect(renderer, &player);            // Draw the player

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set color to green
  SDL_RenderFillRect(renderer, &healthBar);         // Draw the health bar

  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set color to green
  SDL_RenderFillRect(renderer, &ground);            // Draw the ground

  // Update screen
  SDL_RenderPresent(renderer);

  // Add a small delay to reduce CPU usage
  SDL_Delay(10);
}
