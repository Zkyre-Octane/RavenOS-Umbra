<p align="center">
  <img src="https://github.com/Zkyre-Octane/RavenOS-Umbra/blob/main/assets/logo/RavenOS_Umbra_logo.png">
</p>

# RavenOS Umbra  
A next‑generation embedded OS for ESP32/Arduino featuring a modular UI framework, smooth animations, and a 5‑button input system.

RavenOS Umbra is the expanded, feature‑rich evolution of the original **RavenOS‑Core**.  
Where Core focuses on minimalism and simplicity, Umbra introduces:

- A complete UI layer  
- A structured animation engine  
- A directional input system  
- A modular subsystem architecture  
- A clean, documented SDK‑style API  

Umbra is ideal for embedded projects requiring:

- Multi‑screen UI  
- Menus and navigation  
- Icons, headers, and structured layouts  
- Smooth transitions and animations  
- Responsive 5‑button input  

If you need a tiny OS with only display helpers, choose **RavenOS‑Core**.  
If you want a full embedded UI system, choose **Umbra**.

---

# Key Features

## 5‑Button Input System
- Up, Down, Left, Right, Enter/Escape  
- Active‑low button handling  
- Internal pull‑up configuration  
- Clean `RavenInputEvent` enum  
- `poll()` returns **one event per call**  
- Optional `isPressed()` for continuous input  
- Fully isolated subsystem (`raven_input.h/.cpp`)

## Umbra UI Framework
- Menus  
- Selectors  
- Panels  
- Headers  
- Dialogs  
- Reusable UI components  
- UI state machine

## Animation Engine
- Slide transitions  
- Fade‑in / fade‑out  
- Timed animations  
- Frame‑based rendering  
- Works directly with DisplayManager

## Optimized Display Manager
- Region‑based clearing  
- Partial redraws  
- Icon rendering  
- Text alignment helpers  
- Boot screen utilities  
- SSD1306‑optimized drawing

## Modular Architecture
Umbra is built from **isolated subsystems**, each with its own `.h` and `.cpp`:

- Display Engine  
- Input Engine  
- Sound Engine  
- UI Engine  

No cross‑dependencies.  
No spaghetti.  
No hidden logic.

## Asset Support
- Icons  
- Bitmaps  
- Fonts  
- UI elements  
Stored under `/assets`.

---

# Architecture Overview

Umbra is organized into three core modules:

## DisplayManager
Responsible for all rendering operations:
- Headers  
- Icons  
- Text alignment  
- Bitmaps  
- Partial redraws  
- Animation frames  

## InputEngine
Handles 5‑button input:
- Debouncing  
- Active‑low reads  
- Event generation  
- `poll()` and `isPressed()`  
- Zero UI logic  

## UmbraUI
High‑level UI components:
- Menus  
- Selectors  
- Panels  
- Animated transitions  
- UI state machine  

---

# Project Structure

RavenOS-Umbra/
│
├── src/
│   ├── raven_display.cpp
│   ├── raven_display.h
│   ├── raven_input.cpp
│   ├── raven_input.h
│   ├── raven_sound.cpp
│   ├── raven_sound.h
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


---

# Getting Started

## Requirements
- ESP32 development board  
- SSD1306 OLED display  
- PlatformIO or Arduino IDE  
- Adafruit GFX + SSD1306 libraries  

Relationship to RavenOS‑Core
Umbra is not a version update — it is a larger, more capable OS built on the same design principles.

| Project | Purpose | Size | Features |
| --- | --- | --- | --- |
| RavenOS‑Core | Minimal display helpers | Tiny | Basic drawing + text |
| RavenOS Umbra | Full UI/UX embedded OS | Larger | UI engine, animations, input |

Credits
RavenOS Umbra is developed by NyxOverflow Also known as Zkyre‑Octane and contributors.
Designed with the RavenLabs philosophy: clean, modular, documented, and developer‑friendly.

## Basic Example
```cpp
#include "raven_display.h"
#include "raven_input.h"
#include "raven_ui.h"

DisplayManager displayManager(&display);
InputEngine inputEngine(PIN_UP, PIN_DOWN, PIN_LEFT, PIN_RIGHT, PIN_ENTER, PIN_ESCAPE);
UmbraUI ui(&displayManager, &inputEngine);

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    inputEngine.init();
    displayManager.ravenBootScreen();
}

void loop() {
    RavenInputEvent ev = inputEngine.poll();
    ui.update(ev);
}
