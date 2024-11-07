#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set pinMode for LEDs (done once in setup)
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  // Create FreeRTOS tasks for each LED control
  xTaskCreate(ledControllerTask, "Red LED Task", 100, (void *)RED, 1, NULL);
  xTaskCreate(ledControllerTask, "Yellow LED Task", 100, (void *)YELLOW, 1, NULL);
  xTaskCreate(ledControllerTask, "Blue LED Task", 100, (void *)BLUE, 1, NULL);
}

void ledControllerTask(void *pvParameters)
{
  int ledPin = (int)pvParameters; // Cast the passed pin number to an integer

  while(1) {
    // Toggle LED state
    digitalWrite(ledPin, !digitalRead(ledPin)); 
    
    // Wait for a period before toggling again
    vTaskDelay(500 / portTICK_PERIOD_MS); // Delay for 500ms (FreeRTOS delay)
  }
}

void loop() {
  // The loop is empty since the tasks are managed by FreeRTOS
}
