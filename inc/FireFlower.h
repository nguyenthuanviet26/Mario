#pragma once
#include "Item.h"
#include "ResrcManager.h"

class FireFlower : public Item
{
private:
    bool blinking;
    float blinkingAcum;
    float blinkingTime;
    bool doBlink;

public:
    FireFlower(Vector2 pos);
    ~FireFlower() override = default;

    void updateMario(Mario &mario) override;
    void playCollisionSound() override;
    void draw() override;
    void NewFunction(Texture2D &tex, std::string &texKey, bool &retFlag);
    void Update() override;
};