#include <Arduino_FreeRTOS.h>
#include "queue.h"

// Pin definitions for LEDs
#define   RED     6
#define   YELLOW  7
#define   BLUE    8

// Queue handles
QueueHandle_t xQueue1;
QueueHandle_t xQueue2;

// Queue set handle
QueueSetHandle_t xQueueSet;

void setup()
{
  // Initialize the Serial Monitor and set pin modes
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);

  // Create two queues, each capable of holding one pointer to a string
  xQueue1  = xQueueCreate(1, sizeof(char *));
  xQueue2  = xQueueCreate(1, sizeof(char *));

  // Create a queue set with enough space to accommodate both queues
  xQueueSet = xQueueCreateSet(1 * 2);

  // Add the queues to the queue set
  xQueueAddToSet(xQueue1, xQueueSet);
  xQueueAddToSet(xQueue2, xQueueSet);

  // Create tasks for the sender and receiver
  xTaskCreate(vSenderTask1, "Sender Task 1", 100, NULL, 1, NULL);
  xTaskCreate(vSenderTask2, "Sender Task 2", 100, NULL, 1, NULL);
  xTaskCreate(vReceiverTask, "Receiver Task", 100, NULL, 2, NULL);
}

void vSenderTask1(void *pvParameters)
{
  // Block time between sending messages
  const TickType_t xBlockTime = pdMS_TO_TICKS(100);

  // Message to be sent by this task
  const char * const messageToSend = "Message from Sender 1";

  while (1)
  {
    vTaskDelay(xBlockTime); // Delay for 100ms
    xQueueSend(xQueue1, &messageToSend, 0); // Send message to queue 1
  }
}

void vSenderTask2(void *pvParameters)
{
  // Block time between sending messages
  const TickType_t xBlockTime = pdMS_TO_TICKS(200);

  // Message to be sent by this task
  const char * const messageToSend = "Message from Sender 2";

  while (1)
  {
    vTaskDelay(xBlockTime); // Delay for 200ms
    xQueueSend(xQueue2, &messageToSend, 0); // Send message to queue 2
  }
}

void vReceiverTask(void *pvParameters)
{
  QueueHandle_t xQueueThatContainsData; // Queue that contains data
  char *pcReceivedString; // Variable to store the received string

  while (1)
  {
    // Wait for data to be available in any queue in the set
    xQueueThatContainsData = (QueueHandle_t)xQueueSelectFromSet(xQueueSet, portMAX_DELAY);

    // Retrieve the message from the selected queue
    xQueueReceive(xQueueThatContainsData, &pcReceivedString, 0);

    // Print the received message to the Serial Monitor
    Serial.println(pcReceivedString);
  }
}

void loop() {
  // Empty loop as FreeRTOS handles task execution
}
