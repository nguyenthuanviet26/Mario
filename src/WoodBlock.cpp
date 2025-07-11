
#include "Block.h"
#include "GameWorld.h"
#include "raylib.h"
#include "ResrcManager.h"
#include "WoodBlock.h"
#include <iostream>

WoodBlock::WoodBlock( Vector2 pos, Vector2 dim, Color color ) :
    WoodBlock( pos, dim, color, 0, 1 ) {}

WoodBlock::WoodBlock( Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames ) :
    Block( pos, dim, color, frameTime, maxFrames ) {
        this->blockType = BLOCK_WOOD;
    }

WoodBlock::~WoodBlock() = default;

void WoodBlock::Update() {};

void WoodBlock::draw() {

    DrawTexture( ResrcManager::GetInstance().getTexture("BLOCK_WOOD"), pos.x, pos.y, WHITE );
}
