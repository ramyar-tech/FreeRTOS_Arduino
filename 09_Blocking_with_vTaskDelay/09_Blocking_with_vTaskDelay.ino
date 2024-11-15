#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8

typedef int TaskProfiler;

TaskProfiler  RedLEDProfiler;
TaskProfiler  YellowLEDProfiler;
TaskProfiler  BlueLEDProfiler;

// Defining the 500ms delay constant for task scheduling
const TickType_t _500ms = pdMS_TO_TICKS(500);

void setup() {
  // Start serial communication at 9600 baud
  Serial.begin(9600);

  // Create the Red LED task
  xTaskCreate(redLEDControllerTask,
              "Red Led Task",  // Task name
              100,             // Stack size (in words)
              NULL,            // Task input parameters
              1,               // Task priority
              NULL             // Task handle (not used here)
  );

  // Create the Yellow LED task
  xTaskCreate(yellowLEDControllerTask,
              "Yellow Led Task",
              100,
              NULL,
              1,
              NULL
  );

  // Create the Blue LED task
  xTaskCreate(BlueLEDControllerTask,
              "Blue Led Task",
              100,
              NULL,
              1,
              NULL
  );
}

// Red LED task, turns the LED on and off every 500ms
void redLEDControllerTask(void *pvParameters)
{
  pinMode(RED, OUTPUT);  // Set the Red LED pin as an output

  while(1)
  {
    // Turn the Red LED on
    digitalWrite(RED, HIGH);
    // Wait for 500ms
    vTaskDelay(_500ms);
    // Turn the Red LED off
    digitalWrite(RED, LOW);
    // Wait for 500ms
    vTaskDelay(_500ms);
  }
}

// Yellow LED task, currently does nothing
void yellowLEDControllerTask(void *pvParameters)
{
  pinMode(YELLOW, OUTPUT);  // Set the Yellow LED pin as an output

  while(1)
  {
    // Yellow LED task is empty, but can be extended in the future
    // Currently, this task is a placeholder for further functionality
  }
}

// Blue LED task, currently does nothing
void BlueLEDControllerTask(void *pvParameters)
{
  pinMode(BLUE, OUTPUT);  // Set the Blue LED pin as an output

  while(1)
  {
    // Blue LED task is empty, but can be extended in the future
    // Currently, this task is a placeholder for further functionality
  }
}

void loop() {
  // FreeRTOS tasks run in parallel and are managed by the scheduler,
  // so no need for code in the loop() function.
}
