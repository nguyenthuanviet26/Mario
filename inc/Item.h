#pragma once

#include "Object.h"
#include "Mario.h"

class Item : public Object {
protected:
    bool pauseGameOnHit;
    int earnedPoints;
    int hitsToDie;

public:
    Item();
    Item(Vector2 pos, Vector2 dim, Vector2 vel, Color color,
         float frameTime, int maxFrames, Direction facingDirection,
         int hitsToDie, int earnedPoints);
    virtual ~Item() override;

    virtual void Update() override = 0;
    virtual void draw() override;

    virtual void updateMario(Mario& mario) = 0;
    virtual void playCollisionSound() = 0;
    virtual void onSouthCollision(Mario& mario);

    void SetState(ObjectState state);
    bool isPauseGameOnHit();
    void SetSprite(Texture2D* texture);  
    CollisionType checkCollision(const Object& other);
};