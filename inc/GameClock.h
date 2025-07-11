#pragma once
#include "raylib.h"

class GameClock { // Singleton class for managing game time
private:
    static GameClock *instance ; // Singleton instance
    // why we use a pointer here? Because we want to ensure that the instance is created only once and can be accessed globally.
    GameClock() = default;
    ~GameClock() = default;
public:
    static  GameClock &getInstance(); // Get the singleton instance
    double updateTimeAcum; // Accumulated time for updates
    // what is this used for? This is used to accumulate the time between frames so that we can update the game logic at a fixed time step.
    // example: if the game runs at 60 FPS, we want to update the game logic every 1/60 seconds.
    // so why updatetimeacum = 0.0? Because we want to start with no accumulated time and add the delta time from each frame to it.
    const double FIXED_TIME_STEP=1/60.0;

};


    