# AVR Drivers

This repository contains AVR microcontroller drivers organized into a modular structure. The drivers are implemented using layered architecture principles, ensuring scalability and maintainability. The project includes drivers for hardware abstraction (HAL), microcontroller abstraction (MCAL), and supporting utilities.

---

## Table of Contents

1. [Project Structure](#project-structure)  
   1.1 [HAL (Hardware Abstraction Layer)](#1-hal-hardware-abstraction-layer)  
   1.2 [LIB (Library)](#2-lib-library)  
   1.3 [MCAL (Microcontroller Abstraction Layer)](#3-mcal-microcontroller-abstraction-layer)  
   1.4 [Service](#4-service) 
2. [Key Features](#key-features) 
3. [How to Use](#how-to-use)  

---

## Project Structure

### 1. `HAL` (Hardware Abstraction Layer)

This layer provides high-level drivers for external hardware components. Each module in the HAL layer has the following files:

- `<DriverName>_config.h`: Configuration settings for the driver.
- `<DriverName>_interface.h`: Public API for the driver.
- `<DriverName>_private.h`: Internal driver details (not exposed to the user).
- `<DriverName>_program.c`: Implementation of the driver functionality.

#### Subdirectories:

- **`DCM` (DC Motor Driver)**: Contains files for controlling DC motors.
- **`KPD` (Keypad Driver)**: Drivers for interfacing with a keypad module.
- **`LCD` (LCD Driver)**: Drivers for controlling an LCD module.

---

### 2. `LIB` (Library)

The library folder contains utility files and helper functions to support the drivers and application logic.

#### Files:

- `bit_math.h`: Bit manipulation macros for operations like setting, clearing, toggling, or reading bits.
- `num_str_conv.c`/`.h`: Functions for number-to-string and string-to-number conversions.
- `std_types.h`: Definitions for standard data types to ensure code portability and consistency.

---

### 3. `MCAL` (Microcontroller Abstraction Layer)

This layer provides low-level drivers for AVR peripherals. Each module contains the same structure as HAL drivers (config, interface, private, and program files).

#### Subdirectories:

- **`ADC` (Analog-to-Digital Converter)**: Drivers for configuring and reading data from the ADC module.
- **`DIO` (Digital Input/Output)**: Drivers for configuring and using GPIO pins.
- **`EXTI` (External Interrupts)**: Drivers for handling external interrupt events.
- **`GI` (Global Interrupts)**: Driver for enabling/disabling global interrupts.
- **`SLEEP_MODE`**: Drivers for configuring sleep modes on AVR microcontrollers.
- **`SPI` (Serial Peripheral Interface)**: Drivers for SPI communication.
- **`TIMERS`**: Drivers for timer/counter functionality.
- **`TWI` (Two-Wire Interface)**: Drivers for I2C communication.
- **`UART` (Universal Asynchronous Receiver/Transmitter)**: Drivers for UART serial communication.
- **`WDT` (Watchdog Timer)**: Driver for configuring the watchdog timer.

---

### 4. `Service`

This folder contains advanced functionality, including real-time operating system implementations and schedulers.

#### Subdirectories:

- **`RTO` (Real-Time Scheduler)**: A custom scheduler implementation using AVR timers.
- **`RTOS` (FreeRTOS)**: Contains files for integrating FreeRTOS with AVR microcontrollers.

---

## Key Features

- Modular and scalable structure.
- Supports a variety of AVR peripherals and external components.
- Includes real-time operating system support (`FreeRTOS`).
- Utility functions for enhanced portability.

---

## How to Use

### Steps:

1. Clone this repository:
   
   ```bash
   git clone https://github.com/AhmedEmadh/all_projects
   ```

2. Navigate to the desired driver folder (e.g., `HAL/KPD` for the keypad driver).

3. Include the driver's interface header file (e.g., `KPD_interface.h`) in your project.

4. Follow the API provided in the interface file to use the driver.
