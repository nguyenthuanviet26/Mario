
#include "Block.h"
#include "GameWorld.h"
#include "QuestionBlock.h"
#include "raylib.h"
#include <iostream>
#include <string>

QuestionBlock::QuestionBlock( Vector2 pos, Vector2 dim, Color color ) :
    QuestionBlock( pos, dim, color, 0.5, 4 ) {    }

QuestionBlock::QuestionBlock( Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames ) :
    Block( pos, dim, color, frameTime, maxFrames),
    coinAnimationTime( 0.6 ),
    coinAnimationAcum( 0 ),
    coinFrameAcum( 0 ),
    coinAnimationFrame( 0 ),
    coinAnimationRunning( false ),
    coinY( 0 ),
    coinVelY( -400 ),
    stardustAnimationTime( 0.1 ),
    stardustAnimationAcum( 0 ),
    stardustAnimationFrame( 0 ),
    maxStartDustAnimationFrame( 4 ),
    stardustAnimationRunning( false ),
    pointsFrameAcum( 0 ),
    pointsFrameTime( 0.5 ),
    pointsAnimationRunning( false ) {}

QuestionBlock::~QuestionBlock() = default;

void QuestionBlock::Update() {
    

    const float delta = GetFrameTime();

    if ( hit && coinAnimationRunning ) {

        coinAnimationAcum += delta;
        if ( coinAnimationAcum >= coinAnimationTime ) {
            coinAnimationRunning = false;
            stardustAnimationRunning = true;
            pointsAnimationRunning = true;
            coinAnimationFrame++;
            coinAnimationFrame %= maxFrames;
        }

        coinFrameAcum += delta;
        if ( coinFrameAcum > frameTime ) {
            coinFrameAcum = 0;
            coinAnimationFrame++;
            coinAnimationFrame %= maxFrames;
        }

        coinY += coinVelY * delta;
        coinVelY += GameWorld::GetGravity();

    }

    if ( !hit ) {
        frameAcumulator += delta;
        if ( frameAcumulator > 6*frameTime ) {
            frameAcumulator = 0;
            currentFrame++;
            currentFrame %= maxFrames;
        }
    }

    // if ( stardustAnimationRunning ) {    

    //     stardustAnimationAcum += delta;
    //     if ( stardustAnimationAcum >= stardustAnimationTime ) {
    //         stardustAnimationAcum = 0;
    //         stardustAnimationFrame++;
    //         if ( stardustAnimationFrame == maxStartDustAnimationFrame ) {
    //             stardustAnimationRunning = false;
    //         }
    //     }

    // }

    // if ( pointsAnimationRunning ) {

    //     pointsFrameAcum += delta;
    //     if ( pointsFrameAcum >= pointsFrameTime ) {
    //         pointsAnimationRunning = false;
    //     }

    // }

}

void QuestionBlock::draw() {
    if (coinAnimationRunning) {
        
    }

    // Vẽ hiệu ứng stardust nếu có
    if (stardustAnimationRunning) {

    }

    if (pointsAnimationRunning) {
        std::string pointsStr = "guiPoints" + std::to_string(stardustAnimationFrame);
        Texture2D& tex = ResrcManager::GetInstance().getTexture(pointsStr);
        DrawTexture(tex,
            pos.x + size.x / 2 - tex.width / 2,
            pos.y - size.y / 2 - tex.height - (20 * pointsFrameAcum / pointsFrameTime),
            WHITE);
    }

    // Vẽ block (trạng thái chưa bị hit hoặc đã bị hit)
    if (hit) {
        DrawTexture(ResrcManager::GetInstance().getTexture("BLOCK_STONE"), this->pos.x, this->pos.y, WHITE);
    } else {
        DrawTexture( ResrcManager::GetInstance().getTexture(std::string( TextFormat( "BLOCK_QUESTION_%d", currentFrame ) )), pos.x, pos.y, WHITE );
    }

    // Vẽ overlay nếu có màu
    // if (color.a != 0) {
    //     DrawRectangle(this->pos.x, this->pos.y, this->size.x, this->size.y, Fade(this->color, 0.5f));
    // }
}


void QuestionBlock::doHit( Mario& mario, Map *map ) {
    if ( !hit ) {
        //PlaySound( ResrcManager::GetInstance().getSound()["coin"] );
        hit = true;
        coinAnimationRunning = true;
        coinY = pos.y;
    }
}
