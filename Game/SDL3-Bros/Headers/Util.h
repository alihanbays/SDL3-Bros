#ifndef UTIL_H
#define UTIL_H
#include "GameState.h"
#include <SDL3/SDL.h>

#include "Vec2.h"

// Utilities, statemanagement, engine related helper functions
void close();
bool init();
void setNextState(GameState* state);
bool changeState();
bool AABB(const SDL_FRect& a, const SDL_FRect& b);
void handleCollision(Vec2* worldPos, SDL_FRect* a, SDL_FRect* b);
Vec2 ToScreenSpace(const Vec2& v, const SDL_FRect& body);

#endif
