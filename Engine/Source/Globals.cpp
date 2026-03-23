#include "Globals.h"

SDL_Window* window{nullptr};
SDL_Renderer* renderer{nullptr};
TTF_Font* font;
GameState* currentState{nullptr};
GameState* nextState{nullptr};
uint64_t frameStart;
uint64_t frameEnd;
uint64_t frameTime;
float deltaTime;
uint64_t lastTick{0};
