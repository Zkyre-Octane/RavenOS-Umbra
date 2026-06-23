#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class DisplayManager {
  public:
    DisplayManager(Adafruit_SSD1306* display);

    // System display
    void ravenBootScreen();  // Shows boot screen
    void ravenShowMessage(const char* msg, int line);  // Show message on specific line
    void ravenClearDisplay();  // Clear the display
    void ravenRefresh(); // Refresh the display with current buffer content

    // Display control functions
    void ravenThemeInvertOn(); // Invert the display colors
    void ravenThemeInvertOff(); // Revert the display colors to normal
    /*
    void ravenFadein(int delay); // Fade in effect
    void ravenFadeout(int delay); // Fade out effect
    void ravenAnimate(const uint8_t* bitmap, int width, int height, int x, int y, int delay); // Animate bitmap at specified position 
    */

    //Header System
    void ravenDrawHeader(); // Draw header box 
    void ravenHeaderText(const char* text); // print header text
    void ravenHeaderIcon(const uint8_t* bitmap, int width, int height, int x, int y); // Draw header icon

    //Drawing primitives
    void ravenPixel(int x, int y); // Draw a pixel at specified coordinates
    void ravenHorizontalLine(int y, int length); // Draw a line at specified coordinates
    void ravenVerticalLine(int x, int length); // Draw a vertical line at specified coordinates
    void ravenDrawRect(int x, int y, int width, int height); // Draw a rectangle at specified coordinates
    void ravenFillRect(int x, int y, int width, int height); // Fill a rectangle at specified coordinates
    void ravenRoundRect(int x, int y, int width, int height, int radius); // Draw a rounded rectangle at specified coordinates
    void ravenFillRoundRect(int x, int y, int width, int height, int radius); // Fill a rounded rectangle at specified coordinates
    void ravenSetCursor(int x, int y); // Set cursor position
    void ravenDrawBitmap(int x, int y, const uint8_t* bitmap, int width, int height); // Draw bitmap at specified coordinates

    // Text helpers
    void ravenCenterText(const char* text, int y); // Center text at specified y position
    void ravenRightText(const char* text, int y); // Right align text at specified y position
    void ravenLineText(const char* text, int line); // Print text at specified line
    void ravenSetTextSize(int size); // Set text size
    
    // Area control
    void ravenCleanArea(int x, int y, int width, int height); // Clean specific area of the display

  private:
    Adafruit_SSD1306* _display;
};

#endif