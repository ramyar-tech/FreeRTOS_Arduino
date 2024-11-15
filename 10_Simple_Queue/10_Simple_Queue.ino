#include <Arduino_FreeRTOS.h>
#include "queue.h"

QueueHandle_t yearQueue;  // Declare a queue handle to store year data

void setup()
{
  // Start serial communication
  Serial.begin(9600);

  // Create the queue with space for 5 elements, each of size int32_t
  yearQueue = xQueueCreate(5, sizeof(int32_t));

  // Check if the queue was created successfully
  if (yearQueue == NULL) {
    Serial.println("Queue creation failed!");
    while(1);  // Halt the program if queue creation failed
  }

  // Create tasks for sending and receiving data
  xTaskCreate(vSenderTask, "Sender Task", 100, NULL, 1, NULL);
  xTaskCreate(vReceiverTask, "Receiver Task", 100, NULL, 1, NULL);
}

void vSenderTask(void *pvParameters)
{
  int32_t valuetoSend = 2019;  // Initialize the value to send

  while (1)
  {
    // Send the value to the queue, with no blocking time (0ms)
    BaseType_t qStatus = xQueueSend(yearQueue, &valuetoSend, 0);
    
    // Optionally, check if sending was successful
    if (qStatus != pdPASS) {
      Serial.println("Failed to send value to queue!");
    }

    vTaskDelay(pdMS_TO_TICKS(500));  // Delay for 500 ms before sending again
  }
}

void vReceiverTask(void *pvParameters)
{
  int32_t valueReceived;
  const TickType_t xTicksTOWait = pdMS_TO_TICKS(100);  // Set timeout for receiving data (100 ms)

  while (1)
  {
    // Attempt to receive data from the queue
    BaseType_t qStatus = xQueueReceive(yearQueue, &valueReceived, xTicksTOWait);

    // If data was received, print it
    if (qStatus == pdPASS) {
      Serial.print("Received Value: ");
      Serial.println(valueReceived);
    } else {
      // If queue is empty (no data received), notify
      Serial.println("No data received within the timeout period");
    }

    vTaskDelay(pdMS_TO_TICKS(500));  // Delay for 500 ms before trying again
  }
}

void loop() {
  // Empty loop, as the tasks handle everything
}
