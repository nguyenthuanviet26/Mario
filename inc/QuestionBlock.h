
#pragma once
#include "ResrcManager.h"
#include "raylib.h"
#include "Block.h"
#include "Mario.h"
#include "Map.h"

class QuestionBlock : public Block {

    float coinAnimationTime;
    float coinAnimationAcum;
    float coinFrameAcum;
    int coinAnimationFrame;
    bool coinAnimationRunning;
    float coinY;
    float coinVelY;

    float stardustAnimationTime;
    float stardustAnimationAcum;
    int stardustAnimationFrame;
    int maxStartDustAnimationFrame;
    bool stardustAnimationRunning;

    float pointsFrameAcum;
    float pointsFrameTime;
    bool pointsAnimationRunning;


public:

    QuestionBlock( Vector2 pos, Vector2 dim, Color color );
    QuestionBlock( Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames );
    ~QuestionBlock() override;

    void Update() override;
    void draw() override;
    void doHit( Mario& mario, Map *map ) override;
    bool isQuestionBlock()  { return true; } // Override to indicate this is a QuestionBlock

};