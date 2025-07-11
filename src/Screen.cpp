#include "Screen.h"

Screen::Screen(ScreenController* controller) : screenController(controller) {
    // Constructor implementation
}


void Screen::Update() {
    // Default implementation, can be overridden by derived classes
}

void Screen::Draw() {
    // Default implementation, can be overridden by derived classes
    // This method should be implemented in derived classes to handle drawing
}