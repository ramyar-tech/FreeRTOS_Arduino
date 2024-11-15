# FreeRTOS LED Task Priority and Profiling Demonstration

This project demonstrates multitasking on an Arduino using FreeRTOS. It manages three LEDs (Red, Yellow, and Blue) with individual tasks while monitoring task priorities and profiling task execution.

## Features

- **Multitasking with FreeRTOS**:
  - Three independent tasks to manage the Red, Yellow, and Blue LEDs.
  - Tasks execute based on their assigned priorities.
  
- **Task Profiling**:
  - Tracks the execution count for each task.
  - Outputs task execution data to the Serial Monitor.
  
- **Task Priority Monitoring**:
  - Retrieves and displays task priorities for debugging and analysis.

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
  - Each task is created with a pointer to the LED pin number, which is used to toggle the respective LED.
  - The tasks toggle the LED state every 300ms using `vTaskDelay(300 / portTICK_PERIOD_MS)`.
- **Task Logic**: 
  - **Red LED**: Toggles the Red LED and tracks the task execution count.
  - **Yellow LED**: Toggles the Yellow LED, tracks execution, and adjusts task priority.
  - **Blue LED**: Toggles the Blue LED and tracks the task execution count.

## Usage

1. Connect your Arduino to your computer and open the **Serial Monitor** (optional, mainly for debug).
2. Upload the code and observe the LEDs: each LED should toggle independently every 300 milliseconds.

## Troubleshooting

- **No Output on Serial Monitor**:
  - Ensure the correct COM port is selected.
  - Verify the baud rate is set to `9600`.
  
- **LEDs Not Blinking**:
  - Check wiring and resistor connections.
  - Verify the LEDs are connected to the correct pins.


