#include <raven_display.h>

DisplayManager::DisplayManager(Adafruit_SSD1306* display) { // Constructor to initialize the display manager with the provided display object
    _display = display; // Initialize the display object
}


// System display
void DisplayManager::ravenBootScreen() {
    _display->clearDisplay(); //clear the initial buffer
    _display->setCursor(4,4); //sets the cursor to the top of the screen
    _display->setTextSize(1); //sets the text size to 1
    _display->print("RavenOS Umbra"); //prints the os name
    _display->display(); //displays the buffer on the screen
}

void DisplayManager::ravenShowMessage(const char* msg, int line) {
    int y = line * 10; // Calculate y position based on line number
    _display->setCursor(0, y); // set the cursor at the indicated line
    _display->print(msg); // print the specified message 
}

void DisplayManager::ravenClearDisplay() {
    _display->clearDisplay(); // Clear the display 
}

void DisplayManager::ravenRefresh() {
    _display->display(); // Refresh the display with current buffer content
}

// Header System
void DisplayManager::ravenDrawHeader() {
    _display->drawRect(0, 0, 128, 16, SSD1306_WHITE); // Draw a rectangle at the top of the screen
}

void DisplayManager::ravenHeaderText(const char* text) {
    _display->setCursor(4, 4); // Set the cursor to the top of the screen
    _display->print(text); // Print the header text
}

void DisplayManager::ravenHeaderIcon(const uint8_t* bitmap, int width, int height, int x, int y) {
    _display->drawBitmap(x, y, bitmap, width, height, SSD1306_WHITE); // Draw the header icon at the specified position
}

// Display control functions
void DisplayManager::ravenThemeInvertOn() {
    _display->invertDisplay(true); // Invert the display colors
}

void DisplayManager::ravenThemeInvertOff() {
    _display->invertDisplay(false); // Revert the display colors to normal
}

// Drawing primitives
void DisplayManager::ravenPixel(int x, int y) {
    _display->drawPixel(x, y, SSD1306_WHITE); // Draw a pixel at the specified coordinates
}

void DisplayManager::ravenHorizontalLine(int y, int length) {
    _display->drawFastHLine(0, y, length, SSD1306_WHITE); // Draw a horizontal line at the specified coordinates
}

void DisplayManager::ravenVerticalLine(int x, int length) {
    _display->drawFastVLine(x, 0, length, SSD1306_WHITE); // Draw a vertical line at the specified coordinates
}

void DisplayManager::ravenDrawRect(int x, int y, int width, int height) {
    _display->drawRect(x, y, width, height, SSD1306_WHITE); // Draw a rectangle at the specified coordinates
}

void DisplayManager::ravenFillRect(int x, int y, int width, int height) {
    _display->fillRect(x, y, width, height, SSD1306_WHITE); // Fill a rectangle at the specified coordinates
}

void DisplayManager::ravenRoundRect(int x, int y, int width, int height, int radius) {
    _display->drawRoundRect(x, y, width, height, radius, SSD1306_WHITE); // Draw a rounded rectangle at the specified coordinates
}

void DisplayManager::ravenFillRoundRect(int x, int y, int width, int height, int radius) {
    _display->fillRoundRect(x, y, width, height, radius, SSD1306_WHITE); // Fill a rounded rectangle at the specified coordinates
}

void DisplayManager::ravenSetCursor(int x, int y) {
    _display->setCursor(x, y); // Set the cursor position
}

void DisplayManager::ravenDrawBitmap(int x, int y, const uint8_t* bitmap, int width, int height) {
    _display->drawBitmap(x, y, bitmap, width, height, SSD1306_WHITE); // Draw a bitmap at the specified coordinates
}

// Text helpers ***BETA***
void DisplayManager::ravenCenterText(const char* text, int y) {
    int16_t x1, y1; // Variables to hold the bounding box coordinates
    uint16_t w, h; // Variables to hold the width and height of the text
    _display->getTextBounds(text, 0, y, &x1, &y1, &w, &h); // Get the bounding box of the text
    int x = (128 - w) / 2; // Calculate the x position to center the text
    _display->setCursor(x, y); // Set the cursor to the calculated position
    _display->print(text); // Print the centered text
}

void DisplayManager::ravenRightText(const char* text, int y) {
    int16_t x1, y1; // Variables to hold the bounding box coordinates
    uint16_t w, h; // Variables to hold the width and height of the text
    _display->getTextBounds(text, 0, y, &x1, &y1, &w, &h); // Get the bounding box of the text
    int x = 128 - w; // Calculate the x position to right-align the text
    _display->setCursor(x, y); // Set the cursor to the calculated position
    _display->print(text); // Print the right-aligned text
}

void DisplayManager::ravenLineText(const char* text, int line) {
    int y = line * 10; // Calculate y position based on line number
    _display->setCursor(0, y); // Set the cursor at the indicated line
    _display->print(text); // Print the specified text
}

void DisplayManager::ravenSetTextSize(int size) {
    _display->setTextSize(size); // Set the text size
}

// Area control
void DisplayManager::ravenCleanArea(int x, int y, int width, int height) {
    _display->fillRect(x, y, width, height, SSD1306_BLACK); // Clean a specific area of the display by filling it with black
}