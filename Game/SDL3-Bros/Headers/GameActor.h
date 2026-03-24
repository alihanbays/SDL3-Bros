#ifndef SPRITE_H
#define SPRITE_H
#include <SDL3/SDL.h>
#include <sstream>

class GameActor
{
public:
    GameActor();
    ~GameActor() = default;
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
    void setPosition(float x, float y);
    void setTextureClip(float x, float y, float w, float h);
    void destroy();
    SDL_FRect* getCollisionBox();
    SDL_FRect* getTextureClip();

private:
    SDL_FRect collisionBody_{};
    SDL_FRect textureClip_{};
    float dx_{};
    float dy_{};
    bool isOnGround_{false};
};

#endif
