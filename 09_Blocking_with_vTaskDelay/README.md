# FreeRTOS LED Control Demonstration

This Arduino project demonstrates the use of FreeRTOS to manage multiple tasks controlling LEDs. Three tasks are created to manage three LEDs (Red, Yellow, and Blue), with the Red LED toggling every 500 milliseconds.

## Features

- **FreeRTOS Multitasking**: Manages Red, Yellow, and Blue LEDs with independent FreeRTOS tasks.
- **Task Scheduling**: Each LED is controlled by its own task, with the Red LED task set to toggle every 500ms.
- **Task Structure**: Each task is independent, allowing for easy scalability and extension.

## Hardware Requirements

- **Arduino Board**: Arduino Uno, Nano, or any compatible board
- **LEDs**: 3 LEDs (Red, Yellow, Blue)
- **Resistors**: 220Ω resistors for each LED
- **Miscellaneous**: Breadboard, jumper wires

## Circuit Setup

1. **Red LED**: Connect to pin 6 with a 220Ω resistor.
2. **Yellow LED**: Connect to pin 7 with a 220Ω resistor.
3. **Blue LED**: Connect to pin 8 with a 220Ω resistor.
4. Each resistor’s other terminal connects to GND.

## Software Requirements

- **Arduino IDE**: Version 1.8.x or higher
- **FreeRTOS Library**: Install the `Arduino_FreeRTOS` library through the Library Manager

## Setup Instructions

1. **Install FreeRTOS**:
   - Open Arduino IDE.
   - Go to **Sketch** -> **Include Library** -> **Manage Libraries**.
   - Search for **FreeRTOS** and install the library.

2. **Connect the LEDs**:
   - Connect the Red LED to pin 6.
   - Connect the Yellow LED to pin 7.
   - Connect the Blue LED to pin 8.

3. **Upload the Code**:
   - Open this `.ino` file in the Arduino IDE.
   - Select the correct board and port under **Tools**.
   - Upload the code to the Arduino.

## Code Explanation

- **Setup**: Initializes serial communication and creates three FreeRTOS tasks for controlling the LEDs.
- **Red LED Task**: Toggles the Red LED every 500ms.
- **Yellow and Blue LED Tasks**: Placeholders for further functionality (currently empty).
- **Task Scheduling**: Each task runs concurrently, and the FreeRTOS scheduler handles their execution.

## Usage

1. Upload the code to the Arduino board.
2. Open the **Serial Monitor** (set baud rate to 9600) to track task execution times and statuses.
3. Observe the Red LED toggling every 500ms. The Yellow and Blue LED tasks are placeholders for further development.

## Troubleshooting

- **No LED Blinking**:
  - Check wiring connections and ensure the LEDs are connected to the correct pins.
  - Ensure that FreeRTOS is installed correctly.

- **Serial Monitor Output Missing**:
  - Verify the baud rate is set to 9600 in the Serial Monitor.
  - Make sure the correct COM port is selected in the Arduino IDE.

