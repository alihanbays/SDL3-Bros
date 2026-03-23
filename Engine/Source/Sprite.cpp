#include "Sprite.h"
#include "Audio.h"
#include "Constants.h"
#include "Globals.h"
#include "Texture.h"
#include "Util.h"
#include <algorithm>

Sprite::Sprite() = default;

SDL_FRect* Sprite::getCollisionBox()
{
    return &collisionBody;
}

SDL_FRect* Sprite::getTextureClip()
{
    return &textureClip;
}

void Sprite::destroy()
{
    collisionBody.w = 0;
    collisionBody.h = 0;
}

void Sprite::setPosition(const float x, const float y)
{
    collisionBody.x = x;
    collisionBody.y = y;
}

void Sprite::setTextureClip(const float x, const float y, const float w, const float h)
{
    const SDL_FRect rect{x, y, w, h};
    textureClip = rect;
    collisionBody.w = rect.w;
    collisionBody.h = rect.h;
}

void Sprite::move()
{
    collisionBody.x += static_cast<float>(direction) * moveSpeed * deltaTime;
    collisionBody.y += yVelocity * deltaTime;
}

// TODO: Implement velocity base movement in the future
void Sprite::setXVelocity(float newX, bool overwrite)
{
    // if (!overwrite)
    // {
    //     xVelocity += newX * deltaTime;
    // }
    // else
    // {
    //     xVelocity = newX;
    // }

    // if (xVelocity > 0)
    // {
    //     xVelocity = std::min(playerMaxSpeed, xVelocity);
    // }
    // else
    // {
    //     xVelocity = std::max(playerMaxSpeed *, xVelocity);
    // }
}

void Sprite::setYVelocity(const float newY, const bool overwrite)
{
    if (!overwrite)
    {
        yVelocity += newY * deltaTime;
    }
    else
    {
        yVelocity = newY;
    }
}

float Sprite::getXVelocity() const
{
    return xVelocity;
}

float Sprite::getYVelocity() const
{
    return xVelocity;
}

void Sprite::control(const SDL_Event& e)
{
    if (e.type == SDL_EVENT_KEY_DOWN && e.key.repeat == 0)
    {
        switch (e.key.key)
        {
        case SDLK_A:
            direction += -1;
            break;
        case SDLK_D:
            direction += 1;
            break;
        case SDLK_SPACE:
            setYVelocity(jumpPower * -1, true);
            break;
        default:
            break;
        }
    }
    else if (e.type == SDL_EVENT_KEY_UP && e.key.repeat == 0)
    {
        switch (e.key.key)
        {
        case SDLK_A:
            direction += 1;
            break;
        case SDLK_D:
            direction += -1;
            break;
        default:
            break;
        }
    }
}
