#include "raven_display.h"
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire);
DisplayManager ravenDisplay(&display);

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    ravenDisplay.ravenBootScreen();
}

void loop() {
}
