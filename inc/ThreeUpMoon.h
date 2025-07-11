#pragma once

#include "Item.h"
#include "ResrcManager.h"

class ThreeUpMoon : public Item {
public:
    ThreeUpMoon(Vector2 pos);
    ~ThreeUpMoon() override = default;

    void updateMario(Mario& mario) override;
    void playCollisionSound() override;
    void draw() override;
    void Update() override;

private:
    bool applyGravity = true;
};