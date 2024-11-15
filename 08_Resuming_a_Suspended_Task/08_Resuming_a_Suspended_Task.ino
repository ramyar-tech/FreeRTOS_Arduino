#include <Arduino_FreeRTOS.h>

#define RED     6
#define YELLOW  7
#define BLUE    8

typedef int TaskProfiler;

// Profiling variables for each LED task
TaskProfiler  RedLEDProfiler;
TaskProfiler  YellowLEDProfiler;
TaskProfiler  BlueLEDProfiler;

// Task handles for each LED task
TaskHandle_t Red_Handle, Yellow_Handle, Blue_Handle;

// Counters for monitoring suspend/resume behavior
uint32_t suspend_monitor;
uint32_t resume_monitor;
bool suspended = false;

void setup() {
  // Start serial communication for monitoring
  Serial.begin(9600);

  // Create FreeRTOS tasks for controlling the LEDs
  xTaskCreate(redLEDControllerTask,
              "Red Led Task",    // Task name
              100,               // Stack size (in words)
              NULL,              // Task input parameters
              1,                 // Task priority
              &Red_Handle       // Task handle
  );

  xTaskCreate(yellowLEDControllerTask,
              "Yellow Led Task",
              100,
              NULL,
              1,
              &Yellow_Handle
  );

  xTaskCreate(BlueLEDControllerTask,
              "Blue Led Task",
              100,
              NULL,
              1,
              &Blue_Handle
  );
}

// Task for controlling the Red LED
void redLEDControllerTask(void *pvParameters) {
  pinMode(RED, OUTPUT);  // Set the Red LED pin as an output

  while(1) {
    // Increment the profiler for Red LED task
    RedLEDProfiler++;
    // Print the run time for the Red LED task to Serial Monitor
    Serial.print("Red Run Time: ");
    Serial.println(RedLEDProfiler);

    // Delay for 100 ms to simulate work and give FreeRTOS scheduler a chance to run other tasks
    vTaskDelay(100);
  }
}

// Task for controlling the Yellow LED
void yellowLEDControllerTask(void *pvParameters) {
  pinMode(YELLOW, OUTPUT);  // Set the Yellow LED pin as an output

  while(1) {
    suspend_monitor++; // Increment the suspend monitor variable

    // Toggle the Yellow LED state
    digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
    
    // Increment the profiler for Yellow LED task
    YellowLEDProfiler++;
    // Print the run time for the Yellow LED task to Serial Monitor
    Serial.print("Yellow Run Time: ");
    Serial.println(YellowLEDProfiler);

    // Delay for 100 ms to simulate work
    vTaskDelay(100);

    // If suspended flag is true, resume the Blue LED task after 5 cycles
    if(suspended) {
      resume_monitor++;
      if(resume_monitor >= 5) {
        // Resume the Blue LED task
        vTaskResume(Blue_Handle);
        resume_monitor = 0;  // Reset the resume counter
        suspended = false;   // Reset the suspended flag
      }
    }
  }
}

// Task for controlling the Blue LED
void BlueLEDControllerTask(void *pvParameters) {
  pinMode(BLUE, OUTPUT);  // Set the Blue LED pin as an output

  while(1) {
    // Increment the profiler for Blue LED task
    BlueLEDProfiler++;
    // Print the run time for the Blue LED task to Serial Monitor
    Serial.print("Blue Run Time: ");
    Serial.println(BlueLEDProfiler);

    // Suspend the Blue LED task after 10 cycles of the Yellow LED task
    if(suspend_monitor >= 10) {
      suspended = true;    // Set the suspended flag
      suspend_monitor = 0; // Reset the suspend monitor counter
      vTaskSuspend(NULL);  // Suspend the current task (Blue LED task)
    }

    // Delay for 100 ms to simulate work
    vTaskDelay(100);
  }
}

void loop() {
  // No code is needed here since all tasks are handled by FreeRTOS
}
