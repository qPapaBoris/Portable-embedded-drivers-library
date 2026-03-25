# PEDL – Portable Embedded Drivers Library

## Overview

PEDL is a lightweight bare-metal embedded drivers library created for learning low-level firmware development and real-time system behavior.

The project focuses on deterministic execution, hardware timer usage, interrupt driven design and portable driver abstraction across microcontroller architectures.

The initial implementation targets the ATmega328P microcontroller using direct register level programming.

---

## Goals

- Learn how to design reusable embedded drivers
- Understand real-time scheduling concepts
- Measure interrupt latency and execution jitter
- Build portable firmware components
- Prepare for cross-architecture development (AVR → ARM Cortex-M)

---

## Architecture

The project is structured into multiple logical layers:

- **core** – common types and compile-time configuration
- **drivers** – hardware abstraction drivers (GPIO, Timer, UART, PWM, ADC)
- **platform** – microcontroller specific register mappings
- **utils** – software utilities such as ring buffer and timebase logic
- **apps** – standalone demo applications used to test drivers
- **docs** – architectural explanations and timing analysis
- **version** – project version information and changelog

---

## Current Features

- Cooperative cyclic scheduler experiments
- Timer based periodic execution
- GPIO deterministic toggling
- UART interrupt driven communication (planned)
- Execution time monitoring utilities
- CPU load estimation experiments
- Race condition and atomic access demonstrations

---

## Supported Hardware

- ATmega328P (working on)
- ARM Cortex-M4 (planned)

---

## Build

The project uses PlatformIO.
