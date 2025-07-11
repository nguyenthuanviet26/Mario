/**
 * @file CloudBlock.cpp
 * @author Prof. Dr. David Buzatto
 * @brief CloudBlock class implementation.
 *
 * @copyright Copyright (c) 2024
 */
#include "Block.h"
#include "CloudBlock.h"
#include "GameWorld.h"
#include "raylib.h"
#include "ResrcManager.h"
#include <iostream>

CloudBlock::CloudBlock( Vector2 pos, Vector2 size, Color color ) :
    CloudBlock( pos, size, color, 0, 1 ) {}

CloudBlock::CloudBlock( Vector2 pos, Vector2 size, Color color, float frameTime, int maxFrames ) :
    Block( pos, size, color, frameTime, maxFrames ) {
    this->blockType = BLOCK_CLOUD;
    }

CloudBlock::~CloudBlock() = default;

void CloudBlock::Update() {
}

void CloudBlock::draw() {
    DrawTexture(
        ResrcManager::GetInstance().getTexture("BLOCK_CLOUD"),
        this->pos.x,
        this->pos.y,
        WHITE
    );

    // Debug draw nếu muốn
    // if (this->color.a != 0) {
    //     DrawRectangle(
    //         this->pos.x,
    //         this->pos.y,
    //         this->size.x,
    //         this->size.y,
    //         Fade(this->color, 0.5f)
    //     );
    // }
}



