#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event; // Define event here
int quit = 0;

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 700, SDL_WINDOW_SHOWN);
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
        fprintf(stderr, "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    loadMedia();

    while (!quit) {
        

        // Render background
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        handleEvents();
        
        // Render other elements (player, health bar, ground, etc.)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set color to red for player
        SDL_RenderFillRect(renderer, &player); // Draw the player

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set color to green for health bar
        SDL_RenderFillRect(renderer, &healthBar); // Draw the health bar

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set color to green for ground
        SDL_RenderFillRect(renderer, &ground); // Draw the ground


        // Update screen
        SDL_RenderPresent(renderer);

        // Add a small delay to reduce CPU usage
        SDL_Delay(10);
    }

    // Cleanup
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
