#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Event event;
extern SDL_Rect player;
extern SDL_Rect healthBar;
extern SDL_Rect ground;
extern SDL_Rect Inventory;
extern int quit;
extern SDL_Texture* backgroundTexture;

void loadMedia();
void move();
void handleEvents();
void render();
void openInventory();
void keepPlayerOnWindow();

#endif
