#ifndef _MyServo_H_
#define _MyServo_H_
#include "Arduino.h"
#include "MyStruct.h"
#include "esp_timer.h"

void timerCallback(void* targetServo);

void TaskDelay(void* servoData);

void SetServoDegree(myServo* targetServo, int degree);

#endif
