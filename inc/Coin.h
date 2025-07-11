#pragma once

#include "Item.h"
#include <vector>
#include <string>

class Coin : public Item {
private:
    std::vector<Texture2D*> coinFrames;
    bool collected;

public:
    Coin(Vector2 pos);
    ~Coin() override = default;

    void Update() override;
    void draw() override;
    void updateMario(Mario& mario) override;
    void playCollisionSound() override;
};