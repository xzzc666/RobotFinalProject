#include "MyServo.h"
#include "MyServosDef.h"


void setup() 
{
  Serial.begin(115200);
  vTaskDelay(1000/ (portTICK_PERIOD_MS)); 
  Serial.println("Start");
  vTaskDelay(1000/ (portTICK_PERIOD_MS)); 

  xTaskCreate(TaskDelay, hipL.taskSignalName, 2048, &hipL, 1, NULL);
  xTaskCreate(TaskDelay, hipR.taskSignalName, 2048, &hipR, 1, NULL);
  xTaskCreate(TaskDelay, thighL.taskSignalName, 2048, &thighL, 1, NULL);
  xTaskCreate(TaskDelay, thighR.taskSignalName, 2048, &thighR, 1, NULL);
  xTaskCreate(TaskDelay, calfL.taskSignalName, 2048, &calfL, 1, NULL);
  xTaskCreate(TaskDelay, calfR.taskSignalName, 2048, &calfR, 1, NULL);
  xTaskCreate(TaskDelay, ankleR.taskSignalName, 2048, &ankleR, 1, NULL);
  xTaskCreate(TaskDelay, ankleL.taskSignalName, 2048, &ankleL, 1, NULL);

  vTaskDelay(1000/ (portTICK_PERIOD_MS)); 
  Serial.println("Servo xTaskCreate Done");
  vTaskDelay(1000/ (portTICK_PERIOD_MS)); 

  
}

void loop() {

}
