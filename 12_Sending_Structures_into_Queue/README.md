# Arduino FreeRTOS Queue Example

## Overview
This project demonstrates the use of FreeRTOS queues on an Arduino board to facilitate communication between tasks. Two sender tasks send data to a shared queue, and a single receiver task processes the data. The project showcases the fundamental use of queues in FreeRTOS for inter-task communication.

## Hardware Requirements
- Arduino board (e.g., Uno, Mega, or similar)
- USB cable for programming and power
- Serial Monitor to view output

## Software Requirements
- Arduino IDE
- FreeRTOS library for Arduino

## Components and Connections
This project does not use external components like LEDs for visualization but uses the Serial Monitor for task communication. If LEDs are added for visualization, connect:
- **RED LED** to pin 6
- **YELLOW LED** to pin 7
- **BLUE LED** to pin 8

## Code Functionality

### Key Features
1. **Queue Creation**: 
   - A queue is created to hold a maximum of 3 `Data_t` structures.
   - Each `Data_t` structure contains:
     - A `uint8_t` value (`ucValue`)
     - A source identifier (`eDataSource`)

2. **Sender Tasks**:
   - Two sender tasks (`Sender Task 1` and `Sender Task 2`) send their respective data structures to the queue.
   - If the queue is full, tasks wait for up to 100ms before retrying.
   - Data values and their sources are predefined in the `xStructToSend` array.

3. **Receiver Task**:
   - The receiver task reads data from the queue.
   - It identifies the source of the data and prints the received value and source information to the Serial Monitor.

4. **Error Handling**:
   - Both sender and receiver tasks handle errors, such as failure to send data to or receive data from the queue.

### FreeRTOS Concepts Used
- **Tasks**: Three tasks are created: two sender tasks and one receiver task.
- **Queues**: A shared queue is used for communication between sender and receiver tasks.
- **Priorities**: Sender tasks are given higher priority than the receiver task.

## Serial Monitor Output
The Serial Monitor displays messages indicating:
- Successful data transmission from each sender.
- Successful data reception by the receiver.
- Errors if the queue is full or data cannot be retrieved.



