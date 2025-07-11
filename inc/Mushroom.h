
#pragma once
#include "Item.h"
#include "ResrcManager.h"

class Mushroom : public Item {
public:
    Mushroom(Vector2 pos);
    ~Mushroom() override = default;

    void updateMario(Mario& mario) override;
    void playCollisionSound() override;
    void draw() override;
    void Update() override;

private:
    bool applyGravity = true;
};