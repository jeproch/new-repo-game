// #include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "game.h"

// Conditionally render this rectangle
SDL_Rect Inventory = { 220, 560, 400, 400 };
bool showInventory = false;


// bool listenInventory() {
//     if (event.key.keysym.sym == SDLK_i && showInventory == false) {
//         showInventory = true;
//         return true;
//     } else if (event.key.keysym.sym == SDLK_i && showInventory == true){
//         showInventory = false;
//         return false;
//     }
    
// }

void openInventory() {  
    // printf("Showing inventory: %b \n", showInventory);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); //white inventory
    SDL_RenderFillRect(renderer, &Inventory);
    
}

