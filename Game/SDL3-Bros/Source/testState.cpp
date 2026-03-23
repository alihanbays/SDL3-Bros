#include "testState.h"
#include "Constants.h"
#include "Globals.h"
#include "Util.h"

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
    // Place player
    player.setPosition(0, 0);
    player.setTextureClip(0, 0, 16, 16); // 0,0 location 16x16 size
    // Place Goomba
    goomba.setPosition(16, 0);
    goomba.setTextureClip(16, 0, 16, 16); // 0,0 location 16x16 size

    return success;
}

bool TestState::exit()
{
    return true;
}

void TestState::handleEvent(SDL_Event& e)
{
    player.control(e);
}

void TestState::render()
{
    // Render player
    spriteSheetTexture.render(player.getCollisionBox()->x, player.getCollisionBox()->y, player.getTextureClip());
    // Render goomba
    spriteSheetTexture.render(goomba.getCollisionBox()->x, goomba.getCollisionBox()->y, goomba.getTextureClip());

    // Render temporary ground
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    ground = {
        20.f,
        210.f,
        200.f,
        20.f,
    };
    SDL_RenderFillRect(renderer, &ground);
}

void TestState::addGravity()
{
    // Get all the objects under test state;

    // for now just add player

    // Bunu "Yerde degilsen uygula gibi yapabiliriz"
    player.setYVelocity(gravity);
}

// void TestState::addFriction()
// {
//     // Get all the objects under test state;
//     float xVel = player.getXVelocity();

//     if (xVel != 0)
//     {
//         if (xVel > 0)
//         {
//             xVel -= player.friction;

//             // // If we overshot it
//             // if (xVel < 0)
//             // {
//             //     player.setXVelocity(0, true);
//             // }
//             // else
//             // {
//             //     player.setXVelocity(xVel);
//             // }
//         }
//         else
//         {
//             xVel += player.friction;

//             // if (xVel > 0)
//             // {
//             //     player.setXVelocity(0, true);
//             // }
//             // else
//             // {
//             //     player.setXVelocity(xVel);
//             // }
//         }
//     }
// }

void TestState::update()
{
    player.move();

    // Handle Collision
    if (AABB(*player.getCollisionBox(), ground))
    {
        handleCollision(player.getCollisionBox(), &ground);
    }
    else
    {
        addGravity();
    }

    // addFriction();
}
