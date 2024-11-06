# LED Controller with FreeRTOS

This program demonstrates the use of FreeRTOS on an Arduino board to control an LED. The LED is toggled every 300 milliseconds, and the number of iterations of the task is tracked using a profiler.

## Features
- Multi-tasking with FreeRTOS
- Toggle LED state every 300ms
- Task profiler to track the number of task executions

## Hardware Requirements
- Arduino board (e.g., Arduino Uno, Nano, or any compatible board)
- LED connected to pin 13 (or any other digital pin)
- (Optional) 220 ohm resistor to limit current to the LED

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
- **Task Creation**: The `LedControllerTask` is created in the `setup()` function. This task controls the LED and tracks its execution.
- **Profiler**: The `LEDProfiler` variable increments each time the task runs. This value is printed to the Serial Monitor for monitoring.
- **LED Control**: The LED state is toggled using `digitalWrite(LED, digitalRead(LED) ^ 1)`. This uses the XOR operation to flip the current state.
- **FreeRTOS Delay**: The task uses `vTaskDelay(300 / portTICK_PERIOD_MS)` to wait for 300ms before the next toggle, without blocking other tasks.

## Usage
1. Connect the LED to pin 13 (or any other digital pin) on your Arduino board.
2. Open the **Serial Monitor** in the Arduino IDE (set the baud rate to 9600).
3. Upload the code to your Arduino.
4. The LED will toggle every 300 milliseconds, and the profiler count will be printed to the Serial Monitor.

## Troubleshooting
- **LED not blinking**: Verify the LED is connected correctly. Check the pin number in the code.
- **No serial output**: Ensure the **Serial Monitor** is set to the correct baud rate (`9600`), and the correct COM port is selected in the **Tools** menu.
  
## License
This project is open-source and available under the MIT License.

