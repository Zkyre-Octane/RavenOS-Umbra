#ifndef RAVEN_INPUT_H
#define RAVEN_INPUT_H

#include <Arduino.h>

// High-level input events returned by the engine
enum RavenInputEvent {
    RAVEN_NONE,  // No input detected
    RAVEN_UP,    // Up button 
    RAVEN_DOWN,  // Down button 
    RAVEN_LEFT,  // Left button 
    RAVEN_RIGHT, // Right button 
    RAVEN_ENTER, // Enter button 
    RAVEN_ESCAPE // Escape button 
};

class InputEngine {
public:
    /*
       All buttons are expected to be wired as:
       - Active LOW (button pulls pin to GND)
       - INPUT_PULLUP enabled
    */
    InputEngine(
      int upPin,
      int downPin,
      int leftPin,
      int rightPin,
      int enterPin,
      int escapePin);

    void init(); //Initialize GPIO modes (INPUT_PULLUP)
    
    RavenInputEvent poll(); //Polls the buttons and returns ONE event per call

    bool isPressed(RavenInputEvent ev); //check if a specific button is currently pressed

private:
    int 
    _up,
    _down,
    _left,
    _right,
    _enter,
    _escape;

    bool readButton(int pin); //Reads a button with basic debouncing behavior
};

#endif
