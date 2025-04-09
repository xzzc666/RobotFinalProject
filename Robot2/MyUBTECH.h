#ifndef _MyUBTECH_H_
#define _MyUBTECH_H_

#include <stdint.h>
#include <Arduino.h> 
#include "MyRobotState.h"

void ApplyServoAngle(uint8_t targetID);

void SetServoID(uint8_t IDBefore, uint8_t IDAfter);

void ServosStart(void* servosData);

#endif