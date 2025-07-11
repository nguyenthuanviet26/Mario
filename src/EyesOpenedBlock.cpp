
#include "Block.h"
#include "EyesOpenedBlock.h"
#include "GameWorld.h"
#include "raylib.h"
#include "ResrcManager.h"
#include <iostream>
#include <string>

EyesOpenedBlock::EyesOpenedBlock( Vector2 pos, Vector2 dim, Color color ) :
    EyesOpenedBlock( pos, dim, color, 1, 4 ) {}

EyesOpenedBlock::EyesOpenedBlock( Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames ) :
    Block( pos, dim, color, frameTime, maxFrames ){
        this->blockType = BLOCK_EYES_OPENED;
    }

EyesOpenedBlock::~EyesOpenedBlock() = default;

void EyesOpenedBlock::Update() {

    const float delta = GetFrameTime();

    if ( hit ) {
        frameAcumulator += delta;
        if ( frameAcumulator > 6*frameTime ) {
            frameAcumulator = 0;
            currentFrame++;
            if( currentFrame >= maxFrames ) {
                currentFrame %= maxFrames;
                resetHit();
            }
        }
    }

    // if ( hit ) {
    //     animationAcum += delta;
    //     if ( animationAcum >= animationTime ) {
    //         hit = false;
    //         animationAcum = 0;
    //         currentFrame = 0;
    //         state = SPRITE_STATE_IDLE;
    //     }
    // }

}

void EyesOpenedBlock::draw() {
    
    if ( hit ) {
        DrawTexture( ResrcManager::GetInstance().getTexture(std::string( TextFormat( "BLOCK_EYE_OPEN_%d", currentFrame ) )) , pos.x, pos.y, WHITE );
    } else {
        DrawTexture( ResrcManager::GetInstance().getTexture("BLOCK_EYE_OPEN_0"), pos.x, pos.y, WHITE );
    }

}

void EyesOpenedBlock::doHit( Mario& mario, Map *map ) {
    if ( !hit ) {
        //PlaySound( ResrcManager::GetInstance().getSound("shellRicochet") );
        hit = true;
        state = OBJECT_STATE_IDLE;
    }
}
