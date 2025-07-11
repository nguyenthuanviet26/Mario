
#include "Block.h"
#include "GameWorld.h"
#include "raylib.h"

Block::Block() :
    Object(Vector2{ 0, 0 }, Vector2{ 0, 0 }, BLACK, 0, 0 ), hit(false) {};

Block::Block( Vector2 pos, Vector2 dim, Color color ) :
    Object( pos, dim, color ), hit( false ) {};
Block::Block(Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames)
    : Object(pos, dim, color, frameTime, maxFrames), hit(false) {};


// Block::Block( Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames ) :
//     Object(pos, dim, color, frameTime, maxFrames), hit( false ) {
// }

Block::~Block() = default;

void Block::doHit(Mario& mario, Map* map) {

}

void Block::resetHit() {
    this->hit = false;
}

BlockType Block::GetBlockType() {
    return blockType;
}

