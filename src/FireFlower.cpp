#include "FireFlower.h"
#include "raylib.h"
#include "ResrcManager.h"

FireFlower::FireFlower(Vector2 pos)
    : Item(pos, {32, 32}, {0, 0}, WHITE, 0.3f, 2, DIRECTION_RIGHT, 1, 0),
      blinking(false), blinkingAcum(0), blinkingTime(0.1f), doBlink(false)
{
    state = OBJECT_STATE_ACTIVE;
}

void FireFlower::updateMario(Mario& mario)
{
    mario.changetoFire();
    SetState(OBJECT_STATE_TO_BE_REMOVED);
}

void FireFlower::playCollisionSound()
{
    // TODO: play sound
}

void FireFlower::Update()
{
    float delta = GetFrameTime();
    frameAcumulator += delta;

    // Cập nhật animation mỗi frameTime giây
    if (frameAcumulator >= frameTime) {
        currentFrame = (currentFrame + 1) % maxFrames;
        frameAcumulator = 0.0f;
    }

    // Cập nhật blinking
    if (blinking) {
        blinkingAcum += delta;
        if (blinkingAcum >= blinkingTime) {
            blinkingAcum = 0.0f;
            doBlink = !doBlink;
        }
    }

    UpdateCollisionProbes();
}

void FireFlower::draw()
{
    if (state == OBJECT_STATE_TO_BE_REMOVED || state == OBJECT_STATE_DEAD)
        return;

    if (blinking && doBlink)
        return;

    // Dùng currentFrame để lấy tên ảnh tương ứng
    std::string texKey = "FIRE FLOWER_" + std::to_string(currentFrame);
    Texture2D& tex = ResrcManager::GetInstance().getTexture(texKey);

    if (tex.id == 0) {
        TraceLog(LOG_ERROR, "Texture %s not loaded!", texKey.c_str());
        return;
    }

    DrawTextureEx(tex, pos, 0.0f, 1.0f, color);
}