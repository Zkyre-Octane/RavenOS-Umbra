#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#include "hal/raven_display.h"
#include "core/raven_sound.h"
#include "core/raven_input.h"

#include "config/raven_DisplayConfig.h"
#include "config/raven_pins.h"

#include "core/raven_boot.h"

// Sreen setup
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DisplayManager dm(&display);
BootScreen bootScreen(&dm);

// Sound setup
SoundManager sound(PIN_BUZZER, PWM_CHANNEL_SOUND);   // GPIO 25, PWM channel 0

// Input Setup
InputEngine input(PIN_UP, PIN_DOWN, PIN_LEFT, PIN_RIGHT, PIN_ENTER, PIN_ESCAPE);

// Setup
void setup() {
    Serial.begin(115200);
    Wire.begin();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    sound.ravenSoundInit();
    bootScreen.show();
}

// Loop

void loop() {
    
}