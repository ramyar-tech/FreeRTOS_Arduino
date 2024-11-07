#include <Arduino_FreeRTOS.h>

// Define pin numbers for the LEDs
#define RED     6
#define YELLOW  7
#define BLUE    8

// Task handles for each LED task
TaskHandle_t red_handle, yellow_handle, blue_handle;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Create FreeRTOS tasks for each LED control
  xTaskCreate(RedLEDControllerTask,    // Task function
              "Red LED Task",          // Task name
              100,                     // Stack size
              NULL,                    // Task parameters
              1,                       // Priority
              &red_handle);            // Task handle
  
  xTaskCreate(YellowLEDControllerTask, // Task function
              "Yellow LED Task",       // Task name
              100,                     // Stack size
              NULL,                    // Task parameters
              1,                       // Priority
              &yellow_handle);         // Task handle
  
  xTaskCreate(BlueLEDControllerTask,   // Task function
              "Blue LED Task",         // Task name
              100,                     // Stack size
              NULL,                    // Task parameters
              1,                       // Priority
              &blue_handle);           // Task handle
}

// Task to control the Red LED
void RedLEDControllerTask(void *pvParameters) {
  pinMode(RED, OUTPUT); // Set RED LED pin as output
  while (1) {
    digitalWrite(RED, !digitalRead(RED)); // Toggle RED LED state
    Serial.println("Red LED Toggled");    // Print status to Serial Monitor
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1 second
  }
}

// Task to control the Yellow LED and change priority of Red LED task
void YellowLEDControllerTask(void *pvParameters) {
  pinMode(YELLOW, OUTPUT); // Set YELLOW LED pin as output
  while (1) {
    digitalWrite(YELLOW, !digitalRead(YELLOW)); // Toggle YELLOW LED state
    Serial.println("Yellow LED Toggled");       // Print status to Serial Monitor
    
    // Change the priority of the Red LED task to 2 (higher priority)
    vTaskPrioritySet(red_handle, 2);
    Serial.println("Red LED Priority changed to 2");
    
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1 second
  }
}

// Task to control the Blue LED
void BlueLEDControllerTask(void *pvParameters) {
  pinMode(BLUE, OUTPUT); // Set BLUE LED pin as output
  while (1) {
    digitalWrite(BLUE, !digitalRead(BLUE)); // Toggle BLUE LED state
    Serial.println("Blue LED Toggled");     // Print status to Serial Monitor
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay 1 second
  }
}

void loop() {
  // Empty loop since the tasks are managed by FreeRTOS
}
