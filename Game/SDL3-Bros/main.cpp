/*
  Copyright (C) 1997-2026 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely.
*/
#define SDL_MAIN_USE_CALLBACKS 1 /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Globals.h"
#include "Constants.h"
#include "testState.h"
#include "Util.h"
#include "ExitState.h"

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    if (init() == false)
    {
        SDL_Log("Unable to initialize program!\n");
        return SDL_APP_FAILURE;
    }

    currentState = TestState::get();
    if (currentState->enter() == false)
    {
        currentState->exit();
        currentState = ExitState::get();
    }

    return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    currentState->handleEvent(*event);

    if (event->type == SDL_EVENT_QUIT)
    {
        setNextState(ExitState::get());
    }

    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void* appstate)
{
    frameStart = SDL_GetTicksNS();
    deltaTime = (frameStart - lastTick) / 1000000000.f;
    currentState->update();

    if (changeState() == false)
    {
        currentState->exit();
        currentState = ExitState::get();
    }

    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
    SDL_RenderClear(renderer);
    currentState->render();
    SDL_RenderPresent(renderer);

    frameEnd = SDL_GetTicksNS();
    frameTime = frameEnd - frameStart;
    if (frameTime < targetFrameNs)
    {
        uint64_t delayNs = targetFrameNs - frameTime;
        SDL_DelayNS(delayNs);
    }

    lastTick = frameStart;

    if (currentState == ExitState::get())
    {
        SDL_Log("Stopping game");
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    close();
}
