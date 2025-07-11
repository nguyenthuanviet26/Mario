#pragma once

#include "Object.h"
#include "ResrcManager.h"
#include <string>

enum TileType {

    TILE_TYPE_SOLID,
    TILE_TYPE_SOLID_ONLY_FOR_BADDIES,
    TILE_TYPE_NON_SOLID,
    TILE_TYPE_SOLID_FROM_ABOVE,
    TILE_TYPE_SLOPE_UP,     //   /
    TILE_TYPE_SLOPE_DOWN    //   \

};

class Tile : public Object {
    private:
        void Update() override{};
        TileType type;
    public:
        Tile(Vector2 pos,int map,  int key, TileType type);
        void draw() override;
        TileType getType() const;
    };