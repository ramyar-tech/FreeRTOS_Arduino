#include <Arduino_FreeRTOS.h>

// Define pins for each LED
#define RED     6
#define YELLOW  7
#define BLUE    8

// Typedef for profiling each task's runtime
typedef int TaskProfiler;

// Profiling variables to track how many times each task has run
TaskProfiler RedLEDProfiler = 0;
TaskProfiler YellowLEDProfiler = 0;
TaskProfiler BlueLEDProfiler = 0;

// Task handles for managing and potentially changing task properties like priority
TaskHandle_t red_handle, yellow_handle, blue_handle;

void setup() {
  // Initialize serial communication for monitoring
  Serial.begin(9600);

  // Create FreeRTOS tasks for each LED control
  xTaskCreate(RedLEDControllerTask,       // Task function
              "Red LED Task",             // Task name
              100,                        // Stack size
              NULL,                       // Parameters
              1,                          // Priority
              &red_handle);               // Task handle

  xTaskCreate(YellowLEDControllerTask,    // Task function
              "Yellow LED Task",          // Task name
              100,                        // Stack size
              NULL,                       // Parameters
              1,                          // Priority
              &yellow_handle);            // Task handle

  xTaskCreate(BlueLEDControllerTask,      // Task function
              "Blue LED Task",            // Task name
              100,                        // Stack size
              NULL,                       // Parameters
              1,                          // Priority
              &blue_handle);              // Task handle
}

// Task to control the Red LED and track how many times it has run
void RedLEDControllerTask(void *pvParameters) {
  pinMode(RED, OUTPUT); // Set RED LED pin as output
  while (1) {
    RedLEDProfiler++; // Increment profiler for Red LED
    Serial.print("Red Task Run Time: ");
    Serial.println(RedLEDProfiler);

    // Toggle the RED LED state
    digitalWrite(RED, !digitalRead(RED));

    // Delay for 300ms (non-blocking)
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

// Task to control the Yellow LED and track how many times it has run
void YellowLEDControllerTask(void *pvParameters) {
  pinMode(YELLOW, OUTPUT); // Set YELLOW LED pin as output
  while (1) {
    YellowLEDProfiler++; // Increment profiler for Yellow LED
    Serial.print("Yellow Task Run Time: ");
    Serial.println(YellowLEDProfiler);

    // Toggle the YELLOW LED state
    digitalWrite(YELLOW, !digitalRead(YELLOW));

    // Adjust the priority of the Yellow LED task as an example of task management
    vTaskPrioritySet(yellow_handle, 1);

    // Delay for 300ms (non-blocking)
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

// Task to control the Blue LED and track how many times it has run
void BlueLEDControllerTask(void *pvParameters) {
  pinMode(BLUE, OUTPUT); // Set BLUE LED pin as output
  while (1) {
    BlueLEDProfiler++; // Increment profiler for Blue LED
    Serial.print("Blue Task Run Time: ");
    Serial.println(BlueLEDProfiler);

    // Toggle the BLUE LED state
    digitalWrite(BLUE, !digitalRead(BLUE));

    // Delay for 300ms (non-blocking)
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

void loop() {
  // Empty loop as tasks are managed by FreeRTOS
}
