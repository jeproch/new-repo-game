#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdbool.h>
// #include <time.h>
// #include <stdio.h>

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

void quitGame() { quit = 1; }

// switch between animations when moving

bool startedRight = false;
int timeRight = 0;
int endTimeRight;

void startTimeShowRight() {
  startedRight = true;
  timeRight = SDL_GetTicks();
  endTimeRight = timeRight + 500;
}

bool startedLeft = false;
int timeLeft = 0;
int endTimeLeft;

void startTimeShowLeft() {
  startedLeft = true;
  timeLeft = SDL_GetTicks();
  endTimeLeft = timeLeft + 500;
}

void move() { // SDL_KEYDOWN
  if (event.key.keysym.sym == SDLK_LEFT) {
    if (player.x > 0) {
      player.x -= 15;

      if (startedLeft == false) {
        startTimeShowLeft();
      }

      if (timeLeft != endTimeLeft) {
        showPlayerLeft();
      } else {
        startedLeft = false;
      }
    }
  } else if (event.key.keysym.sym == SDLK_RIGHT) {
    if (player.x < 1366 - player.w) {
      player.x += 15;

      if (startedRight == false) {
        startTimeShowRight();
      }

      if (timeRight != endTimeRight) {
        showPlayerRight();
      } else {
        startedRight = false;
      }
    }
  } else if (event.key.keysym.sym == SDLK_F1) {
    quitGame();
  }

  keepPlayerOnWindow();
}
