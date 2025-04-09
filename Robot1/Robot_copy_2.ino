#include "MyServo.h"
#include "MyServosDef.h"
#include "MyServer.h"

void setup() 
{
  Serial.begin(115200);
  vTaskDelay(1000/ (portTICK_PERIOD_MS)); 
  Serial.println("Start");
  vTaskDelay(1000/ (portTICK_PERIOD_MS)); 

  
  xTaskCreate(TaskWeb, "Web", 4096, NULL, 1, NULL);
  vTaskDelay(1000/ (portTICK_PERIOD_MS)); 
  Serial.println("Web xTaskCreate Done");
  vTaskDelay(1000/ (portTICK_PERIOD_MS)); 

  xTaskCreate(TaskDelay, hipL.taskSignalName, 2048, &hipL, 2, NULL);
  xTaskCreate(TaskDelay, hipR.taskSignalName, 2048, &hipR, 2, NULL);
  xTaskCreate(TaskDelay, thighL.taskSignalName, 2048, &thighL, 2, NULL);
  xTaskCreate(TaskDelay, thighR.taskSignalName, 2048, &thighR, 2, NULL);
  xTaskCreate(TaskDelay, calfL.taskSignalName, 2048, &calfL, 2, NULL);
  xTaskCreate(TaskDelay, calfR.taskSignalName, 2048, &calfR, 2, NULL);
  xTaskCreate(TaskDelay, ankleR.taskSignalName, 2048, &ankleR, 2, NULL);
  xTaskCreate(TaskDelay, ankleL.taskSignalName, 2048, &ankleL, 2, NULL);

  vTaskDelay(1000/ (portTICK_PERIOD_MS)); 
  Serial.println("Servo xTaskCreate Done");
  vTaskDelay(1000/ (portTICK_PERIOD_MS)); 

  
}

void loop() {

}
