#ifndef RAVEN_INPUT_H
#define RAVEN_INPUT_H

#include <Arduino.h>

/*
    RavenOS Core — Input Engine
    --------------------------------
    The InputEngine provides a clean, isolated interface for reading
    directional and action buttons on RavenOS devices.

    Design Philosophy:
    - No UI logic
    - No display logic
    - No sound logic
    - No dependencies on other subsystems

    The engine simply converts raw GPIO button states into high-level
    RavenInputEvent values. This keeps the input layer predictable,
    portable, and easy to integrate with any UI or system module.
*/

// High-level input events returned by the engine
enum RavenInputEvent {
    RAVEN_NONE,
    RAVEN_UP,
    RAVEN_DOWN,
    RAVEN_LEFT,
    RAVEN_RIGHT,
    RAVEN_ENTER,
    RAVEN_ESCAPE
};

class InputEngine {
public:
    /*
        Constructor
        --------------------------------
        Stores the GPIO pins for each button.

        All buttons are expected to be wired as:
        - Active LOW (button pulls pin to GND)
        - INPUT_PULLUP enabled
    */
    InputEngine(int upPin, int downPin, int leftPin, int rightPin,
                int enterPin, int escapePin);

    // Initialize GPIO modes (INPUT_PULLUP)
    void init();

    // Polls the buttons and returns ONE event per call
    RavenInputEvent poll();

    // Optional helper: check if a specific button is currently pressed
    bool isPressed(RavenInputEvent ev);

private:
    int _up, _down, _left, _right, _enter, _escape;

    // Reads a button with basic debouncing behavior
    bool readButton(int pin);
};

#endif
