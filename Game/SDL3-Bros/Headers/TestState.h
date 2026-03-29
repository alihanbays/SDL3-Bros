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
  Vec2 ToScreenSpace(const Vec2& v, const SDL_FRect& body);
  Vec2 ToCameraSpace(const Vec2& v) const;

private:
  static TestState testState_;
  TestState();
  Texture spriteSheetTexture_;
  std::vector<GameObject*> gameObjects_;
  GameObject* playerObject_;
  GameObject* groundObject_;
  const bool* keyboardState_;
  Vec2 cameraPosition_;
  SDL_Rect viewport_;
  float worldSpaceWidth_{1024};
  float worldSpaceHeight_{960};
};

#endif
