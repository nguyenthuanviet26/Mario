#include "OneUpMushroom.h"
#include "GameWorld.h"
#include "Mario.h"
#include "raylib.h"

OneUpMushroom::OneUpMushroom(Vector2 pos)
    : Item(pos, {32, 32}, {0, 0}, WHITE, 0.0f, 1, DIRECTION_RIGHT, 1, 0)
{
    state = OBJECT_STATE_ACTIVE;
    vel.x = 100;
    vel.y = 0;
}

void OneUpMushroom::updateMario(Mario& mario)
{
    mario.SetLives(mario.GetLives() + 1);
    this->SetState(OBJECT_STATE_TO_BE_REMOVED);
}

void OneUpMushroom::playCollisionSound()
{
    
}

void OneUpMushroom::Update()
{
    float dt = GetFrameTime();

    pos.x += vel.x * dt;
    vel.y += GameWorld::GetGravity() * dt;
    pos.y += vel.y * dt;

    UpdateCollisionProbes();
}

void OneUpMushroom::draw()
{
    if (state == OBJECT_STATE_TO_BE_REMOVED || state == OBJECT_STATE_DEAD)
        return;

    Texture2D& tex = ResrcManager::GetInstance().getTexture("1UpMushroom");
    DrawTextureEx(
        tex,
        pos,
        0.0f,
        1.0f,
        color
    );
}