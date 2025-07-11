
#pragma once

#include "raylib.h"
#include "Block.h"

class EyesClosedBlock : public Block {

public:

    EyesClosedBlock( Vector2 pos, Vector2 dim, Color color );
    EyesClosedBlock( Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames );
    ~EyesClosedBlock() override;

    void Update() override;
    void draw() override;

};