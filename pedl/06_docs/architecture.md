# PEDL Architecture

## Design Philosophy

The PEDL project follows a layered embedded firmware architecture that separates hardware dependent code from reusable driver logic and application level experiments.

The main objective is to enable portability and deterministic behavior analysis.

---

## Layer Description

### Core Layer

Contains global type definitions and compile-time configuration options.
This layer ensures that higher level modules remain independent from compiler or architecture specific definitions.

---

### Driver Layer

Implements reusable peripheral drivers such as GPIO, Timer, UART, PWM and ADC.

Drivers expose a generic API and must not contain direct application logic.

Responsibilities:

- Deterministic execution
- Minimal latency
- Interrupt safe behavior where required
- No dynamic memory allocation

---

### Platform Layer

Provides microcontroller specific register mappings and hardware configuration values.

When porting to a new architecture, only this layer should require major modifications.

---

### Utility Layer

Contains software components not directly tied to hardware peripherals.

Examples:

- Ring buffer implementation for interrupt driven communication
- Timebase utilities for execution time measurement
- Scheduler support functions

---

### Application Layer

Standalone demo applications used to validate driver functionality and observe real-time behavior.

Each application contains its own `main.c` entry point and is compiled independently.

---

## Portability Strategy

The project aims to isolate hardware register access inside platform specific headers while keeping driver APIs architecture neutral.

Future ARM Cortex-M support will reuse existing driver logic with minimal modification.