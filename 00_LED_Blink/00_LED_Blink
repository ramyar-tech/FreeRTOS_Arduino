#include <Arduino_FreeRTOS.h>  // Include the FreeRTOS library

#define LED  13  // Define the pin for the LED

// Typedef for TaskProfiler. This keeps track of the number of times the LED task has run.
typedef int TaskProfiler;
TaskProfiler LEDProfiler;  // Variable to store the LED task profile counter

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);

  // Set LED pin as output
  pinMode(LED, OUTPUT);

  // Create a FreeRTOS task to control the LED
  xTaskCreate(LedControllerTask,   // Task function
              "LED",               // Task name
              128,                 // Stack size (adjusted if necessary)
              NULL,                // Parameters for the task (not used here)
              1,                   // Task priority (1 is a low priority)
              NULL);               // Task handle (not needed here)
}

void LedControllerTask(void *pvParameters) {
  // Set LED pin as output in the task (not required in setup, but included here for clarity)
  pinMode(LED, OUTPUT);

  while (1) {
    LEDProfiler++;  // Increment the task profiler to track task iterations

    // Print the profiler value to Serial Monitor
    Serial.print("LED Profiler: ");
    Serial.println(LEDProfiler);

    // Uncomment the following line to toggle the LED state
    // digitalWrite(LED, digitalRead(LED) ^ 1);  // Toggle the LED pin state

    delay(300);  // Wait for 300 ms before executing the next iteration
  }
}

void loop() {
  // The loop function is not used in this example because FreeRTOS tasks are handling the behavior
  // You can remove the loop or add code for other tasks here if needed
}
