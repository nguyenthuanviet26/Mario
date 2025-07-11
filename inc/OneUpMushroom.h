#pragma once

#include "Item.h"
#include "ResrcManager.h"

class OneUpMushroom : public Item {
public:
    OneUpMushroom(Vector2 pos);
    ~OneUpMushroom() override = default;

    void updateMario(Mario& mario) override;
    void playCollisionSound() override;
    void draw() override;
    void Update() override;
};