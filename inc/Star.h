#pragma once

#include "Item.h"
#include "ResrcManager.h"
#include "GameWorld.h"
class Star : public Item, GameWorld {
public:
    Star(Vector2 pos);
    ~Star() override = default;

    void updateMario(Mario& mario) override;
    void playCollisionSound() override;
    void draw() override;
    void Update() override;
};