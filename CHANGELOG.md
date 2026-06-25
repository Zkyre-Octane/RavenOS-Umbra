# Changelog

## 2026‑06‑17 - Initial Repository Upload
### Added
- main.cpp
- raven_display.cpp
- raven_display.h
- raven_ui.h

## 2026-06-22 - Added new screen utilities
### Added
- Header system APIs
- Display control functions
- Drawing primitives
- Text helpers for testing
- Area control utilities

### Changed
- Cleaned up repeated APIs

### Notes
- The text helpers APIs still on testing

## 2026-06-24 - Added Full SoundManager Documentation & Expanded Audio Suite
### Added
- New SoundManager documentation for both header and implementation files

- detailed section headers and SDK‑style comments

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
- Unified tone generation through ravenPlayTone()

- Cleaned up melody timing and structure

- Organized .cpp into clear functional sections:

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
