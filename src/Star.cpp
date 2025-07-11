
#include "GameWorld.h"
#include "Mario.h"
#include "raylib.h"
#include "Star.h"

Star::Star(Vector2 pos)
    : Item(pos, {32, 32}, {100, 0}, WHITE, 0.0f, 1, DIRECTION_RIGHT, 1, 0)
{
    state = OBJECT_STATE_ACTIVE;
}

void Star::updateMario(Mario& mario)
{
    mario.setInvincible(true);
    this->SetState(OBJECT_STATE_TO_BE_REMOVED);
}

void Star::playCollisionSound()
{
    
}

void Star::Update()
{
    float dt = GetFrameTime();

    pos.x += vel.x * dt;
    vel.y += GameWorld::GetGravity() * dt;
    pos.y += vel.y * dt;

    UpdateCollisionProbes();
}

void Star::draw()
{
    if (state == OBJECT_STATE_TO_BE_REMOVED || state == OBJECT_STATE_DEAD)
        return;

    Texture2D& tex = ResrcManager::GetInstance().getTexture("star");
    DrawTextureEx(
        tex,
        pos,
        0.0f,
        1.0f,
        color
    );
}