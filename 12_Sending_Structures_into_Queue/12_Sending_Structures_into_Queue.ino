#include <Arduino_FreeRTOS.h>
#include "queue.h"

#define RED     6  // Red LED pin (unused, but could be used for visualization)
#define YELLOW  7  // Yellow LED pin (unused, but could be used for visualization)
#define BLUE    8  // Blue LED pin (unused, but could be used for visualization)

// Typedef to define task profiling variables
typedef int TaskProfiler;

TaskProfiler SenderTaskProfiler;   // Profiling variable for sender tasks
TaskProfiler ReceiverTaskProfiler; // Profiling variable for receiver tasks

// Enum for identifying the data source
typedef enum
{
  eSender1, // Sender Task 1
  eSender2  // Sender Task 2
} DataSource_t;

// Structure to hold data sent to the queue
typedef struct
{
  uint8_t ucValue;        // Data value
  DataSource_t eDataSource; // Enum to identify which sender the data is from
} Data_t;

// Data to send by each sender
static const Data_t xStructToSend[2] = 
{
  {100, eSender1}, // Sender Task 1 sends value 100
  {20, eSender2}   // Sender Task 2 sends value 20
};

// Queue handle
QueueHandle_t xQueue;

void setup()
{
  Serial.begin(9600);  // Initialize Serial communication
  
  // Create a queue to hold `Data_t` structures with a capacity of 3 elements
  xQueue = xQueueCreate(3, sizeof(Data_t));
  
  // Check if queue creation was successful
  if (xQueue == NULL)
  {
    Serial.println("Failed to create queue!");
    while (1); // Halt the program if the queue couldn't be created
  }

  // Create two sender tasks with their respective data
  xTaskCreate(vSenderTask, "Sender Task 1", 100, &xStructToSend[0], 2, NULL);
  xTaskCreate(vSenderTask, "Sender Task 2", 100, &xStructToSend[1], 2, NULL);

  // Create a receiver task
  xTaskCreate(vReceiverTask, "Receiver Task", 100, NULL, 1, NULL);
}

// Sender Task: Sends data to the queue
void vSenderTask(void *pvParameters)
{
  BaseType_t xStatus;
  const TickType_t xTicksToWait = pdMS_TO_TICKS(100); // Wait time if queue is full

  while (1)
  {
    // Attempt to send data to the queue
    xStatus = xQueueSend(xQueue, pvParameters, xTicksToWait);
    
    // Check if the data was sent successfully
    if (xStatus != pdPASS)
    {
      Serial.println("Couldn't send to the queue");
    }

    // Simulate some delay (can be replaced with actual work)
    vTaskDelay(pdMS_TO_TICKS(200));
  }
}

// Receiver Task: Receives data from the queue and processes it
void vReceiverTask(void *pvParameters)
{
  Data_t xReceivedStructure; // Structure to hold received data
  BaseType_t xStatus;

  while (1)
  {
    // Attempt to receive data from the queue
    xStatus = xQueueReceive(xQueue, &xReceivedStructure, pdMS_TO_TICKS(100));

    // Check if data was received successfully
    if (xStatus == pdPASS)
    {
      // Process received data based on its source
      if (xReceivedStructure.eDataSource == eSender1)
      {
        Serial.print("This is from Sender 1: ");
        Serial.println(xReceivedStructure.ucValue);
      }
      else if (xReceivedStructure.eDataSource == eSender2)
      {
        Serial.print("This is from Sender 2: ");
        Serial.println(xReceivedStructure.ucValue);
      }
    }
    else
    {
      // Print an error message if no data was received
      Serial.println("Couldn't receive data from queue");
    }
  }
}

void loop()
{
  // Empty loop as tasks are managed by FreeRTOS
}
