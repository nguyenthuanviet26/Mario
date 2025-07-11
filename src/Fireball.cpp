#include "Fireball.h"
#include "GameWorld.h"

Fireball::Fireball(Vector2 pos, Direction direction) : Object(pos, Vector2{16,16}, WHITE), distanceLeft(MAX_DISTANCE)
{
    sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_0_RIGHT");
    frameTime = 0.1;
    frameAcumulator = 0.0f;
    currentFrame = 0;
    maxFrames = 3;
    vel = Vector2{FIREBALL_SPEEDX, 0};
    if (direction == DIRECTION_LEFT)
    {
        vel.x = -FIREBALL_SPEEDX;
        sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_0_LEFT");
    }
    cpN.setColor(RED);
    cpS.setColor(RED);
    cpE.setColor(RED);
    cpW.setColor(RED);
    cpN.setSize(Vector2{size.x-8, 1});
    cpS.setSize(Vector2{size.x-8, 1});
    cpE.setSize(Vector2{1, size.y-8});
    cpW.setSize(Vector2{1, size.y-8});
    UpdateCollisionProbes();
}

bool Fireball::isOutOfDistance() const
{
    return distanceLeft < 0.0f;
}

void Fireball::draw()
{
    if (isOutOfDistance())
        return;
    Update();
    DrawTexture(*sprite, pos.x, pos.y, WHITE);
}

void Fireball::setSpeed(float speedX, float speedY)
{
    //
}

void Fireball::setDirection(Direction direction)
{
    if (direction == DIRECTION_LEFT)
    {
        vel.x = -FIREBALL_SPEEDX;
        sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_0_LEFT");
    }
    else if (direction == DIRECTION_RIGHT)
    {
        vel.x = FIREBALL_SPEEDX;
        sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_0_RIGHT");
    }
    // Add other directions if needed
}

void Fireball::Update()
{
    if (direction == DIRECTION_LEFT)
    {
        switch(currentFrame) {
            case 0:
                sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_0_LEFT");
                break;
            case 1:
                sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_1_LEFT");
                break;
            case 2:
                sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_2_LEFT");
                break;
            case 3:
                sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_3_LEFT");
                break;
        }
    } else {
        switch(currentFrame) {
            case 0:
                sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_0_RIGHT");
                break;
            case 1:
                sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_1_RIGHT");
                break;
            case 2:
                sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_2_RIGHT");
                break;
            case 3:
                sprite = &ResrcManager::GetInstance().getTexture("FIRE_BALL_3_RIGHT");
                break;
        }
    }
    
}

void Fireball::UpdateStateAndPhysic()
{
    if (isOutOfDistance())
        return;
    UpdateCollisionProbes();
    const float deltaTime = GameClock::getInstance().FIXED_TIME_STEP;

    frameAcumulator += deltaTime;
    maxFrames = 3;
    if (frameAcumulator > frameTime)
    {
        currentFrame = (currentFrame + 1) % maxFrames;
        frameAcumulator -= frameTime;
    }

    distanceLeft -= abs(vel.x) * deltaTime; // Update distance left based on speed

    if (vel.x > 0) direction = DIRECTION_RIGHT;
    else if (vel.x < 0) direction = DIRECTION_LEFT;

    Object::UpdateStateAndPhysic();
    vel.y += GameWorld::GetGravity()*deltaTime;
}

