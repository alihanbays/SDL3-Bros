#ifndef SPRITE_H
#define SPRITE_H
#include <SDL3/SDL.h>
#include <sstream>

#include "Vec2.h"

class GameObject
{
public:
    GameObject();
    GameObject(const Vec2& worldPos, const SDL_FRect& collisionBody);
    GameObject(const Vec2& worldPos, const SDL_FRect& collisionBody, const SDL_FRect& textureClip);
    ~GameObject() = default;
    float jumpPower = 140.f;
    float moveSpeed = 400.f;
    float maxSpeed = 60.f;
    float maxFallSpeed = 250.f;
    int moveDirection = 0;
    float getYVelocity() const;
    float getXVelocity() const;
    void setXVelocity(float dx, bool overwrite = false);
    void setYVelocity(float dy, bool overwrite = false);
    void jump();
    void control(const SDL_Event& e);
    void move();
    void setPosition(const Vec2& v);
    void setTextureClip(const SDL_FRect& textureClip);
    void destroy();
    SDL_FRect& getCollisionBox();
    Vec2& getPosition();
    SDL_FRect& getTextureClip();
    void syncLocation();

private:
    SDL_FRect collisionBody_{};
    SDL_FRect textureClip_{};
    Vec2 worldPos_{};
    float dx_{};
    float dy_{};
    bool isOnGround_{false};
};

#endif
