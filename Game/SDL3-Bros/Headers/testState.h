#ifndef TESTSTATE_H
#define TESTSTATE_H
#include "GameState.h"
#include "Sprite.h"
#include <SDL3/SDL.h>
#include <vector>

// Abstract state machine
class TestState : public GameState
{
public:
  static TestState* get();
  bool enter() override;
  bool exit() override;
  void handleEvent(SDL_Event& e) override;
  void update() override;
  void render() override;
  void addGravity();
  // void addFriction();

private:
  static TestState testState;
  TestState();
  Texture spriteSheetTexture;
  Sprite player;
  Sprite goomba;
  SDL_FRect ground{};
};

#endif
