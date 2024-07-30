#include "game.h"

void render() {
  // Update game state (positions, game logic, etc.)
  keepPlayerOnWindow(); // Adjust player position to stay within window bounds

  // Clear the screen
  SDL_RenderClear(renderer);

  // Render background
  SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
  SDL_RenderCopy(renderer, playerTexture, NULL, &player);

  // Render other elements
  // Player is not a one colour rectangle anymore

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