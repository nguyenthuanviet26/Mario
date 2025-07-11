#pragma once

#include "Item.h"
#include "ResrcManager.h"

class CourseClearToken : public Item {
private:
    float rotationAngle; 
    float rotationSpeed; 
    float scaleX = 0.1f;
    float spinTimer = 0.0f;
    float spinSpeed = 1.0f; // Tốc độ xoay (vòng/giây)
public:
    CourseClearToken(Vector2 pos);
    ~CourseClearToken() override = default;

    void updateMario(Mario& mario) override;
    void playCollisionSound() override;
    void draw() override;
    void Update() override;
};
