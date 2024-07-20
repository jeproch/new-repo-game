#include "game.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void move() {
    if (event.key.keysym.sym == SDLK_DOWN) {
        if (player.y < ground.y - player.h) {
            player.y += player.h;
        }
    } else if (event.key.keysym.sym == SDLK_UP) {
        if (player.y > 0 ) {
            player.y -= player.h;
        }
    } else if (event.key.keysym.sym == SDLK_LEFT) {
        if (player.x > 0) {
            player.x -= player.w;
        }
    } else if (event.key.keysym.sym == SDLK_RIGHT) {
        if (player.x < 1366 - player.w) {
            player.x += player.w;
        }
    } else if (event.key.keysym.sym == SDLK_F1) {
        quit = 1;
    }
    keepPlayerOnWindow();
}