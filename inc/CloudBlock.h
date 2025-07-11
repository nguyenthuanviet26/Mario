
#pragma once

#include "raylib.h"
#include "Block.h"

class CloudBlock : public Block {

public:

    CloudBlock( Vector2 pos, Vector2 size, Color color );
    CloudBlock( Vector2 pos, Vector2 size, Color color, float frameTime, int maxFrames );
    ~CloudBlock() override;

    void Update() override ;
    void draw() override;

};