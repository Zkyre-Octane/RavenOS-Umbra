#include <raven_display.h>

DisplayManager::DisplayManager(Adafruit_SSD1306* display) { // Constructor to initialize the display manager with the provided display object
    _display = display; // Initialize the display object
}

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

void DisplayManager::ravenDrawHeader() {
    _display->drawRect(0, 0, 128, 16, SSD1306_WHITE); // Draw a rectangle at the top of the screen
}

void DisplayManager::ravenHeaderText(const char* text) {
    _display->setCursor(4, 4); // Set the cursor to the top of the screen
    _display->print(text); // Print the header text
}

void DisplayManager::ravenRefresh() {
    _display->display(); // Refresh the display with current buffer content
}