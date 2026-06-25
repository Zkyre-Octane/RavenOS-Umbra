#ifndef RAVEN_INPUT_H
#define RAVEN_INPUT_H

#include <Arduino.h>

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
    InputEngine(int upPin, int downPin, int leftPin, int rightPin,
                int enterPin, int escapePin);

    void init();                 // Setup GPIOs
    RavenInputEvent poll();      // Returns ONE event per call
    bool isPressed(RavenInputEvent ev); // Optional helper

private:
    int _up, _down, _left, _right, _enter, _escape;

    bool readButton(int pin);    // Debounced read
};

#endif
