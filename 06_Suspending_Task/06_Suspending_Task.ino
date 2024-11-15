#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8

// Typedef for profiling task runtime
typedef int TaskProfiler;

// Profiling variables to track how many times each task has run
TaskProfiler  RedLEDProfiler = 0;
TaskProfiler  YellowLEDProfiler = 0;
TaskProfiler  BlueLEDProfiler = 0;

// Task handles for controlling each LED task
TaskHandle_t Red_Handle, Yellow_Handle, Blue_Handle;

// Variable to monitor the suspension condition
uint32_t suspend_monitor = 0;

void setup() {
  // Initialize serial communication for monitoring
  Serial.begin(9600);

  // Create tasks for each LED control
  xTaskCreate(redLEDControllerTask,   // Red LED task
              "Red Led Task", 
              100, 
              NULL, 
              1, 
              &Red_Handle);

  xTaskCreate(yellowLEDControllerTask, // Yellow LED task
              "Yellow Led Task", 
              100, 
              NULL, 
              1, 
              &Yellow_Handle);

  xTaskCreate(BlueLEDControllerTask,   // Blue LED task
              "Blue Led Task", 
              100, 
              NULL, 
              1, 
              &Blue_Handle);
}

// Red LED control task
void redLEDControllerTask(void *pvParameters) {
  pinMode(RED, OUTPUT); // Set Red LED pin as output
  while (1) {
    RedLEDProfiler++; // Increment profiler for Red LED task
    Serial.print("Red Run Time: ");
    Serial.println(RedLEDProfiler); // Print Red LED task runtime
    vTaskDelay(100); // Delay for 100ms (non-blocking)
  }
}

// Yellow LED control task
void yellowLEDControllerTask(void *pvParameters) {
  pinMode(YELLOW, OUTPUT); // Set Yellow LED pin as output
  while (1) {
    suspend_monitor++; // Monitor condition for suspending Yellow task
    digitalWrite(YELLOW, !digitalRead(YELLOW)); // Toggle Yellow LED state
    YellowLEDProfiler++; // Increment profiler for Yellow LED task
    Serial.print("Yellow Run Time: ");
    Serial.println(YellowLEDProfiler); // Print Yellow LED task runtime
    vTaskDelay(100); // Delay for 100ms (non-blocking)
  }
}

// Blue LED control task
void BlueLEDControllerTask(void *pvParameters) {
  pinMode(BLUE, OUTPUT); // Set Blue LED pin as output
  while (1) {
    BlueLEDProfiler++; // Increment profiler for Blue LED task
    Serial.print("Blue Run Time: ");
    Serial.println(BlueLEDProfiler); // Print Blue LED task runtime
    
    // Suspend Yellow task after 10 cycles of Blue task execution
    if (suspend_monitor >= 10) {
      vTaskSuspend(Yellow_Handle); // Suspend Yellow LED task
      suspend_monitor = 0; // Reset suspend monitor to allow future suspension
    }

    vTaskDelay(100); // Delay for 100ms (non-blocking)
  }
}

void loop() {
  // Empty loop as tasks are managed by FreeRTOS
}
