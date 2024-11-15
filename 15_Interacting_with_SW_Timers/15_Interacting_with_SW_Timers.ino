#include <Arduino_FreeRTOS.h>
#include "timers.h"

// Pin definitions for LEDs
#define RED       6
#define BLUE      8

// Timer periods (in FreeRTOS ticks)
#define BLUE_TIMER_PERIOD   (pdMS_TO_TICKS(120)) // 120ms period for the blue LED
#define RED_TIMER_PERIOD    (pdMS_TO_TICKS(300)) // 300ms period for the red LED

// Timer handles
TimerHandle_t xBlueTimer, xRedTimer; 

// Execution counter for blue timer
uint32_t blueExecutionCount = 0;

void setup()
{
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);

  // Set pin modes for LEDs
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  // Variables to check if timers started successfully
  BaseType_t xBlueTimerStarted, xRedTimerStarted;

  // Create timers
  xBlueTimer = xTimerCreate("Blue Timer", BLUE_TIMER_PERIOD, pdTRUE, NULL, prvTimerCallback);
  xRedTimer = xTimerCreate("Red Timer", RED_TIMER_PERIOD, pdTRUE, NULL, prvTimerCallback);

  // Ensure timers are created successfully
  if ((xBlueTimer != NULL) && (xRedTimer != NULL))
  {
    // Start timers
    xBlueTimerStarted = xTimerStart(xBlueTimer, 0);
    xRedTimerStarted = xTimerStart(xRedTimer, 0);

    // Wait until both timers are successfully started
    while ((xBlueTimerStarted != pdPASS) || (xRedTimerStarted != pdPASS)) {}
  }
}

void prvTimerCallback(TimerHandle_t xTimer)
{
  // Get the current tick count
  TickType_t xTimeNow = xTaskGetTickCount();

  if (xTimer == xBlueTimer)
  {
    // Increment execution count for the blue timer
    blueExecutionCount++;

    // Print execution time for blue timer
    Serial.print("Blue Timer execution: ");
    Serial.println(xTimeNow);

    // Toggle blue LED state
    digitalWrite(BLUE, !digitalRead(BLUE));

    // Stop the blue timer after 7 executions
    if (blueExecutionCount == 7)
    {
      xTimerStop(xBlueTimer, 0); 
    }
  }
  else if (xTimer == xRedTimer)
  {
    // Print execution time for red timer
    Serial.print("Red Timer execution: ");
    Serial.println(xTimeNow);

    // Toggle red LED state
    digitalWrite(RED, !digitalRead(RED));
  }
}

void loop()
{
  // Empty loop as FreeRTOS handles task scheduling
}
