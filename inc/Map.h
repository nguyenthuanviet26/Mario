#pragma once
#include "raylib.h"
#include "Drawable.h"
#include "Object.h"
#include "Tile.h"
#include "Coin.h"
#include <vector>
#include "ResrcManager.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <memory>
#include "CourseClearToken.h"
#include "FireFlower.h"


class Map : public Drawable {
    private:
        int currentMap;
        float width;
        const float height = 900.0f; 
        float currBackgroundStarX;
        Texture2D background;
        std::vector<Tile*> interactiveTiles;
        std::vector<Tile*> nonInteractiveTiles;
        std::vector<std::shared_ptr<Coin>> interactiveCoins;
        std::vector<std::shared_ptr<CourseClearToken>> interactiveCourseClearTokens;
        std::vector<std::shared_ptr<FireFlower>> interactiveFireFlowers;
        void LoadFromJsonFile(const std::string& filename);
    public:
        Map();
        ~Map();
        std::vector<Tile*>& getInteractiveTiles();
        std::vector<std::shared_ptr<Coin>>& getInteractiveCoins();
        std::vector<std::shared_ptr<CourseClearToken>>& getInteractiveCourseClearTokens();
        std::vector<std::shared_ptr<FireFlower>>& getInteractiveFireFlowers();
        float GetWidth() const;
        void nextMap();
        void LoadMap(int mapIndex);
        void draw() override;
};