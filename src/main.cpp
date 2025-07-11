#include "raylib.h"
#include "ResrcManager.h"
#include "GameWorld.h"
#include "Mario.h"
#include "GameClock.h"
#include <iostream>
int main() {
    InitWindow(1600, 900, "Mario Game");
    InitAudioDevice();

    SetTargetFPS(60);
    bool isPaused = false;
    ResrcManager::GetInstance().loadResources();

    // // Create a Mario instance
    // Mario mario(Vector2{100, 100}, 3, SMALL);
    GameWorld::Init(); // Initialize game world resources - Call Resource Manager to load textures, sounds, etc.   
    GameWorld gameWorld; // Create a game world instance
    while(!WindowShouldClose()) {
        // if (IsKeyPressed(KEY_P)) {
        //     isPaused = !isPaused;
        // }

        // if (!isPaused) {
            GameClock::getInstance().updateTimeAcum += GetFrameTime();

        // }
        
        gameWorld.UpdateWorld(); // Update game world
        BeginDrawing();
        ClearBackground(RAYWHITE);
        gameWorld.DrawWorld();
        // mario.draw(); // Draw Mario
        // mario.UpdateStateAndPhysic(); // Update Mario's state and physics
        EndDrawing();
    }
}