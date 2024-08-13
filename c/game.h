#ifndef GAME_H
#define GAME_H

// LIBRARIES SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>

// VARIABLES
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;
extern SDL_Rect player;
extern SDL_Rect healthBar;
extern SDL_Rect ground;
extern SDL_Rect Inventory;
extern SDL_Rect newRectangle; // the food or just enemies {Items??}
extern SDL_Texture *backgroundTexture;
extern SDL_Texture *playerTexture;
extern int quit;
extern int lastFrameTime;
extern bool bShowInventory;

// FUNCTIONS
void loadMedia();
void showPlayer();
void showPlayerRight();
void showPlayerLeft();
void move();
void handleEvents();
void render();
void toggleInventory();
void keepPlayerOnWindow();
int initializeSDL();

#endif
