#include "../Headers/Util.h"
#include "../Headers/Audio.h"
#include "../Headers/Constants.h"
#include "ExitState.h"
#include "../Headers/Globals.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

void close()
{
    SDL_Log("Trying to Quit...");
    audioCleanup();
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
}

bool init()
{
    bool success{true};

    if (!SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        SDL_Log("SDL could not be initialized! SDL error: %s\n", SDL_GetError());
        success = false;
    }

    if (!SDL_CreateWindowAndRenderer("Pong", WindowWidth, WindowHeight, SDL_WINDOW_RESIZABLE, &window, &renderer))
    {
        SDL_Log("SDL could not create window and renderer! SDL error: %s\n", SDL_GetError());
        success = false;
    }

    SDL_SetRenderLogicalPresentation(renderer, RenderWidth, RenderHeight, SDL_LOGICAL_PRESENTATION_LETTERBOX);

    if (!TTF_Init())
    {
        SDL_Log("SDL_ttf could not initialize! SDL_ttf error: %s\n", SDL_GetError());
        success = false;
    }

    // Initilize Font
    std::string fontPath{"Game/SDL3-Bros/Assets/font.ttf"};
    font = TTF_OpenFont(fontPath.c_str(), 28);

    if (font == nullptr)
    {
        SDL_Log("generateScoreTexture: Font is null");
        printf("TTF_OpenFont: %s\n", SDL_GetError());
        return false;
    }

    if (!audioInit())
    {
        SDL_Log("Failed to initilize audio");
        // return false;
    }

    return success;
}

void setNextState(GameState* state)
{
    if (nextState != ExitState::get())
    {
        nextState = state;
    }
}

bool changeState()
{
    bool success{true};

    if (nextState != nullptr)
    {
        SDL_Log("Changing state to: %p", &nextState);
        success = currentState->exit() && success;
        success = nextState->enter() && success;

        currentState = nextState;
        nextState = nullptr;
    }

    return success;
}

bool AABB(const SDL_FRect& a, const SDL_FRect& b)
{
    return a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h && a.y + a.h > b.y;
}

void handleCollision(Vec2* worldPos, SDL_FRect* a, SDL_FRect* b)
{
    const float aXmin{a->x};
    const float aXmax{a->x + a->w};
    const float aYmin{a->y};
    const float aYmax{a->y + a->h};
    const float bXmin{b->x};
    const float bXmax{b->x + b->w};
    const float bYmin{b->y};
    const float bYmax{b->y + b->h};

    const float xOverlap = std::min(aXmax, bXmax) - std::max(aXmin, bXmin);
    const float yOverlap = std::min(aYmax, bYmax) - std::max(aYmin, bYmin);

    if (xOverlap < yOverlap)
    {
        if (aXmax > bXmax)
        {
            worldPos->x += xOverlap;
        }
        else
        {
            worldPos->x -= xOverlap;
        }
    }
    else if (xOverlap >= yOverlap)
    {
        if (aYmax > bYmax)
        {
            worldPos->y += yOverlap;
        }
        else
        {
            worldPos->y -= yOverlap;
        }
    }
}

Vec2 ToScreenSpace(const Vec2& v, const SDL_FRect& body)
{
    return Vec2{v.x, RenderHeight - v.y - body.h};
}
