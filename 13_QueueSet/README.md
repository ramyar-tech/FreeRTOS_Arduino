# FreeRTOS Queue Set Example

## Description
This project demonstrates the use of **FreeRTOS Queue Sets** on an Arduino platform. Queue Sets allow tasks to wait for data from multiple queues or semaphores, simplifying synchronization and inter-task communication.

---

## Features
1. **Queue Set**:
   - Combines multiple queues into a single set for efficient monitoring.
   - Tasks can block on a queue set and respond when data is available in any queue within the set.

2. **Sender Tasks**:
   - Two tasks (`Sender Task 1` and `Sender Task 2`) send messages to their respective queues at different intervals.

3. **Receiver Task**:
   - Waits for messages from any queue in the queue set.
   - Processes and displays messages on the Serial Monitor.

---

## Hardware Requirements
- Arduino-compatible board (e.g., Arduino Uno, Mega, etc.)
- USB cable for programming and power supply
- Computer with Arduino IDE installed

---

## Software Requirements
- Arduino IDE
- FreeRTOS library for Arduino (`Arduino_FreeRTOS.h`)
- Queue library (`queue.h`)

---

## Connections
This project does not require external hardware connections for basic functionality. The Serial Monitor is used to display the output.

---

## Code Workflow
1. **Initialization**:
   - Two queues (`xQueue1` and `xQueue2`) are created, each capable of holding one pointer to a string.
   - A queue set (`xQueueSet`) is created to manage these queues.
   - The queues are added to the queue set.

2. **Sender Tasks**:
   - **Sender Task 1**: Sends a message to `xQueue1` every 100ms.
   - **Sender Task 2**: Sends a message to `xQueue2` every 200ms.

3. **Receiver Task**:
   - Blocks on the queue set, waiting for data from any of the queues.
   - Retrieves messages from the queue and prints them to the Serial Monitor.

---

## How to Run the Code
1. **Setup**:
   - Open the code in Arduino IDE.
   - Install the FreeRTOS library (`Arduino_FreeRTOS.h`) if not already installed.

2. **Upload**:
   - Connect the Arduino board to your computer using a USB cable.
   - Select the correct board and port in the Arduino IDE.
   - Upload the code to the Arduino board.

3. **Monitor**:
   - Open the Serial Monitor in Arduino IDE.
   - Set the baud rate to `9600`.
   - Observe the messages received by the receiver task.

---

## Output
The Serial Monitor will display:
- Messages from Sender Task 1 and Sender Task 2 as they are received.

---

## Key Functions
- `xQueueCreate`: Creates a queue.
- `xQueueCreateSet`: Creates a queue set.
- `xQueueAddToSet`: Adds a queue to a queue set.
- `xQueueSelectFromSet`: Waits for data to be available in any queue in the queue set.
- `xQueueSend`: Sends a message to a queue.
- `xQueueReceive`: Receives a message from a queue.

---
