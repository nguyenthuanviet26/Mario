#pragma once
#include "Screen.h"

class Screen;
class ScreenController {
    private:
        Screen* currentScreen;
    public:
        ScreenController();
        ~ScreenController();
        void Update();
        void Draw();
        void ChangeScreen(Screen* newScreen);
};