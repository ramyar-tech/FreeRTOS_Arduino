#include <Arduino_FreeRTOS.h>

// Pin definitions for the three LEDs
#define RED     6
#define YELLOW  7
#define BLUE    8

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Create FreeRTOS tasks for controlling LEDs
  xTaskCreate(redLEDControllerTask,   // Task function
              "Red Led Task",          // Task name
              100,                     // Stack size (in words)
              NULL,                    // Parameters for the task
              1,                       // Task priority
              NULL);                   // Handle for task
  
  xTaskCreate(yellowLEDControllerTask,   // Task function
              "Yellow Led Task",         // Task name
              100,                       // Stack size (in words)
              NULL,                       // Parameters for the task
              1,                          // Task priority
              NULL);                      // Handle for task
  
  xTaskCreate(BlueLEDControllerTask,     // Task function
              "Blue Led Task",           // Task name
              100,                       // Stack size (in words)
              NULL,                       // Parameters for the task
              1,                          // Task priority
              NULL);                      // Handle for task
}

void redLEDControllerTask(void *pvParameters)
{
  // Set the RED pin as output
  pinMode(RED, OUTPUT);

  while(1) {
    // Print "Red" to the Serial Monitor
    Serial.println("Red");
    // (Future improvement) Toggle LED state every 500 ms or as per requirement
    vTaskDelay(500 / portTICK_PERIOD_MS);  // FreeRTOS delay, 500ms
  }
}

void yellowLEDControllerTask(void *pvParameters)
{
  // Set the YELLOW pin as output
  pinMode(YELLOW, OUTPUT);

  while(1) {
    // Print "Yellow" to the Serial Monitor
    Serial.println("Yellow");
    // (Future improvement) Toggle LED state every 500 ms or as per requirement
    vTaskDelay(500 / portTICK_PERIOD_MS);  // FreeRTOS delay, 500ms
  }
}

void BlueLEDControllerTask(void *pvParameters)
{
  // Set the BLUE pin as output
  pinMode(BLUE, OUTPUT);

  while(1) {
    // Print "Blue" to the Serial Monitor
    Serial.println("Blue");
    // (Future improvement) Toggle LED state every 500 ms or as per requirement
    vTaskDelay(500 / portTICK_PERIOD_MS);  // FreeRTOS delay, 500ms
  }
}

void loop() {
  // Empty loop since the tasks are managed by FreeRTOS
}
