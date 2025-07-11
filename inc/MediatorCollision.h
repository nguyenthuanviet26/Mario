#pragma once
#include "Object.h"
#include "Mario.h"
#include "CollisionProbe.h"
#include "Tile.h"
#include "Fireball.h"
#include "Item.h"

// class Mario; // Forward declaration
// class Tile; // Forward declaration
// class Fireball; // Forward declaration

class MediatorCollision {
    private:
        void HandleMarioWithTile(Mario*& mario, Tile*& tile, CollisionType AtoB);
        void HandleFireballWithTile(Fireball*& fireball, Tile*& tile, CollisionType AtoB);
    public:
        MediatorCollision() = default; // Ensure default constructor exists
        ~MediatorCollision() = default;

        void HandleCollision(Object* ObjectA, Object* ObjectB);
};
