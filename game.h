#ifndef GAME_H
#define GAME_H
#include <stdbool.h>
#include <SDL2/SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Event event; // Declare event as extern here
extern SDL_Rect player;
extern SDL_Rect healthBar;
extern SDL_Rect ground;
extern SDL_Rect Inventory; // Declare other variables as extern here
extern int quit;
extern int hp;
extern SDL_Texture* backgroundTexture;

//functions

void loadMedia();
void move();
void handleEvents();
void render();
bool listenInventory();
void openInventory();
void keepPlayerOnWindow();

#endif
