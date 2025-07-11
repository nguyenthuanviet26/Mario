#include "Object.h"



void Object::UpdateCollisionProbes() {
    cpN.setPos(Vector2{ pos.x + size.x / 2 - cpN.getSize().x/2 , pos.y });
    cpS.setPos(Vector2{ pos.x + size.x / 2 - cpS.getSize().x/2, pos.y + size.y - cpS.getSize().y +1 });
    cpE.setPos(Vector2{ pos.x + size.x - cpE.getSize().x , pos.y + size.y / 2 - cpE.getSize().y / 2 });
    cpW.setPos(Vector2{ pos.x, pos.y + size.y / 2 - cpW.getSize().y / 2 });
}

void Object::UpdateStateAndPhysic() {
    // Update the object's state and physics based on its current state
    pos.x += vel.x * GameClock::getInstance().FIXED_TIME_STEP;
    pos.y += vel.y * GameClock::getInstance().FIXED_TIME_STEP;
    
    UpdateCollisionProbes(); // Update collision probes after moving
}

CollisionType Object::checkCollisionType(const Object& other) const {
    // Check collision with another object
    Rectangle rectA = { pos.x, pos.y, size.x, size.y };
    Rectangle rectB = { other.pos.x, other.pos.y, other.size.x, other.size.y };
    
    
        // Determine the type of collision based on the position of the probes
        if (cpN.checkCollision(rectB) ) return COLLISION_TYPE_NORTH;
        if (cpS.checkCollision(rectB) ) return COLLISION_TYPE_SOUTH;
        if (cpE.checkCollision(rectB) ) return COLLISION_TYPE_EAST;
        if (cpW.checkCollision(rectB) ) return COLLISION_TYPE_WEST;
    
    
    return COLLISION_TYPE_NONE; // No collision
}
// full constructor 
Object::Object(Vector2 pos, Vector2 size, Vector2 vel, Color color, float frameTime, int maxFrames, Direction direction)
    : pos(pos), size(size), vel(vel), color(color), frameTime(frameTime), maxFrames(maxFrames), direction(direction),
      angle(0.0f), state(OBJECT_STATE_IDLE), AdditionalState(OBJECT_STATE_IDLE), sprite(nullptr),
      frameAcumulator(0.0f), currentFrame(0) {
    cpN = CollisionProbe{ Vector2{ pos.x + size.x/2 - 5, pos.y}, Vector2{size.x,5}, color }; // North probe
    cpS = CollisionProbe{ Vector2{ pos.x + size.x/2 - 5, pos.y + size.y - 5}, Vector2{size.x,5}, color }; // South probe
    cpE = CollisionProbe{ Vector2{ pos.x + size.x - 5, pos.y + size.y/2 - 5}, Vector2{5,size.y}, color }; // East probe
    cpW = CollisionProbe{ Vector2{ pos.x, pos.y + size.y/2 - 5}, Vector2{5,size.y}, color }; // West probe
}
Object::Object() : Object(Vector2{0, 0}, Vector2{50, 50}, Vector2{0, 0}, WHITE, 0, 0, DIRECTION_RIGHT) {
    // Default constructor initializes with default values
}
Object::Object(Vector2 pos, Vector2 size, Color color)
    : Object(pos, size, Vector2{0, 0}, color, 0.0f, 0, DIRECTION_RIGHT) {
    // Constructor with position, size and color
}
Object::Object(Vector2 pos, Vector2 size, Vector2 vel, Color color, float frameTime, int maxFrames)
    : Object(pos, size, vel, color, frameTime, maxFrames, DIRECTION_RIGHT) {
    // Constructor with position, size, velocity, color, frame time and max frames
}
Object::~Object() {
    // Destructor
    sprite = nullptr; // Assuming sprite is managed elsewhere
}



void Object::SetPos(Vector2 pos) {
    this->pos = pos;
    UpdateCollisionProbes(); // Update probes when position changes
}

void Object::SetSize(Vector2 size) {
    this->size = size;
    UpdateCollisionProbes(); // Update probes when size changes
}

void Object::SetAngle(float angle) {
    this->angle = angle;
}

void Object::SetState(ObjectState state) {
    this->state = state;
}

void Object::SetColor(Color color) {
    this->color = color;
    cpN.setColor(color);
    cpS.setColor(color);
    cpE.setColor(color);
    cpW.setColor(color);
}

void Object::SetDirection(Direction direction) {
    this->direction = direction;
}

void Object::SetVel(Vector2 vel) {
    this->vel = vel;
}

void Object::setFrameTime(float frameTime) {
    this->frameTime = frameTime;
}

void Object::setFrameAcum(float frameAcum) {
    this->frameAcumulator = frameAcum;
}

void Object::setCurrFrame(int currFrame) {
    this->currentFrame = currFrame;
}

void Object::setMaxFrame(int maxFrame) {
    this->maxFrames = maxFrame;
}

void Object::SetCollisionProbesTop(CollisionProbe Top) {
    cpN = Top;
}

void Object::SetCollisionProbesBottom(CollisionProbe Bottom) {
    cpS = Bottom;
}

void Object::SetCollisionProbesRight(CollisionProbe Right) {
    cpE = Right;
}

void Object::SetCollisionProbesLeft(CollisionProbe Left) {
    cpW = Left;
}

//Getters
Vector2 Object::GetPos() const {
    return pos;
}

Vector2 Object::GetSize() const{
    return size;
}

float Object::GetAngle() const {
    return angle;
}

ObjectState Object::GetState() const {
    return state;
}

Color Object::GetColor() const {
    return color;
}

Direction Object::GetDirection() const {
    return direction;
}

Vector2 Object::GetVel() const{
    return vel;
}

float Object::GetFrameTime() const {
    return frameTime;
}
float Object::GetFrameAcum() const {
    return frameAcumulator;
}
int Object::GetCurrFrame() const {
    return currentFrame;
}
int Object::GetMaxFrame() const {
    return maxFrames;
}