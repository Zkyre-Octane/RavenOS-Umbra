# Changelog

## 2026‑06‑17 — Initial Repository Upload
### Added
- main.cpp
- raven_display.cpp
- raven_display.h
- raven_ui.h

---

## 2026‑06‑22 — Added New Screen Utilities
### Added
- Header system APIs
- Display control functions
- Drawing primitives
- Text helpers for testing
- Area control utilities

### Changed
- Cleaned up repeated APIs

### Notes
- The text helper APIs are still in testing

---

## 2026‑06‑24 — Added Full SoundManager Documentation & Expanded Audio Suite
### Added
- New SoundManager documentation for both header and implementation files
- Detailed section headers and SDK‑style comments

- Introduced pairing melodies:
  - NFC pairing
  - ESP‑NOW pairing
  - WiFi pairing

### Added vehicle/FPV sound patterns:
- Arm sequence
- Disarm sequence
- Beacon locator pulse

### Added RavenOS Umbra sound identity patterns:
- Boot jingle
- Task complete
- Error tone
- Notification
- UI click

### Improved
- Unified tone generation through `ravenPlayTone()`
- Cleaned up melody timing and structure
- Organized `.cpp` into clear functional sections:
  - System sounds
  - Pairing sounds
  - Vehicle/FPV sounds

### Notes
This update establishes the RavenOS Core Audio Identity, shared across:
- Raven Node (Flipper Zero–based ESP32 module)
- Future RavenOS UGV systems
- Future RavenOS UAV systems

Volume control intentionally omitted — passive buzzers do not support real analog volume.  
A global sound ON/OFF toggle will be added in the System Config API.

---

## 2026‑06‑25 — Added InputEngine Subsystem (Directional + Action Buttons)
### Added
- New InputEngine subsystem (`raven_input.h` / `raven_input.cpp`)
- Clean, isolated API for directional and action buttons
- Support for:
  - UP
  - DOWN
  - LEFT
  - RIGHT
  - ENTER
  - ESCAPE
- Active‑low button handling with internal pull‑ups
- High‑level `RavenInputEvent` enum
- `poll()` method returning one event per call
- `isPressed()` helper for continuous input checks
- Fully documented header and implementation following RavenLabs SDK style

### Improved
- Input handling is now fully decoupled from:
  - Display logic
  - Sound logic
  - UI logic
- Eliminated previous input‑logic mixing issues
- Ensured compatibility with all RavenOS Core devices

### Notes
- GPIO 34–39 limitations documented (no internal pull‑ups)
- InputEngine now serves as the foundation for the upcoming RavenOS Menu Engine
- This subsystem completes the triad of isolated core engines:
  - Display Engine
  - Sound Engine
  - Input Engine
 
## 2026-06-30 — Core Refactor, Project Reorganization & BootScreen Module

### Added
New configuration layer:
raven_pins.h
raven_DisplayConfig.h
New BootScreen UI module
Bitmap boot logo 
Boot sound integrated into startup sequence
Battery icon assets
Project asset organization for UI resources

### Changed
Reorganized project into modular directories:
core/
hal/
config/
ui/
assets/
Simplified main.cpp by moving hardware configuration into dedicated config files
DisplayManager refactored into a lightweight SSD1306 wrapper
Removed experimental scheduler integration
Removed unfinished display redraw/tick system
Removed experimental text helper utilities
Separated BootScreen UI from the display driver

### Improved
Cleaner separation between:
Hardware Abstraction Layer (HAL)
Core runtime modules
Configuration files
UI modules
Prepared the codebase for future RavenOS applications without increasing runtime complexity

### Notes
RavenOS is now transitioning from a monolithic firmware toward a lightweight embedded runtime.
The display driver is now responsible only for rendering primitives, while UI composition is handled by dedicated modules such as BootScreen.
This refactor establishes the base architecture for future RavenOS devices including Raven Node, Raven Wraith and upcoming RavenLabs platforms.
