#pragma once

#include "Object.h"
#include "ResrcManager.h"
#include <string>

class Tile : public Object {
    private:
        void Update() override{};
    
    public:
        Tile(Vector2 pos,int map,  int key);
        void draw() override;
        
    };