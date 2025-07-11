#include "Mushroom.h"
#include "GameWorld.h"
#include "Mario.h"
#include "raylib.h"

Mushroom::Mushroom(Vector2 pos)
    : Item(pos, {32, 32}, {0, 0}, WHITE, 0.0f, 1, DIRECTION_RIGHT, 1, 0),
      applyGravity(true)
{
    state = OBJECT_STATE_ACTIVE;
    vel.x = 100;
    vel.y = 0;
}

void Mushroom::updateMario(Mario& mario)
{
    mario.changeToBig();
    this->SetState(OBJECT_STATE_TO_BE_REMOVED);
}

void Mushroom::playCollisionSound()
{
    
}

void Mushroom::Update()
{
    float dt = GetFrameTime();

    pos.x += vel.x * dt;
    if (applyGravity)
        vel.y += GameWorld::GetGravity() * dt;

    pos.y += vel.y * dt;

    UpdateCollisionProbes();
}

void Mushroom::draw()
{
    if (state == OBJECT_STATE_TO_BE_REMOVED || state == OBJECT_STATE_DEAD)
        return;

    Texture2D& tex = ResrcManager::GetInstance().getTexture("Mushroom");
    DrawTextureEx(
        tex,
        pos,
        0.0f,
        1.0f,
        color
    );
}