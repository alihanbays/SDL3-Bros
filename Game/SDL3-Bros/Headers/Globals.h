#ifndef GLOBALS_H
#define GLOBALS_H
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "GameState.h"

// Core Engine Globals
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern TTF_Font* font;
extern GameState* currentState;
extern GameState* nextState;
extern uint64_t frameStart;
extern uint64_t frameEnd;
extern uint64_t frameTime;
extern float deltaTime;
extern uint64_t lastTick;
#endif
