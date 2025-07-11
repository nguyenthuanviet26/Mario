#pragma once
#include "ScreenController.h"

class ScreenController; // Forward declaration
class Screen {
    public:
        ScreenController* screenController;

        
        Screen(ScreenController* controller);
        virtual ~Screen() = default;
        virtual void Update() = 0;
        virtual void Draw() = 0;
};