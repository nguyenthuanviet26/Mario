
#include "Block.h"
#include "EyesClosedBlock.h"
#include "GameWorld.h"
#include "raylib.h"
#include "ResrcManager.h"
#include <iostream>

EyesClosedBlock::EyesClosedBlock( Vector2 pos, Vector2 dim, Color color ) :
    EyesClosedBlock( pos, dim, color, 0, 1 ) {}

EyesClosedBlock::EyesClosedBlock( Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames ) :
    Block( pos, dim, color, frameTime, maxFrames ) {
        this->blockType = BLOCK_EYES_CLOSED;
    }

EyesClosedBlock::~EyesClosedBlock() = default;

void EyesClosedBlock::Update() {}

void EyesClosedBlock::draw() {

    DrawTexture( ResrcManager::GetInstance().getTexture("BLOCK_EYE_CLOSED"), pos.x, pos.y, WHITE );

}