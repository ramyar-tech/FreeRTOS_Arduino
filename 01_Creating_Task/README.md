# LED Controller with FreeRTOS

This program demonstrates how to control three LEDs (Red, Yellow, Blue) using FreeRTOS on an Arduino. Each LED has its own task, which prints the color name to the Serial Monitor every 500 milliseconds. The program showcases the use of FreeRTOS to manage multiple tasks concurrently.

## Features
- **FreeRTOS Multitasking**: Three tasks, each controlling a different LED.
- **LED Control**: Each LED's state is periodically updated (in this case, printed to the Serial Monitor).
- **Serial Output**: The task for each LED prints the corresponding color ("Red", "Yellow", "Blue") to the Serial Monitor every 500ms.

## Hardware Requirements
- Arduino board (e.g., Arduino Uno, Nano, or any compatible board)
- 3 LEDs (Red, Yellow, and Blue)
- 3 resistors (220 ohms) for current limiting
- Jumper wires and breadboard for connecting the LEDs

## Software Requirements
- Arduino IDE (version 1.8.x or higher)
- FreeRTOS library for Arduino (can be installed through the Arduino Library Manager)

## Installation Instructions
1. **Install Arduino IDE**: Ensure you have the latest version of the Arduino IDE installed.
2. **Install FreeRTOS Library**:
   - Open the Arduino IDE.
   - Go to **Sketch** -> **Include Library** -> **Manage Libraries**.
   - In the Library Manager, search for **FreeRTOS** and install it.
3. **Upload the Code**:
   - Connect your Arduino board to your computer via USB.
   - Open the `led_controller_freertos.ino` file.
   - Click **Upload** to load the program onto your Arduino.

## Code Explanation
- **Task Creation**: Three FreeRTOS tasks are created to manage the Red, Yellow, and Blue LEDs.
  - Each task is responsible for printing the corresponding color to the Serial Monitor.
  - The task delays for 500ms to avoid spamming the Serial Monitor too quickly.
  
- **FreeRTOS Delay**: Each task uses `vTaskDelay()` to pause its execution for 500ms, allowing other tasks to run and ensuring the microcontroller isn't continuously printing without a pause.

## Usage
1. Connect the LEDs to pins 6 (Red), 7 (Yellow), and 8 (Blue) on your Arduino board.
2. Open the **Serial Monitor** in the Arduino IDE (set the baud rate to 9600).
3. Upload the code to your Arduino.
4. The Serial Monitor will display the color name ("Red", "Yellow", "Blue") every 500 milliseconds as each LED task runs.

## Troubleshooting
- **LEDs not connected correctly**: Double-check your wiring, ensuring that each LED is connected to the correct pin (6, 7, 8).
- **No output in Serial Monitor**: Make sure that the **Serial Monitor** is set to the correct baud rate (9600) and the correct COM port is selected under **Tools**.
  
## License
This project is open-source and available under the MIT License.

