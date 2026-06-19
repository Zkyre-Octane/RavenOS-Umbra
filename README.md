<p align="center">
  <img src="https://github.com/Zkyre-Octane/RavenOS-Umbra/blob/main/assets/logo/RavenOS_Umbra_logo.png">
</p>

RavenOS Umbra
A next‑generation embedded OS for ESP32/Arduino featuring a modular UI framework, smooth animations, and a 5‑button input system.

RavenOS Umbra is the expanded, feature‑rich evolution of the original RavenOS‑Core.
Where the Core focuses on minimalism and simplicity, Umbra introduces a complete UI layer, animation engine, and multi‑button navigation — while preserving the same clean architecture and developer‑friendly design philosophy.

Umbra is ideal for embedded projects requiring:

Multi‑screen UI

Menus and navigation

Icons, headers, and structured layouts

Smooth transitions and animations

Responsive 5‑button input

If you need a tiny OS with only display helpers, choose RavenOS‑Core.
If you want a full embedded UI system, choose Umbra.

Key Features
5‑Button Input System
Up, Down, Left, Right, Select

Debouncing

State tracking

Event callbacks

Navigation helpers

Umbra UI Framework
Menus

Selectors

Panels

Headers

Dialogs

Reusable UI components

Animation Engine
Slide transitions

Fade‑in / fade‑out

Timed animations

Frame‑based rendering

Optimized Display Manager
Region‑based clearing

Partial redraws

Icon rendering

Text alignment helpers

Modular Architecture
Clean separation between display, input, and UI layers

Asset Support
Icons, bitmaps, fonts, and UI elements stored in /assets

Architecture Overview
Umbra is organized into three core modules:

DisplayManager
Responsible for all rendering operations:

Headers

Icons

Text alignment

Bitmaps

Partial redraws

Animation frames

InputManager
Handles 5‑button input:

Debouncing

State tracking

Event callbacks

Navigation helpers

UmbraUI
High‑level UI components:

Menus

Selectors

Panels

Animated transitions

UI state machine

Project Structure
Code
RavenOS-Umbra/
│
├── src/
│   ├── raven_display.cpp
│   ├── raven_display.h
│   ├── raven_input.cpp
│   ├── raven_input.h
│   ├── raven_ui.cpp
│   ├── raven_ui.h
│   ├── main.cpp
│
├── assets/
│   ├── icons/
│   └── fonts/
│
├── include/
├── lib/
├── test/
└── platformio.ini
Getting Started
Requirements
ESP32 or Arduino board

SSD1306 OLED display

PlatformIO or Arduino IDE

Adafruit GFX + SSD1306 libraries

Basic Example
cpp
#include "raven_display.h"
#include "raven_input.h"
#include "raven_ui.h"

DisplayManager displayManager(&display);
InputManager inputManager;
UmbraUI ui(&displayManager, &inputManager);

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    inputManager.begin();
    displayManager.ravenBootScreen();
}

void loop() {
    inputManager.update();
    ui.update();
}
Relationship to RavenOS‑Core
Umbra is not a version update — it is a larger, more capable OS built on the same design principles.
| Project | Purpose | Size | Features |
| --- | --- | --- | --- |
| RavenOS‑Core | Minimal display helpers | Tiny | No UI, no input, no animations |
| RavenOS Umbra | Full embedded UI system | Larger | Menus, animations, 5‑button input, transitions |
