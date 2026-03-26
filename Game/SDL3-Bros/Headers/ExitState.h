#ifndef EXITSTATE_H
#define EXITSTATE_H
#include "GameState.h"
#include "Texture.h"
#include <SDL3/SDL.h>

class ExitState : public GameState
{
public:
    static ExitState* get();
    bool enter() override;
    bool exit() override;
    void handleEvent(SDL_Event& e) override;
    void update() override;
    void render() override;

private:
    static ExitState exitState_;
    ExitState();
    Texture messageTexture_;
    Uint64 startingFrame_{};
    Uint64 delay_{};
};

#endif
