

## Description
This project demonstrates the use of FreeRTOS software timers (One-Shot and Auto-Reload) on an Arduino platform. Timers are used to execute specific tasks at defined intervals without requiring dedicated tasks, reducing the overall CPU load.

---

## Features
1. **One-Shot Timer**: Executes its callback function once after a delay of 500ms.
2. **Auto-Reload Timer**: Continuously executes its callback function every 300ms.
3. **Serial Output**: Prints the timer callback execution times (in ticks) to the Serial Monitor.

---

## Hardware Requirements
- Arduino-compatible board (e.g., Arduino Uno, Mega, etc.)
- USB cable for programming and power supply
- Computer with Arduino IDE installed

---

## Software Requirements
- Arduino IDE
- FreeRTOS library for Arduino (`Arduino_FreeRTOS.h`)
- Timer library (`timers.h`)

---

## Connections
This project does not require external hardware connections. The Serial Monitor is used for output.

---

## Code Workflow
1. **Initialization**:
   - A one-shot timer and an auto-reload timer are created using `xTimerCreate`.
   - Both timers are started using `xTimerStart`.

2. **Callback Functions**:
   - **One-Shot Timer**: Executes its callback once and logs the tick count when executed.
   - **Auto-Reload Timer**: Executes its callback periodically, logging the tick count for each execution.

3. **FreeRTOS Scheduler**:
   - FreeRTOS manages the timers and executes the callback functions as per their schedules.

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
   - Observe the timer execution logs.

---

## Output
The Serial Monitor will display:
- Execution time (in ticks) for the **one-shot timer** when it runs after 500ms.
- Execution times (in ticks) for the **auto-reload timer** every 300ms.

---

## Key Functions
- `xTimerCreate`: Creates a software timer.
- `xTimerStart`: Starts a timer.
- `xTaskGetTickCount`: Retrieves the current tick count since FreeRTOS started.
- `prvOneShotTimerCallback`: Callback for the one-shot timer.
- `prvAutoReloadCallback`: Callback for the auto-reload timer.

---

