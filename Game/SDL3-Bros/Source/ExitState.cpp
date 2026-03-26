#include "ExitState.h"
#include "Constants.h"
#include "../Headers/Globals.h"
#include "../Headers/Util.h"

ExitState ExitState::exitState_;

ExitState::ExitState() = default;

ExitState* ExitState::get()
{
    return &exitState_;
}

bool ExitState::enter()
{
    bool success{true};

    if (messageTexture_.createTextTexture("Exiting...") == false)
    {
        SDL_Log("Failed to create intro message");
        success = false;
    }

    startingFrame_ = SDL_GetTicks();
    delay_ = 1000;
    return success;
}

bool ExitState::exit()
{
    messageTexture_.destroy();
    return true;
}

void ExitState::handleEvent(SDL_Event& e)
{
    if (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_RETURN)
    {
        close();
    }
}

void ExitState::render()
{
    messageTexture_.render((RenderWidth - messageTexture_.getWidth()) / 2.f,
                          (RenderHeight - messageTexture_.getHeight()) / 2.f);
}

void ExitState::update()
{
    if (SDL_GetTicks() - startingFrame_ >= delay_)
    {
        // running = false;
    }
}
