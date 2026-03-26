#include "GameObject.h"
#include <algorithm>
#include "Constants.h"
#include "Globals.h"
#include "Util.h"

GameObject::GameObject() = default;

GameObject::GameObject(const Vec2& worldPos, const SDL_FRect& collisionBody)
{
    worldPos_ = worldPos;
    collisionBody_ = collisionBody;
}

GameObject::GameObject(const Vec2& worldPos, const SDL_FRect& collisionBody, const SDL_FRect& textureClip)
{
    worldPos_ = worldPos;
    collisionBody_ = collisionBody;
    textureClip_ = textureClip;
}

SDL_FRect& GameObject::getCollisionBox() { return collisionBody_; }

SDL_FRect& GameObject::getTextureClip() { return textureClip_; }

Vec2& GameObject::getPosition() { return worldPos_; }

void GameObject::destroy()
{
    collisionBody_.w = 0;
    collisionBody_.h = 0;
}

void GameObject::setPosition(const Vec2& v)
{
    worldPos_.x = v.x;
    worldPos_.y = v.y;
}

void GameObject::syncLocation()
{
    this->collisionBody_.x = this->worldPos_.x;
    this->collisionBody_.y = this->worldPos_.y;
}

void GameObject::setTextureClip(const SDL_FRect& textureClip)
{
    textureClip_ = textureClip;
    collisionBody_.w = textureClip.w;
    collisionBody_.h = textureClip.h;
}

void GameObject::move()
{
    dy_ = std::clamp(dy_, -maxFallSpeed, jumpPower);
    dx_ = std::clamp(dx_, -maxSpeed, maxSpeed);

    if (dx_ != 0)
        worldPos_.x += dx_ * deltaTime;

    if (dy_ != 0)
        worldPos_.y += dy_ * deltaTime;

    syncLocation();
    SDL_Log("World Position x : %f, y: %f", worldPos_.x, worldPos_.y);
}

void GameObject::setXVelocity(const float dx, const bool overwrite)
{
    if (overwrite)
        dx_ = dx;
    else
        dx_ += dx;
}

void GameObject::setYVelocity(const float dy, const bool overwrite)
{
    if (overwrite)
        dy_ = dy;
    else
        dy_ += dy;
}

float GameObject::getXVelocity() const { return dx_; }

float GameObject::getYVelocity() const { return dx_; }

void GameObject::jump() { setYVelocity(jumpPower, true); }

void GameObject::control(const SDL_Event& e) {}


