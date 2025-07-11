
#include "Block.h"
#include "GameWorld.h"
#include "GlassBlock.h"
#include "raylib.h"
#include "ResrcManager.h"
#include <iostream>

GlassBlock::GlassBlock( Vector2 pos, Vector2 dim, Color color ) :
    GlassBlock( pos, dim, color, 0, 1 ) {}

GlassBlock::GlassBlock( Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames ) :
    Block( pos, dim, color, frameTime, maxFrames ) {
        this-> blockType = BLOCK_GLASS;
    }

GlassBlock::~GlassBlock() = default;

void GlassBlock::Update() {}

void GlassBlock::draw() {

    DrawTexture( ResrcManager::GetInstance().getTexture("BLOCK_GLASS"), pos.x, pos.y, WHITE );

}
