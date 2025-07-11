#include "ThreeUpMoon.h"
#include "GameWorld.h"
#include "Mario.h"
#include "raylib.h"

ThreeUpMoon::ThreeUpMoon(Vector2 pos)
    : Item(pos, {32, 32}, {100, 0}, WHITE, 0.0f, 1, DIRECTION_RIGHT, 3, 0)
{
    state = OBJECT_STATE_ACTIVE;
}

void ThreeUpMoon::updateMario(Mario& mario)
{
    mario.SetLives(mario.GetLives() + 3);  
    this->SetState(OBJECT_STATE_TO_BE_REMOVED);
}

void ThreeUpMoon::playCollisionSound()
{
    Sound& sound = ResrcManager::GetInstance().getSound("1UP_SOUND");
    PlaySound(sound);
}

void ThreeUpMoon::Update()
{
    float dt = GetFrameTime();

    pos.x += vel.x * dt;
    if (applyGravity)
        vel.y += GameWorld::GetGravity() * dt;

    pos.y += vel.y * dt;

    UpdateCollisionProbes();
}

void ThreeUpMoon::draw()
{
    if (state == OBJECT_STATE_TO_BE_REMOVED || state == OBJECT_STATE_DEAD)
        return;

    Texture2D& tex = ResrcManager::GetInstance().getTexture("3UpMoon");
    DrawTextureEx(
        tex,
        pos,
        0.0f,
        1.0f,
        color
    );
}