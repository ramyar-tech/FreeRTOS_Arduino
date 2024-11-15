# FreeRTOS LED Control with Task Suspension and Resumption

This project demonstrates how to control three LEDs (Red, Yellow, and Blue) using FreeRTOS on an Arduino. The program includes task suspension and resumption based on certain conditions, where the Blue LED task is suspended after 10 cycles of the Yellow LED task and resumed after the Yellow LED task has executed 5 cycles.

## Features

- **FreeRTOS Multitasking**: 
  - Three independent tasks to manage the Red, Yellow, and Blue LEDs.
  - Tasks execute based on their assigned priorities.

- **Task Suspension and Resumption**: 
  - The Blue LED task is suspended after 10 cycles of the Yellow LED task and resumed after 5 cycles of the Yellow LED task.
  - Tracks and monitors the suspension and resumption behavior.

- **Task Profiling**: 
  - Tracks the execution count for each task.
  - Outputs task execution data to the Serial Monitor.

## Hardware Requirements

- **Arduino Board**: Compatible with FreeRTOS (e.g., Uno, Nano, Mega).
- **LEDs**: Red, Yellow, and Blue LEDs.
- **Resistors**: 220Ω resistors for each LED.
- **Other Components**: Breadboard and jumper wires for connecting the LEDs to the Arduino pins.

## Software Requirements

- **Arduino IDE**: Version 1.8.x or higher.
- **FreeRTOS Library**: Install the `Arduino_FreeRTOS` library through the Arduino Library Manager.

## Setup Instructions

1. **Install the FreeRTOS Library**:
   - Open the Arduino IDE.
   - Go to **Sketch** -> **Include Library** -> **Manage Libraries**.
   - Search for **FreeRTOS** and install it.

2. **Connect the LEDs**:
   - **Red LED**: Connect to pin 6 with a 220-ohm resistor.
   - **Yellow LED**: Connect to pin 7 with a 220-ohm resistor.
   - **Blue LED**: Connect to pin 8 with a 220-ohm resistor.
   - Connect each LED’s ground to the Arduino GND.

3. **Upload the Code**:
   - Open this code in the Arduino IDE.
   - Select your Arduino board and the correct COM port under **Tools**.
   - Click **Upload** to load the program onto the Arduino.

## Code Explanation

- **Pin Setup**: The `setup()` function initializes each LED pin as an output.
- **Task Creation**: Three FreeRTOS tasks are created, each responsible for one LED (Red, Yellow, or Blue).
  - Each task increments its respective profiler variable and prints the runtime to the Serial Monitor.
- **Task Logic**:
  - The Yellow LED task toggles the LED every 100ms, and monitors the suspend/resume process.
  - The Blue LED task is suspended after the Yellow LED task has executed 10 cycles, and it is resumed after the Yellow LED task runs 5 cycles.

## Usage

1. Connect your Arduino to your computer and open the **Serial Monitor** (optional, mainly for debug).
2. Upload the code and observe the LEDs: each LED should toggle independently every 100 milliseconds.
3. The Serial Monitor will display the runtime for each task, and the Blue LED task will be suspended after 10 cycles of the Yellow LED task, resuming after 5 cycles of the Yellow LED task.

## Troubleshooting

- **No Output on Serial Monitor**:
  - Ensure the correct COM port is selected.
  - Verify the baud rate is set to `9600`.

- **LEDs Not Blinking**:
  - Check wiring and resistor connections.
  - Verify the LEDs are connected to the correct pins.

