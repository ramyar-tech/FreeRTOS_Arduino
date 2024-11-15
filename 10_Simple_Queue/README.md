# FreeRTOS Queue Communication Demonstration

This project demonstrates how to use FreeRTOS queues for inter-task communication between two tasks. One task sends a value to a queue, and another task receives and prints the value to the Serial Monitor.

## Features

- **Queue Communication**: Demonstrates how tasks can communicate through FreeRTOS queues.
- **Task Synchronization**: One task sends data to the queue, and another task receives the data.
  
## Hardware Requirements

- **Arduino Board**: Compatible with FreeRTOS (e.g., Uno, Nano, Mega).
- **Other Components**: Breadboard and jumper wires (no external components are required).

## Software Requirements

- **Arduino IDE**: Version 1.8.x or higher.
- **FreeRTOS Library**: Install the `Arduino_FreeRTOS` library via the Library Manager.

## Setup Instructions

1. **Install the FreeRTOS Library**:
   - Open the Arduino IDE.
   - Go to **Sketch** -> **Include Library** -> **Manage Libraries**.
   - Search for **FreeRTOS** and install it.

2. **Upload the Code**:
   - Clone or download this repository.
   - Open the `.ino` file in the Arduino IDE.
   - Install the `Arduino_FreeRTOS` library via the Library Manager.
   - Upload the code to your Arduino board.
   - Open the Serial Monitor and set the baud rate to `9600`.

## Code Explanation

- **Queue Creation**: The queue is created with space for 5 integers (`yearQueue = xQueueCreate(5, sizeof(int32_t))`).
- **Sender Task**: The sender task repeatedly sends the value `2019` to the queue.
- **Receiver Task**: The receiver task waits for the data to be available in the queue and then prints it to the Serial Monitor.

## Usage

1. After uploading the code, open the **Serial Monitor**.
2. The receiver task will continuously print the value `2019` to the Serial Monitor as long as the sender task sends data to the queue.

## Troubleshooting

- **No Output on Serial Monitor**:
  - Ensure the correct COM port is selected.
  - Ensure the baud rate is set to `9600` in the Serial Monitor.
  
- **Queue Not Receiving Data**:
  - Verify that the queue is created successfully before any task attempts to use it.
  - Check for any error messages related to queue operations in the Serial Monitor.

## Future Enhancements

- **Increase Queue Size**: Expand the queue to hold more data or different data types.
- **Task Synchronization**: Implement task synchronization techniques such as semaphores or mutexes.
- **Additional Features**: Add more tasks or communication mechanisms for more complex use cases.

