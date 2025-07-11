
#pragma once

#include "raylib.h"
#include "Block.h"
#include "Mario.h"

class EyesOpenedBlock : public Block {

private:
    float animationTime;
    float animationAcum;

public:

    EyesOpenedBlock( Vector2 pos, Vector2 dim, Color color );
    EyesOpenedBlock( Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames );
    ~EyesOpenedBlock() override;

    void Update() override;
    void draw() override;
    void doHit( Mario& mario, Map *map ) override;

};