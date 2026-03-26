#include "TestState.h"
#include "../Headers/Constants.h"
#include "../Headers/Globals.h"
#include "../Headers/Util.h"

TestState TestState::testState_;

TestState::TestState() = default;

TestState* TestState::get()
{
    return &testState_;
}

bool TestState::enter()
{
    bool success{true};

    if (spriteSheetTexture_.loadFromFile("Game/SDL3-Bros/Assets/spritesheet.png") == false)
    {
        SDL_Log("TestState::enter(): Failed load spritesheet");
        success = false;
    }

    // Place player
    auto* player = new GameObject({50, 50}, {50, 50, 16, 16}, {0, 0, 16, 16});

    // Place Goomba
    auto* goomba = new GameObject({100, 100}, {100, 100, 16, 16}, {16, 0, 16, 16});

    // Place Ground
    auto* ground = new GameObject({0, 0}, {0, 0, 2000.f, 20.f,});

    playerObject_ = player;
    groundObject_ = ground;
    gameObjects_.push_back(player);
    gameObjects_.push_back(goomba);

    keyboardState_ = SDL_GetKeyboardState(nullptr);
    return success;
}

bool TestState::exit()
{
    return true;
}

void TestState::handleEvent(SDL_Event& e)
{
    if (keyboardState_[SDL_SCANCODE_A])
    {
        playerObject_->setXVelocity(playerObject_->moveSpeed * -1);
    }
    if (keyboardState_[SDL_SCANCODE_D])
    {
        playerObject_->setXVelocity(playerObject_->moveSpeed);
    }
    if (keyboardState_[SDL_SCANCODE_SPACE])
    {
        playerObject_->jump();
    }
}

void TestState::render()
{
    for (GameObject* actor : gameObjects_)
    {
        auto [x, y] = ToScreenSpace(actor->getPosition(), actor->getCollisionBox());
        spriteSheetTexture_.render(x, y, &actor->getTextureClip());
    }

    // Render temporary ground
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    auto [x, y] = ToScreenSpace(groundObject_->getPosition(), groundObject_->getCollisionBox());
    auto box = groundObject_->getCollisionBox();
    box.x = x;
    box.y = y;
    SDL_RenderFillRect(renderer, &box);
}

void TestState::addGravity(GameObject* actor) { actor->setYVelocity(gravity); }

void TestState::addFriction(GameObject* actor) { actor->setXVelocity(actor->getXVelocity() * friction, true); }

void TestState::update()
{
    for (GameObject* actor : gameObjects_)
    {
        addGravity(actor);
        actor->move();

        // Handle Collision
        if (AABB(actor->getCollisionBox(), groundObject_->getCollisionBox()))
        {
            handleCollision(&actor->getPosition(), &actor->getCollisionBox(), &groundObject_->getCollisionBox());
            actor->setYVelocity(0, true);
        }

        if (!keyboardState_[SDL_SCANCODE_A] && !keyboardState_[SDL_SCANCODE_D])
            addFriction(actor);
    }
}
