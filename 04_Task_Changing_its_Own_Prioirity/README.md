# FreeRTOS LED Control with Task Profiling and Priority Management

This Arduino project uses FreeRTOS to manage three separate tasks, each controlling an LED (Red, Yellow, and Blue). The program demonstrates basic task scheduling, LED toggling, and dynamic task priority management. Each task runs independently and logs its execution count to the Serial Monitor for profiling purposes.

## Features
- **Multitasking with FreeRTOS**: Each LED is controlled by an independent FreeRTOS task.
- **LED Toggle Control**: The Red, Yellow, and Blue LEDs toggle their state at regular intervals (300ms).
- **Task Profiling**: Each task tracks the number of times it has run, outputting this information to the Serial Monitor.
- **Dynamic Priority Change**: The Yellow LED task changes its own priority during execution to demonstrate task management in FreeRTOS.

## Hardware Requirements
- **Arduino Board**: Compatible with Arduino Uno, Nano, or other AVR-based boards.
- **3 LEDs**: Red, Yellow, and Blue.
- **3 Resistors**: 220-ohm resistors for current limiting.
- **Breadboard and Jumper Wires**: For connecting LEDs to the Arduino.

## Software Requirements
- **Arduino IDE**: Version 1.8.x or higher.
- **FreeRTOS Library for Arduino**: Install via the Arduino Library Manager.

## Circuit Setup
1. **Connect LEDs** to the specified digital pins:
   - **Red LED**: Pin 6
   - **Yellow LED**: Pin 7
   - **Blue LED**: Pin 8
2. Each LED should be connected to a 220-ohm resistor in series, with the resistor connected to ground.

## Code Explanation
- **Task Creation**: 
  - Three tasks are created in `setup()` for controlling each LED, using `xTaskCreate()` for task setup.
- **Task Profiling**:
  - Each task maintains a counter (`Profiler`) that increments with every task cycle. This count is printed to the Serial Monitor for tracking.
- **LED Toggling**:
  - Each task toggles its LED on and off every 300ms.
- **Dynamic Priority Change**:
  - The Yellow LED task modifies its own priority dynamically to demonstrate task priority adjustments within FreeRTOS.

## Usage
1. **Upload the Code**:
   - Load this code into the Arduino IDE, select the appropriate board and COM port, and upload it.
   
2. **Open the Serial Monitor**:
   - Set the baud rate to 9600. The Serial Monitor will show the task profiling data (i.e., the number of times each task has executed).

3. **Observe the LEDs**:
   - Each LED (Red, Yellow, Blue) should blink on and off every 300 milliseconds, indicating that each task is being scheduled by FreeRTOS independently.

## Example Serial Output
