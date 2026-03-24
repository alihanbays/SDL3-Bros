#ifndef TESTSTATE_H
#define TESTSTATE_H
#include <vector>
#include <SDL3/SDL.h>
#include "GameActor.h"
#include "GameState.h"

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
  void addGravity(GameActor* actor);
  void addFriction(GameActor* actor);

private:
  static TestState testState;
  TestState();
  Texture spriteSheetTexture;
  std::vector<GameActor*> actors;
  GameActor* playerActor;
  SDL_FRect ground{};
  const bool* keyboardState;
};

#endif
