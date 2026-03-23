#ifndef SPRITE_H
#define SPRITE_H
#include <SDL3/SDL.h>
#include <sstream>

class Sprite
{
public:
    Sprite();
    ~Sprite() = default;
    // float playerSpeed = 2000.f;
    // float playerMaxSpeed = 35.f;
    float jumpPower = 80.f;
    // float friction = 100.f;
    float moveSpeed = 60.f;
    int direction = 0;
    SDL_FRect* getCollisionBox();
    SDL_FRect* getTextureClip();
    float getYVelocity() const;
    float getXVelocity() const;
    void setXVelocity(float newX, bool overwritsetYVelocitye = false);
    void setYVelocity(float newY, bool overwrite = false);
    void control(const SDL_Event& e);
    void move();
    void setPosition(float x, float y);
    void setTextureClip(float x, float y, float w, float h);
    void destroy();

private:
    SDL_FRect collisionBody{};
    SDL_FRect textureClip{};
    float xVelocity{};
    float yVelocity{};
};

#endif
