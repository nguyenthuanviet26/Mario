#include "GameClock.h"
GameClock *GameClock::instance = nullptr;
GameClock &GameClock::getInstance()
{
    if(instance == nullptr) {
        instance = new GameClock();
        instance->updateTimeAcum = 0.0;
    }
    return *instance;
}




