
#pragma once

#include "raylib.h"
#include "Block.h"

class WoodBlock : public Block {

public:

    WoodBlock( Vector2 pos, Vector2 dim, Color color );
    WoodBlock( Vector2 pos, Vector2 dim, Color color, float frameTime, int maxFrames );
    ~WoodBlock() override;

    void Update() override;
    void draw() override;

};