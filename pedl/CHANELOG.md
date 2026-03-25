# Changelog

All important changes to this project are documented here.

---
## [0.1.1] – First working GPIO driver and build system fix

### Added
- First functional low level GPIO driver implementation
- ATmega328P platform layer with direct register access
- Simple LED test application on PB5
- PlatformIO configuration for layered project build
- Proper include paths for all project layers

## [0.1.0] – Architecture baseline

### Added

- Initial layered project structure
- Core configuration and type definition headers
- Driver module placeholders (GPIO, Timer, UART, PWM, ADC)
- Platform abstraction folders for ATmega328P
- Utility module placeholders (ring buffer, timebase)
- Application test folder structure
- Initial architectural documentation

### Notes

This version establishes the architectural foundation of the PEDL project.
Functional driver implementations will be added in future versions.

