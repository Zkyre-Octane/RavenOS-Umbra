#include <Arduino.h>
#include <Wire.h>
#include "raven_display.h"
#include "raven_sound.h"
#include "raven_input.h"
#include "raven_DisplayConfig.h"
#include "raven_pins.h"
#include "raven_boot.h"
#include "raven_screen_demo.h"

// Display Setup
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DisplayManager dm(&display);
BootScreen bootScreen(&dm);
ScreenDemo screenDemo(&dm);

// Sound Setup
SoundManager sound(PIN_BUZZER, PWM_CHANNEL_SOUND);

// Input Setup
InputEngine input(PIN_UP, PIN_DOWN, PIN_LEFT, PIN_RIGHT, PIN_ENTER, PIN_ESCAPE);

// Setup
void setup() {
    Serial.begin(115200);
    Wire.begin();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    sound.ravenSoundInit();
    input.init();

    // Boot screen
    bootScreen.show();
    screenDemo.update();

}

// Loop — Input Test + Status Bar
void loop() {
    RavenInputEvent ev = input.poll();

    if (ev != RAVEN_NONE) {
        dm.ravenClearDisplay();
        dm.ravenSetTextSize(2);
        dm.ravenSetTextColor(SSD1306_WHITE);

        switch (ev) {
            case RAVEN_UP:
                dm.ravenCenterText("UP", 20);
                sound.ravenPlayTone(1200, 80);
                break;

            case RAVEN_DOWN:
                dm.ravenCenterText("DOWN", 20);
                sound.ravenPlayTone(300, 120);
                break;

            case RAVEN_LEFT:
                dm.ravenCenterText("LEFT", 20);
                sound.ravenPlayTone(800, 40);
                break;

            case RAVEN_RIGHT:
                dm.ravenCenterText("RIGHT", 20);
                sound.ravenPlayTone(900, 60);
                delay(80);
                sound.ravenPlayTone(900, 60);
                break;

            case RAVEN_ENTER:
                dm.ravenCenterText("ENTER", 20);
                sound.ravenPlayTone(1000, 120);
                break;

            case RAVEN_ESCAPE:
                dm.ravenCenterText("ESCAPE", 20);
                sound.ravenPlayTone(500, 150);
                break;

            default:
                dm.ravenCenterText("???", 20);
                break;
        }

        dm.ravenRefresh();
    }
/*
Low level button test, you may need a serial monitor to see the output, 
this is only for testing purposes and will be removed in future versions.
*/
Serial.print("UP=");
Serial.print(digitalRead(PIN_UP));
Serial.print(" ENTER=");
Serial.print(digitalRead(PIN_ENTER));
Serial.print(" ESC=");
Serial.println(digitalRead(PIN_ESCAPE));
Serial.print("DOWN=");
Serial.print(digitalRead(PIN_DOWN));
Serial.print(" LEFT=");
Serial.print(digitalRead(PIN_LEFT));
Serial.print(" RIGHT=");
Serial.println(digitalRead(PIN_RIGHT));


    delay(20);
}
