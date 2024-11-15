# FreeRTOS LED Control with Priority Management

This Arduino project demonstrates multitasking and task priority management using FreeRTOS to control three LEDs (Red, Yellow, and Blue) independently. Each LED is managed by its own FreeRTOS task, which toggles the LED state every 1000 milliseconds. Additionally, the Yellow LED task dynamically changes the priority of the Red LED task.

## Features
- **FreeRTOS Multitasking**: Utilizes FreeRTOS to create and manage separate tasks for controlling each LED.
- **LED Toggling**: Each LED toggles on and off at a regular interval.
- **Dynamic Task Priority Change**: The Yellow LED task increases the priority of the Red LED task, demonstrating how FreeRTOS manages task priorities.

## Hardware Requirements
- **Arduino Board**: Compatible with Arduino Uno, Nano, or similar boards.
- **3 LEDs**: Red, Yellow, and Blue.
- **3 Resistors**: 220-ohm resistors to limit current to each LED.
- **Breadboard and Jumper Wires**: For connecting LEDs to the Arduino.

## Software Requirements
- **Arduino IDE**: Version 1.8.x or higher.
- **FreeRTOS Library for Arduino**: Install via the Arduino Library Manager.

## Setup Instructions
1. **Install FreeRTOS Library**:
   - Open the Arduino IDE.
   - Go to **Sketch** -> **Include Library** -> **Manage Libraries**.
   - Search for **FreeRTOS** and install it.

2. **Circuit Setup**:
   - Connect each LED to its respective pin on the Arduino with a 220-ohm resistor in series.
     - **Red LED**: Connect to digital pin 6.
     - **Yellow LED**: Connect to digital pin 7.
     - **Blue LED**: Connect to digital pin 8.
   - Connect each LED’s ground to the Arduino GND.

3. **Upload the Code**:
   - Load this code into the Arduino IDE.
   - Select your board and COM port under **Tools**.
   - Click **Upload** to load the program onto the Arduino.

## Code Explanation
- **Task Creation**: 
  - Three tasks are created in `setup()` for controlling the Red, Yellow, and Blue LEDs.
  - Each task is assigned to toggle one of the LEDs.
- **Task Priority Change**:
  - In the Yellow LED task, the priority of the Red LED task is increased to demonstrate dynamic priority management in FreeRTOS.
- **Task Logic**:
  - Each task toggles its LED every second and logs activity to the Serial Monitor.

## Usage
1. **Connect to Serial Monitor** (optional): 
   - Open the Serial Monitor (baud rate set to 9600) to observe the task activity and priority changes.
2. **Observe LED Behavior**:
   - The LEDs should each toggle on and off every second.
   - The Serial Monitor will display logs indicating which LED is toggling and when the priority of the Red LED task changes.

## Troubleshooting
- **LEDs Not Blinking**: Verify each LED is correctly connected to its designated pin and ground.
- **Library Issues**: Ensure the FreeRTOS library is installed if compilation errors occur.
- **Serial Output Issues**: Check that the correct COM port is selected, and the Serial Monitor baud rate is set to 9600.

