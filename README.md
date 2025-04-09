# Smart Traffic Light Project

## Overview
The **Smart Traffic Light** project is an embedded systems application developed for the STM32 microcontroller as part of a coursework assignment at Ho Chi Minh City University of Technology (HCMUT). This project integrates a cooperative scheduler (RTOS-like) and a finite state machine (FSM) to manage a traffic light system with interactive features controlled by buttons. It demonstrates proficiency in embedded programming, real-time task scheduling, and hardware interfacing.

## Features
- **Traffic Light Control**: Manages 12 LEDs (4 red, 4 amber, 4 green) to simulate a crossroad traffic light system.
- **Seven-Segment Display**: Displays countdown timers for each road using four seven-segment LEDs (two per road).
- **Button-Based Interaction**: 
  - **Mode Selection**: Button 1 cycles through 4 modes (Normal, Red Modify, Amber Modify, Green Modify).
  - **Time Adjustment**: Button 2 increases time duration (1-99 seconds) for the selected LED color in modification modes.
  - **Value Setting**: Button 3 confirms and applies the adjusted time value.
- **Modes**:
  - **Mode 1 (Normal)**: Standard traffic light operation with pre-set timings.
  - **Mode 2-4 (Modify)**: Allows runtime adjustment of red, amber, or green light durations and real-time display updates.
- **Debouncing**: Software-based button debouncing ensures reliable input detection.
- **Cooperative Scheduler**: Manages periodic tasks (e.g., 0.5s, 1s, 1.5s, 2s, 2.5s) with a 10ms timer tick for precise timing.

## Implementation Details
- **Hardware**: STM32 microcontroller interfaced with LEDs, seven-segment displays, and push buttons.
- **Software**:
  - **Scheduler**: A custom cooperative scheduler with functions like `SCH_Add_Task()`, `SCH_Update()`, and `SCH_Dispatch_Tasks()` for task management.
  - **FSM**: Implements state transitions for mode switching and button actions.
  - **Button Handling**: Debounces inputs with a 10ms sampling rate and supports short/long press detection.
  - **Timer**: Uses a 10ms interrupt-driven timer for task scheduling and system updates.
- **Code Structure**:
  - `input_reading.c/h`: Button debouncing and state tracking.
  - `scheduler.c/h`: Cooperative scheduler implementation.
  - `fsm_processing.c/h`: FSM logic for traffic light states and mode handling.
  - `main.c`: System initialization and super loop with dispatcher.

## Prerequisites
- **Hardware**: STM32 development board (e.g., STM32F103), LEDs, seven-segment displays, resistors, and buttons.
- **Software**: STM32CubeIDE for development, Proteus for schematic simulation.
- **Dependencies**: STM32 HAL library for hardware abstraction.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/smart-traffic-light.git
2. Run file Smart-Traffic-Light.pdsprj (Require install Proteus)
3. Click on the "Run the simulation" button to run the simulation
