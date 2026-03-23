#include "ExitState.h"
#include "Constants.h"
#include "Globals.h"
#include "../Headers/Util.h"

ExitState ExitState::exitState;

ExitState::ExitState() = default;

ExitState* ExitState::get()
{
    return &exitState;
}

bool ExitState::enter()
{
    bool success{true};

    if (messageTexture.createTextTexture("Exiting...") == false)
    {
        SDL_Log("Failed to create intro message");
        success = false;
    }

    startingFrame = SDL_GetTicks();
    delay = 1000;
    return success;
}

bool ExitState::exit()
{
    messageTexture.destroy();
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
    messageTexture.render((ScreenWidth - messageTexture.getWidth()) / 2.f,
                          (ScreenHeight - messageTexture.getHeight()) / 2.f);
}

void ExitState::update()
{
    if (SDL_GetTicks() - startingFrame >= delay)
    {
        // running = false;
    }
}
