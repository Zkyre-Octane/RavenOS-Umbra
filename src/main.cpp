#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#include "raven_display.h"
#include "raven_sound.h"
#include "raven_input.h"   // <-- NEW

// Display Setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DisplayManager dm(&display);

// =====================
// Sound Setup (PASSIVE BUZZER)
// =====================
SoundManager sound(25, 0);   // GPIO 25, PWM channel 0

// =====================
// Input Setup
// =====================
// Adjust pins to your hardware
#define PIN_UP      32
#define PIN_DOWN    33
#define PIN_LEFT    14
#define PIN_RIGHT   12
#define PIN_ENTER   27
#define PIN_ESCAPE  26

InputEngine input(PIN_UP, PIN_DOWN, PIN_LEFT, PIN_RIGHT, PIN_ENTER, PIN_ESCAPE);

// =====================
// Helper: show label + play sound
// =====================
void testSound(const char* label, void (*func)()) {
    dm.ravenClearDisplay();
    dm.ravenSetTextSize(3);
    dm.ravenSetTextColor(SSD1306_WHITE);
    dm.ravenShowMessage(label, 0);
    dm.ravenRefresh();

    func();      // Play the sound
    delay(500);  // Pause between tests
}

// =====================
// Setup
// =====================
void setup() {
    Serial.begin(115200);

    // Init display
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    dm.ravenBootScreen();
    delay(800);

    // Init sound engine
    sound.ravenInit();

    // Init input engine
    input.init();

    // =====================
    // Run sound tests
    // =====================
    /*testSound("Boot Sound", [](){ sound.ravenSoundBoot(); });
    delay(500);
    testSound("Beep", [](){ sound.ravenSoundBeep(); });
    delay(500);
    testSound("Error Tone", [](){ sound.ravenSoundError(); });
    delay(500);
    testSound("Task Complete", [](){ sound.ravenSoundTaskComplete(); });
    delay(500);
    testSound("Shutdown Tone", [](){ sound.ravenSoundShutdown(); });
    delay(500);
    testSound("Notify", [](){ sound.ravenSoundNotify(); });
    delay(500);
    testSound("Click", [](){ sound.ravenSoundClick(); });
    delay(500);
    testSound("NFC Pair", [](){ sound.ravenSoundNfcPairing(); });
    delay(1000);
    testSound("ESP-NOW", [](){ sound.ravenSoundEspNowPairing(); });
    delay(1000);
    testSound("WiFi Pair", [](){ sound.ravenSoundWifiPairing(); });
    delay(500);
    testSound("Arm", [](){ sound.ravenSoundArm(); });
    delay(500);
    testSound("Disarm", [](){ sound.ravenSoundDisarm(); });
    delay(500);
    testSound("Beacon", [](){ sound.ravenSoundBeacon(); });*/

    // =====================
    // Switch to Input Test Mode
    // =====================
    dm.ravenClearDisplay();
    dm.ravenCenterText("Input Test Mode", 0);
    dm.ravenRefresh();
    delay(1000);
}

// =====================
// Loop — Input Test Mode
// =====================
void loop() {
    RavenInputEvent ev = input.poll();

    if (ev != RAVEN_NONE) {
        dm.ravenClearDisplay();
        dm.ravenSetTextSize(2);
        dm.ravenSetTextColor(SSD1306_WHITE);

        switch (ev) {
            case RAVEN_UP:
                dm.ravenCenterText("UP", 20);
                sound.ravenPlayTone(1200, 80);   // high beep
                break;

            case RAVEN_DOWN:
                dm.ravenCenterText("DOWN", 20);
                sound.ravenPlayTone(300, 120);   // low beep
                break;

            case RAVEN_LEFT:
                dm.ravenCenterText("LEFT", 20);
                sound.ravenPlayTone(800, 40);    // short click
                break;

            case RAVEN_RIGHT:
                dm.ravenCenterText("RIGHT", 20);
                sound.ravenPlayTone(900, 60);    // double beep
                delay(80);
                sound.ravenPlayTone(900, 60);
                break;

            case RAVEN_ENTER:
                dm.ravenCenterText("ENTER", 20);
                sound.ravenPlayTone(1000, 120);  // confirmation tone
                break;

            case RAVEN_ESCAPE:
                dm.ravenCenterText("ESCAPE", 20);
                sound.ravenPlayTone(500, 150);   // cancel tone
                break;

            default:
                dm.ravenCenterText("???", 20);
                break;
        }

        dm.ravenRefresh();
        delay(150); // debounce
    }
}

