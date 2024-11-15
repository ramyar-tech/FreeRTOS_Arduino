

This project demonstrates the use of FreeRTOS timers to toggle two LEDs (Red and Blue) at different intervals. The Blue LED toggles every 120ms, and the Red LED toggles every 300ms. The Blue timer is also stopped after it has executed 7 times.

## Components Required

- **Arduino Board** (e.g., Arduino Uno, or compatible)
- **Red LED** connected to pin 6
- **Blue LED** connected to pin 8
- **Resistors** (e.g., 220Ω for current-limiting)

## Setup and Configuration

### Pin Definitions:
- **Red LED**: Pin 6
- **Blue LED**: Pin 8

### Timers:
- **Blue Timer**: Executes every 120ms (Auto-reload timer)
- **Red Timer**: Executes every 300ms (Auto-reload timer)
- **Blue Timer Stop**: The Blue timer will stop after executing 7 times.

### Key Functions:
- **`prvTimerCallback()`**: This function is called whenever a timer expires. It toggles the corresponding LED and prints a message with the current tick count.

## Code Explanation:

1. **Timer Setup**:
   - Two timers (`xBlueTimer` and `xRedTimer`) are created using `xTimerCreate()`. The Blue timer runs every 120ms, and the Red timer runs every 300ms.
   
2. **Timer Callback**:
   - The `prvTimerCallback()` function is executed when either timer expires. It toggles the respective LED state and prints the current time (in ticks).
   - The Blue LED stops toggling after 7 executions, while the Red LED continues to toggle indefinitely.

3. **LED Control**:
   - The state of the Blue and Red LEDs is toggled using `digitalWrite()`. The LEDs are connected to pins 6 and 8, respectively.

## How It Works:

- The Arduino board initializes the Serial Monitor for debugging and sets the pin modes for the LEDs.
- Two timers are created and started.
- The Blue LED toggles every 120ms, and after 7 toggles, the Blue timer stops.
- The Red LED toggles every 300ms continuously.

## Requirements:
- **Arduino IDE** with the FreeRTOS library installed.
- **Arduino FreeRTOS library**: Can be installed via the Library Manager in Arduino IDE.


