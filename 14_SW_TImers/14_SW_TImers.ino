#include <Arduino_FreeRTOS.h>
#include "timers.h"

// Define the timer periods in ticks
#define ONE_SHOT_TIMER_PERIOD     (pdMS_TO_TICKS(500)) // One-shot timer (500ms)
#define AUTO_RELOAD_TIMER_PERIOD  (pdMS_TO_TICKS(300)) // Auto-reload timer (300ms)

// Timer handles
TimerHandle_t xTimer1, xTimer2;

// Timer start status variables
BaseType_t xTimer1Started, xTimer2Started;

// Setup function runs once during initialization
void setup() {
  Serial.begin(9600); // Initialize Serial communication

  // Create the one-shot timer
  xTimer1 = xTimerCreate(
    "One Shot",                     // Name of the timer (for debugging)
    ONE_SHOT_TIMER_PERIOD,          // Timer period in ticks
    pdFALSE,                        // pdFALSE indicates one-shot timer
    0,                              // Timer ID (can be used in callback)
    prvOneShotTimerCallback         // Callback function
  );

  // Create the auto-reload timer
  xTimer2 = xTimerCreate(
    "Auto-Reload",                  // Name of the timer
    AUTO_RELOAD_TIMER_PERIOD,       // Timer period in ticks
    pdTRUE,                         // pdTRUE indicates auto-reload timer
    0,                              // Timer ID
    prvAutoReloadCallback           // Callback function
  );

  // Start the timers if they were successfully created
  if ((xTimer1 != NULL) && (xTimer2 != NULL)) {
    xTimer1Started = xTimerStart(xTimer1, 0); // Start one-shot timer
    xTimer2Started = xTimerStart(xTimer2, 0); // Start auto-reload timer
  }

  // Ensure both timers started successfully
  if ((xTimer1Started != pdPASS) || (xTimer2Started != pdPASS)) {
    Serial.println("Timers could not be started!");
    while (1); // Halt execution if timers fail
  }
}

// One-shot timer callback function
void prvOneShotTimerCallback(TimerHandle_t xTimer) {
  static TickType_t xTimeNow;
  xTimeNow = xTaskGetTickCount(); // Get the current tick count
  Serial.print("One-shot timer callback execution: ");
  Serial.println(xTimeNow); // Log the tick count
}

// Auto-reload timer callback function
void prvAutoReloadCallback(TimerHandle_t xTimer) {
  static TickType_t xTimeNow;
  xTimeNow = xTaskGetTickCount(); // Get the current tick count
  Serial.print("Auto-reload timer callback execution: ");
  Serial.println(xTimeNow); // Log the tick count
}

// Main loop function is empty as FreeRTOS handles task scheduling
void loop() {}
