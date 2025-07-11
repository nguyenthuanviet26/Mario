#include "Item.h"
#include "raylib.h"

Item::Item()
    : Object(), pauseGameOnHit(false), earnedPoints(0), hitsToDie(1) {}

Item::Item(Vector2 pos, Vector2 dim, Vector2 vel, Color color,
           float frameTime, int maxFrames, Direction facingDirection,
           int hitsToDie, int earnedPoints)
    : Object(pos, dim, vel, color, frameTime, maxFrames, facingDirection),
      pauseGameOnHit(false), earnedPoints(earnedPoints), hitsToDie(hitsToDie) {}

Item::~Item() = default;

void Item::draw() {
    if (sprite != nullptr && sprite->id != 0) {
        DrawTextureEx(*sprite, pos, angle, 1.0f, color);
    }
}

void Item::SetSprite(Texture2D* texture) {
    this->sprite = texture; 
}

void Item::SetState(ObjectState state) {
    this->state = state;
}

void Item::onSouthCollision(Mario& mario) {
}

bool Item::isPauseGameOnHit() {
    return pauseGameOnHit;
}

CollisionType Item::checkCollision(const Object& other) {
    Rectangle rect1 = { pos.x, pos.y, size.x, size.y };
    Rectangle rect2 = { other.GetPos().x, other.GetPos().y, other.GetSize().x, other.GetSize().y };

    if (CheckCollisionRecs(rect1, rect2)) {
        return COLLISION_TYPE_COLLIDED;
    }
    return COLLISION_TYPE_NONE;
}
