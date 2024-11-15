# FreeRTOS LED Task Control with Suspension Mechanism

This project demonstrates how to control three LEDs (Red, Yellow, and Blue) using FreeRTOS on an Arduino. Each LED is managed by its own FreeRTOS task, with the Yellow LED task being suspended after a certain condition is met (after 10 cycles of the Blue LED task).

## Features

- **Multitasking with FreeRTOS**:
  - Three independent tasks to manage the Red, Yellow, and Blue LEDs.
  - Tasks execute based on their assigned priorities and delay.
  
- **Task Profiling**:
  - Tracks the execution count for each task and outputs the runtime data to the Serial Monitor.

- **Task Suspension**:
  - The Yellow LED task is suspended after the Blue LED task runs 10 cycles, demonstrating FreeRTOS's ability to suspend tasks based on conditions.

## Hardware Requirements

- **Arduino Board**: Compatible with FreeRTOS (e.g., Uno, Nano, Mega).
- **LEDs**: Red, Yellow, and Blue LEDs.
- **Resistors**: 220Ω resistors for each LED.
- **Other Components**: Breadboard, jumper wires.

## Circuit Setup

1. Connect the Red LED to pin 6 via a 220Ω resistor.
2. Connect the Yellow LED to pin 7 via a 220Ω resistor.
3. Connect the Blue LED to pin 8 via a 220Ω resistor.
4. The other terminal of each resistor connects to GND.

## Software Requirements

- **Arduino IDE**: Version 1.8.x or higher.
- **FreeRTOS Library**: Install the `Arduino_FreeRTOS` library via the Library Manager.

## How to Run

1. Clone or download this repository.
2. Open the `.ino` file in the Arduino IDE.
3. Ensure the FreeRTOS library is installed.
4. Upload the code to your Arduino board.
5. Open the Serial Monitor and set the baud rate to `9600`.

## Code Explanation

- **Pin Setup**: The `setup()` function initializes each LED pin as an output.
- **Task Creation**: Three FreeRTOS tasks are created, each responsible for one LED (Red, Yellow, or Blue).
  - The tasks toggle the respective LED and increment the task profiler each time they run.
  - The Yellow LED task is suspended after the Blue LED task has run 10 times.
- **Task Logic**: 
  - **Red LED**: Toggles the Red LED and tracks the task execution count.
  - **Yellow LED**: Toggles the Yellow LED, tracks execution, and is suspended after 10 cycles of Blue task.
  - **Blue LED**: Toggles the Blue LED and tracks the task execution count.

## Usage

1. Connect your Arduino to your computer and open the **Serial Monitor** (optional, mainly for debug).
2. Upload the code and observe the LEDs: each LED should toggle independently every 100 milliseconds.
3. After 10 cycles of the Blue LED task, the Yellow LED task will be suspended.

## Troubleshooting

- **No Output on Serial Monitor**:
  - Ensure the correct COM port is selected.
  - Verify the baud rate is set to `9600`.
  
- **LEDs Not Blinking**:
  - Check wiring and resistor connections.
  - Verify the LEDs are connected to the correct pins.
ssssss
