#ifndef _MyRobotState_H_
#define _MyRobotState_H_

#include <Arduino.h>

typedef struct
{
  const char* name;
  uint8_t ID;
  uint8_t degree;
  uint8_t errorFixAngle;
  uint8_t isChanging;
  uint8_t savedDegree;
} myServo;

extern myServo lowerFeetL;
extern myServo lowerFeetR;

extern myServo upperFeetL;
extern myServo upperFeetR;

extern myServo lowerLegL;
extern myServo lowerLegR;

extern myServo upperLegL;
extern myServo upperLegR;

extern myServo hipL;
extern myServo hipR;

extern myServo upperArmL;
extern myServo upperArmR;

extern myServo lowerArmL;
extern myServo lowerArmR;

extern myServo* servos[];


void SetServoDegreeState(uint8_t ID, uint8_t degree);
uint8_t ReadServoDegreeState(uint8_t ID);

#endif