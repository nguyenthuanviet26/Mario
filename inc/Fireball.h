#pragma once
#include "Object.h"
#include "Tile.h"
#include "ResrcManager.h"
#include "GameClock.h"

class Fireball: public Object{
private:
    Texture2D *sprite;
    static constexpr float MAX_DISTANCE = 1000.0f; // Maximum distance the fireball can travel
    float distanceLeft; // Distance left to travel
    static constexpr float FIREBALL_SPEEDX = 500.0f; // Speed of the fireball in the X direction
    void Update() override;
    
    
public:
    
    Fireball(Vector2 pos, Direction direction);
    bool isOutOfDistance() const;
    void draw() override;
    void setSpeed(float speedX, float speedY);
    void setDirection(Direction direction);
    void UpdateStateAndPhysic() override;
};