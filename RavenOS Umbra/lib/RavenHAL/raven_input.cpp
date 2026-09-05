#include "raven_input.h"

InputEngine::InputEngine(
    int upPin, 
    int downPin, 
    int leftPin, 
    int rightPin,                
    int enterPin, 
    int escapePin) {
    _up = upPin;
    _down = downPin;
    _left = leftPin;
    _right = rightPin;
    _enter = enterPin;
    _escape = escapePin;
}

/*
   init()
   Configures all input pins as INPUT_PULLUP.

   Buttons must be wired active-low:
   - Released = HIGH
   - Pressed  = LOW

   NOTE: remember to use GPIOs with internal pull-up support, or add an external pull-up resistor,
   check the documentation for your specific board.
*/
void InputEngine::init() {
    pinMode(_up, INPUT_PULLUP);
    pinMode(_down, INPUT_PULLUP);
    pinMode(_left, INPUT_PULLUP);
    pinMode(_right, INPUT_PULLUP);
    pinMode(_enter, INPUT_PULLUP);
    pinMode(_escape, INPUT_PULLUP);
}

/*
   readButton(pin)
   Returns true if the button is pressed.
*/
bool InputEngine::readButton(int pin) {
    return digitalRead(pin) == LOW;
}

/*
   Checks all buttons in priority order and returns the first
   detected event.

   This ensures enter and escape are prioritized over directional input.
*/
RavenInputEvent InputEngine::poll() {
    if (readButton(_enter))  return RAVEN_ENTER;
    if (readButton(_escape)) return RAVEN_ESCAPE;
    if (readButton(_up))     return RAVEN_UP;
    if (readButton(_down))   return RAVEN_DOWN;
    if (readButton(_left))   return RAVEN_LEFT;
    if (readButton(_right))  return RAVEN_RIGHT;

    return RAVEN_NONE;
}

/*
   isPressed(event)
   Directly checks the state of a specific button.
*/
bool InputEngine::isPressed(RavenInputEvent ev) {
    switch (ev) {
        case RAVEN_UP:     return readButton(_up);
        case RAVEN_DOWN:   return readButton(_down);
        case RAVEN_LEFT:   return readButton(_left);
        case RAVEN_RIGHT:  return readButton(_right);
        case RAVEN_ENTER:  return readButton(_enter);
        case RAVEN_ESCAPE: return readButton(_escape);
        default:            return false;
    }
}
