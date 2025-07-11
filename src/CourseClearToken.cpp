#include "CourseClearToken.h"
#include "ResrcManager.h"
#include "Mario.h"
#include "raylib.h"
#include <cmath>

CourseClearToken::CourseClearToken(Vector2 pos)
    : Item(
        pos,
        {32, 32},           // Kích thước
        {0, 0},             // Không di chuyển
        WHITE,              // Màu vẽ
        0.0f,               // Không dùng frame animation
        1,                  // 1 frame
        DIRECTION_RIGHT,    // Không quan trọng
        1,                  // 1 lần va chạm là biến mất
        0                   // Không cộng điểm
    ),
    spinTimer(0.0f),
    spinSpeed(1.5f),  // tốc độ quay vòng/giây
    scaleX(1.0f)
{
    sprite = &ResrcManager::GetInstance().getTexture("COURSE CLEAR TOKEN");

    if (sprite->id == 0) {
        TraceLog(LOG_ERROR, "COURSE CLEAR TOKEN texture failed to load!");
    }

    state = OBJECT_STATE_ACTIVE;
}

void CourseClearToken::Update() {
    UpdateCollisionProbes();

    // Tính giá trị scaleX theo sin → lật trái/phải
    spinTimer += GetFrameTime();
    scaleX = sinf(spinTimer * spinSpeed * 2 * PI);  // dao động -1 đến 1
}

void CourseClearToken::draw() {
    if (state == OBJECT_STATE_TO_BE_REMOVED || state == OBJECT_STATE_DEAD)
        return;

    float absScaleX = fabs(scaleX);  // scale dương để tính kích thước
    float renderWidth = size.x * absScaleX;

    Rectangle source = {
        scaleX < 0 ? sprite->width : 0,
        0,
        scaleX < 0 ? -sprite->width : sprite->width,
        (float)sprite->height
    };

    Rectangle dest = {
        pos.x + size.x / 2,
        pos.y + size.y / 2,
        renderWidth,
        size.y
    };

    DrawTexturePro(
        *sprite,
        source,
        dest,
        Vector2{ renderWidth / 2, size.y / 2 },
        0.0f,
        color
    );
}

void CourseClearToken::updateMario(Mario& mario) {
    mario.SetState(OBJECT_STATE_TO_BE_REMOVED); 
    this->SetState(OBJECT_STATE_TO_BE_REMOVED);
}

void CourseClearToken::playCollisionSound() {
    // TODO: Thêm âm thanh nếu cần
}