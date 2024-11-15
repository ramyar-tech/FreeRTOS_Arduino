# LED Controller with FreeRTOS

This Arduino program demonstrates multitasking using FreeRTOS to manage three independent tasks. Each task controls an LED (Red, Yellow, Blue), toggling its state periodically while profiling the task's runtime.

## Features
- **FreeRTOS Multitasking**: Each LED is controlled by a separate FreeRTOS task.
- **Task Profiling**: Tracks the runtime of each task and displays it on the Serial Monitor.
- **Adjustable Delay**: Tasks pause for a user-defined delay (currently 300 milliseconds) between toggles.
- **Dynamic Task Management**: Includes examples of changing task priorities during execution.

## Hardware Requirements
- Arduino board (e.g., Arduino Uno, Nano, or compatible)
- 3 LEDs (Red, Yellow, and Blue)
- 3 resistors (220 ohms) for current limiting
- Breadboard and jumper wires for wiring the LEDs to the Arduino

## Software Requirements
- **Arduino IDE**: Version 1.8.x or higher
- **FreeRTOS Library for Arduino**: Install through the Arduino Library Manager

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
  - Each task tracks its execution runtime using a profiling variable.
  - The tasks toggle the LED state every 300ms using `vTaskDelay(300 / portTICK_PERIOD_MS)`.
- **Task Logic**: The tasks use FreeRTOS functions like `uxTaskPriorityGet` and `vTaskPrioritySet` for runtime task management.

## Usage
1. Connect your Arduino to your computer and open the **Serial Monitor** (optional, mainly for debugging).
2. Upload the code and observe the LEDs: each LED should toggle independently every 300 milliseconds.
3. The Serial Monitor displays the runtime of each task and any changes in task priority.

## Troubleshooting
- **No LED Blinking**: Ensure each LED is correctly connected to the designated pin (6, 7, or 8) and grounded.
- **Check Library Installation**: If FreeRTOS-related errors appear, ensure the FreeRTOS library is properly installed.
- **Serial Monitor Issues**: For Serial Monitor debugging, ensure it’s set to the correct baud rate (9600) and that the correct COM port is selected.
