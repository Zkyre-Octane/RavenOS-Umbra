#pragma once

#include "hal/raven_display.h"

class BootScreen {
public:
    BootScreen(DisplayManager* display);
    void show();

private:
    DisplayManager* _display;
};