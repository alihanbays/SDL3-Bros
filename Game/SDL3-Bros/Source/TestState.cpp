#include "TestState.h"
#include "../Headers/Constants.h"
#include "../Headers/Globals.h"
#include "../Headers/Util.h"

TestState TestState::testState;

TestState::TestState() = default;

TestState* TestState::get()
{
    return &testState;
}

bool TestState::enter()
{
    bool success{true};

    if (spriteSheetTexture.loadFromFile("Game/SDL3-Bros/Assets/spritesheet.png") == false)
    {
        SDL_Log("TestState::enter(): Failed load spritesheet");
        success = false;
    }

    // Lets create character
    // Place playerif
    auto* player = new GameActor();
    player->setPosition(0, 0);
    player->setTextureClip(0, 0, 16, 16); // 0,0 location 16x16 size

    // Place Goomba
    // auto* goomba = new GameActor();
    // goomba->setPosition(16, 0);
    // goomba->setTextureClip(16, 0, 16, 16); // 0,0 location 16x16 size

    playerActor = player;
    actors.push_back(player);
    //actors.push_back(goomba);

    keyboardState = SDL_GetKeyboardState(nullptr);
    return success;
}

bool TestState::exit()
{
    return true;
}

void TestState::handleEvent(SDL_Event& e)
{
    if (keyboardState[SDL_SCANCODE_A])
    {
        playerActor->setXVelocity(playerActor->moveSpeed * -1);
    }
    if (keyboardState[SDL_SCANCODE_D])
    {
        playerActor->setXVelocity(playerActor->moveSpeed);
    }
    if (keyboardState[SDL_SCANCODE_SPACE])
    {
        playerActor->jump();
    }
}

void TestState::render()
{
    for (GameActor* actor : actors)
    {
        spriteSheetTexture.render(actor->getCollisionBox()->x, actor->getCollisionBox()->y, actor->getTextureClip());
    }

    // Render temporary ground
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    ground = {
        0.f,
        210.f,
        2000.f,
        20.f,
    };
    SDL_RenderFillRect(renderer, &ground);
}

void TestState::addGravity(GameActor* actor) { actor->setYVelocity(gravity); }

void TestState::addFriction(GameActor* actor) { actor->setXVelocity(actor->getXVelocity() * friction, true); }

void TestState::update()
{
    for (GameActor* actor : actors)
    {
        addGravity(actor);
        actor->move();

        // Handle Collision
        if (AABB(*actor->getCollisionBox(), ground))
        {
            handleCollision(actor->getCollisionBox(), &ground);
            actor->setYVelocity(0, true);
        }

        if (!keyboardState[SDL_SCANCODE_A] && !keyboardState[SDL_SCANCODE_D])
            addFriction(actor);
    }
}
