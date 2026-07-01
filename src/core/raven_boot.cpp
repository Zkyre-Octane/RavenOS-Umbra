#include "raven_boot.h"
#include "hal/raven_display.h"
#include "images/raven_Logo.h"
#include <core/raven_sound.h>
#include "config/raven_pins.h"

// instantiate sound manager used by the boot screen
static SoundManager sound(PIN_BUZZER, PWM_CHANNEL_SOUND);

BootScreen::BootScreen(DisplayManager* display) {
    _display = display;
}

void BootScreen::show() {

    _display->ravenClearDisplay();
    _display->ravenDrawBitmap(32, 5, raven_logo, 64, 64);
    _display->ravenSetTextColor(SSD1306_WHITE);
    _display->ravenHeaderText("RavenOS", 40);
    _display->ravenRefresh();
    sound.ravenSoundBoot(); // Play boot sound sequence
    delay(2000); 
    _display->ravenClearDisplay();
    _display->ravenThemeInvertOn();
    _display ->ravenDrawBitmap(30, 8, raven_logo, 64, 64);
    _display->ravenHeaderText("UMBRA", 40);
    _display->ravenRefresh();
}