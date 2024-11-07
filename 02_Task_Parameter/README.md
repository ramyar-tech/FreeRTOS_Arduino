# LED Controller with FreeRTOS

This Arduino program demonstrates how to control three LEDs (Red, Yellow, Blue) using FreeRTOS. Each LED is managed by its own FreeRTOS task, which toggles the LED state every 500 milliseconds.

## Features
- **FreeRTOS Multitasking**: Utilizes FreeRTOS to manage separate tasks for controlling each LED.
- **LED Control**: Each LED is toggled independently by its respective task.
- **Adjustable Delay**: Each task pauses for 500 milliseconds between toggles, making it easy to modify the timing if needed.

## Hardware Requirements
- Arduino board (e.g., Arduino Uno, Nano, or compatible)
- 3 LEDs (Red, Yellow, and Blue)
- 3 resistors (220 ohms) for current limiting
- Breadboard and jumper wires for connecting the LEDs to the Arduino pins

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
  - Each task is created with a pointer to the LED pin number, which is used to toggle the respective LED.
  - The tasks toggle the LED state every 500ms using `vTaskDelay(500 / portTICK_PERIOD_MS)`.
- **Task Logic**: The `ledControllerTask` toggles the LED by reading its current state and writing the opposite value to achieve a blinking effect.

## Usage
1. Connect your Arduino to your computer and open the **Serial Monitor** (optional, mainly for debug).
2. Upload the code and observe the LEDs: each LED should toggle independently every 500 milliseconds.

## Troubleshooting
- **No LED Blinking**: Ensure each LED is correctly connected to the designated pin (6, 7, or 8) and grounded.
- **Check Library Installation**: If FreeRTOS-related errors appear, ensure the FreeRTOS library is properly installed.
- **Serial Monitor Issues**: For Serial Monitor debugging, ensure it’s set to the correct baud rate (9600) and that the correct COM port is selected.

## License
This project is open-source and available under the MIT License.

