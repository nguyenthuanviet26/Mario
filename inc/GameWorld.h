#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include "raylib.h"
#include "Mario.h"

#include "GameClock.h"
#include "Tile.h"
#include "Map.h"
#include "ResrcManager.h"
#include "MediatorCollision.h"


class GameWorld {
    private:
        static constexpr float gravity = 200;
        Texture2D background = ResrcManager::GetInstance().getTexture("BACKGROUND_0");
        Map map;
        float currBackgroundStarX = 0.0f;

        MediatorCollision mediatorCollision;
        Mario player;
        Camera2D camera;
        std::vector<Tile*> &interactiveTiles;
    public:
        GameWorld();
        ~GameWorld();

        void UpdateWorld();
        void DrawWorld();

        static const float GetGravity();
        static void Init();
};
#endif // GAMEWORLD_H