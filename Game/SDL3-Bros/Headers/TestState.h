#ifndef TESTSTATE_H
#define TESTSTATE_H
#include <vector>
#include <SDL3/SDL.h>
#include "GameObject.h"
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
  void addGravity(GameObject* actor);
  void addFriction(GameObject* actor);

private:
  static TestState testState_;
  TestState();
  Texture spriteSheetTexture_;
  std::vector<GameObject*> gameObjects_;
  GameObject* playerObject_;
  GameObject* groundObject_;
  const bool* keyboardState_;
};

#endif
