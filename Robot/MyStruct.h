#ifndef _MyStruct_H_
#define _MyStruct_H_
#include "Arduino.h"

typedef struct
{
  const char* taskSignalName;
  int writePin;
  int readPin;
  int delayTime;
  int degree;
  int isLeft;
  int limitAngleStart;
  int limitAngleEnd;
  int errorFixAngle;
  int isSetting;

} myServo;

#endif
