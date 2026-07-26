## Firmware

The firmware implements a hardware-level privacy slider switch for the Chronis AI Wearable.

### Features
- Interrupt-driven switch detection
- 50 ms debounce
- Hardware override for camera disable
- Camera cannot be enabled when the switch is OFF
- Simulation test included

### Files
- `privacy_switch.cpp` – Main implementation
- `privacy_switch.h` – Header definitions
- `test_privacy_switch.cpp` – Validation test
