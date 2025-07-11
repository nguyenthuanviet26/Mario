#pragma once
#include "Object.h"
#include "Mario.h"
#include "CollisionProbe.h"
#include "Tile.h"
#include "Fireball.h"
#include "Block.h"
#include "CloudBlock.h"
#include "QuestionBlock.h"
#include "WoodBlock.h"
#include "GlassBlock.h"
#include "EyesOpenedBlock.h"
#include "EyesClosedBlock.h"
// class Mario; // Forward declaration
// class Tile; // Forward declaration
// class Fireball; // Forward declaration

class MediatorCollision {
    private:
        void HandleMarioWithTile(Mario*& mario, Tile*& tile, CollisionType AtoB);
        void HandleFireballWithTile(Fireball*& fireball, Tile*& tile, CollisionType AtoB);
        void HandleMarioWithQuestionBlock(Mario*& mario, Block*& questionBlock, CollisionType AtoB);
        void HandleMarioWithCloudBlock(Mario*& mario, CloudBlock*& cloudBlock, CollisionType AtoB);
        void HandleMarioWithWoodBlock(Mario*& mario, WoodBlock*& woodBlock, CollisionType AtoB);
        void HandleMarioWithGlassBlock(Mario*& mario, GlassBlock*& glassBlock, CollisionType AtoB);
        void HandleMarioWithEyesOpenedBlock(Mario*& mario, EyesOpenedBlock*& eyesOpenedBlock, CollisionType AtoB);
        void HandleMarioWithEyesClosedBlock(Mario*& mario, EyesClosedBlock*& eyesClosedBlock, CollisionType AtoB);
    public:
        MediatorCollision() = default; // Ensure default constructor exists
        ~MediatorCollision() = default;

        void HandleCollision(Object* ObjectA, Object* ObjectB);
};
