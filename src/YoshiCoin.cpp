#include "YoshiCoin.h"
#include "GameWorld.h"
#include "Mario.h"
#include "raylib.h"

YoshiCoin::YoshiCoin(Vector2 pos)
    : Item(pos, {32, 32}, {0, 0}, WHITE, 0.15f, 4, DIRECTION_RIGHT, 0, 0)
{
    state = OBJECT_STATE_ACTIVE;
}

void YoshiCoin::updateMario(Mario& mario)
{
    mario.SetCoins(mario.GetCoins() + 1);  // Hoặc mario.addYoshiCoin(); nếu có hệ thống đặc biệt
    this->SetState(OBJECT_STATE_TO_BE_REMOVED);
}

void YoshiCoin::playCollisionSound()
{
    Sound& sound = ResrcManager::GetInstance().getSound("coin");
    PlaySound(sound);
}

void YoshiCoin::Update()
{
    if (state == OBJECT_STATE_TO_BE_REMOVED || state == OBJECT_STATE_DEAD)
        return;

    float dt = GetFrameTime();

    frameAcumulator += dt;
    if (frameAcumulator >= frameTime) {
        frameAcumulator = 0;
        currentFrame = (currentFrame + 1) % maxFrames;
    }

    UpdateCollisionProbes();
}

void YoshiCoin::draw()
{
    if (state == OBJECT_STATE_TO_BE_REMOVED || state == OBJECT_STATE_DEAD)
        return;

    Texture2D& tex = ResrcManager::GetInstance().getTexture(
        TextFormat("YoshiCoin_%d", currentFrame)
    );

    DrawTextureEx(
        tex,
        pos,
        0.0f,
        1.0f,
        color
    );
}