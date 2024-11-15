#include <Arduino_FreeRTOS.h>

// Define pin numbers for the LEDs
#define RED     6
#define YELLOW  7
#define BLUE    8

// Typedef for profiling task run times
typedef int TaskProfiler;

// Profiling variables for tracking task execution
TaskProfiler RedLedProfiler = 0;
TaskProfiler YellowLedProfiler = 0;
TaskProfiler BlueLedProfiler = 0;

// Variables to store task priorities
int BlueTaskPriority = 0;
int RedTaskPriority = 0;
int YellowTaskPriority = 0;

// Task handles for managing tasks and their priorities
TaskHandle_t Red_Handle, Yellow_Handle, Blue_Handle;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Create FreeRTOS tasks for each LED
  xTaskCreate(redControllerTask,    // Task function
              "RED LED Task",       // Task name
              100,                  // Stack size
              NULL,                 // Task parameters
              1,                    // Priority
              &Red_Handle);         // Task handle

  xTaskCreate(yellowControllerTask, // Task function
              "YELLOW LED Task",    // Task name
              100,                  // Stack size
              NULL,                 // Task parameters
              1,                    // Priority
              &Yellow_Handle);      // Task handle

  xTaskCreate(blueControllerTask,   // Task function
              "BLUE LED Task",      // Task name
              100,                  // Stack size
              NULL,                 // Task parameters
              2,                    // Priority
              &Blue_Handle);        // Task handle
}

// Task to control the Red LED
void redControllerTask(void *pvParameters) {
  while (1) {
    RedLedProfiler++;
    Serial.print("RED Task Run Time: ");
    Serial.println(RedLedProfiler);
    vTaskDelay(300 / portTICK_PERIOD_MS); // Delay for 300ms
  }
}

// Task to control the Yellow LED
void yellowControllerTask(void *pvParameters) {
  while (1) {
    YellowLedProfiler++;
    Serial.print("YELLOW Task Run Time: ");
    Serial.println(YellowLedProfiler);
    vTaskDelay(300 / portTICK_PERIOD_MS); // Delay for 300ms
  }
}

// Task to control the Blue LED and monitor priorities
void blueControllerTask(void *pvParameters) {
  while (1) {
    BlueLedProfiler++;
    // Retrieve and print task priorities
    BlueTaskPriority = uxTaskPriorityGet(NULL);           // Priority of current (Blue) task
    RedTaskPriority = uxTaskPriorityGet(Red_Handle);      // Priority of Red task
    YellowTaskPriority = uxTaskPriorityGet(Yellow_Handle); // Priority of Yellow task

    Serial.print("BLUE Task Priority: ");
    Serial.println(BlueTaskPriority);
    Serial.print("RED Task Priority: ");
    Serial.println(RedTaskPriority);
    Serial.print("YELLOW Task Priority: ");
    Serial.println(YellowTaskPriority);

    vTaskDelay(300 / portTICK_PERIOD_MS); // Delay for 300ms
  }
}

void loop() {
  // Empty loop as FreeRTOS manages tasks
}
