#pragma once

#include "Item.h"
#include "ResrcManager.h"

class YoshiCoin : public Item {
public:
    YoshiCoin(Vector2 pos);
    ~YoshiCoin() override = default;

    void updateMario(Mario& mario) override;
    void playCollisionSound() override;
    void draw() override;
    void Update() override;
};