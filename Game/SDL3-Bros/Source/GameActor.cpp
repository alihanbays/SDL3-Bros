#include "GameActor.h"
#include <algorithm>
#include "Constants.h"
#include "Globals.h"

GameActor::GameActor() = default;

SDL_FRect* GameActor::getCollisionBox() { return &collisionBody_; }

SDL_FRect* GameActor::getTextureClip() { return &textureClip_; }

void GameActor::destroy()
{
    collisionBody_.w = 0;
    collisionBody_.h = 0;
}

void GameActor::setPosition(const float x, const float y)
{
    collisionBody_.x = x;
    collisionBody_.y = y;
}

void GameActor::setTextureClip(const float x, const float y, const float w, const float h)
{
    const SDL_FRect rect{x, y, w, h};
    textureClip_ = rect;
    collisionBody_.w = rect.w;
    collisionBody_.h = rect.h;
}

void GameActor::move()
{
    dy_ = std::clamp(dy_, -jumpPower, maxFallSpeed);
    dx_ = std::clamp(dx_, -maxSpeed, maxSpeed);

    if (dx_ != 0)
        collisionBody_.x += dx_ * deltaTime;

    if (dy_ != 0)
        collisionBody_.y += dy_ * deltaTime;

    SDL_Log("dx = %f, dy = %f", dx_, dy_);
}

void GameActor::setXVelocity(const float dx, const bool overwrite)
{
    if (overwrite)
        dx_ = dx;
    else
        dx_ += dx;
}

void GameActor::setYVelocity(const float dy, const bool overwrite)
{
    if (overwrite)
        dy_ = dy;
    else
        dy_ += dy;
}

float GameActor::getXVelocity() const { return dx_; }

float GameActor::getYVelocity() const { return dx_; }

void GameActor::jump() { setYVelocity(-jumpPower, true); }

void GameActor::control(const SDL_Event& e) {}

