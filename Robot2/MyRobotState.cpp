#include "MyRobotState.h"

myServo lowerFeetL = 
{
  .name = "lowerFeetL",
  .ID = 1,
  .degree = 120,
  .errorFixAngle = -5,
  .isChanging = 0,
  .savedDegree = 120
};

myServo lowerFeetR = 
{
  .name = "lowerFeetR",
  .ID = 2,
  .degree = 120,
  .errorFixAngle = 3,
  .isChanging = 0,
  .savedDegree = 120
};

myServo upperFeetL = 
{
  .name = "upperFeetL",
  .ID = 3,
  .degree = 120-22,
  .errorFixAngle = 0,
  .isChanging = 0,
  .savedDegree = 120
};

myServo upperFeetR = 
{
  .name = "upperFeetR",
  .ID = 4,
  .degree = 120+22,
  .errorFixAngle = 0,
  .isChanging = 0,
  .savedDegree = 120
};

myServo lowerLegL = 
{
  .name = "lowerLegL",
  .ID = 5,
  .degree = 20+22,
  .errorFixAngle = 5,
  .isChanging = 0,
  .savedDegree = 120
};

myServo lowerLegR = 
{
  .name = "lowerLegR",
  .ID = 6,
  .degree = 220-22,
  .errorFixAngle = -10,
  .isChanging = 0,
  .savedDegree = 120
};

myServo upperLegL = 
{
  .name = "upperLegL",
  .ID = 7,
  .degree = 120,
  .errorFixAngle = -5,
  .isChanging = 0,
  .savedDegree = 120
};

myServo upperLegR = 
{
  .name = "upperLegR",
  .ID = 8,
  .degree = 120,
  .errorFixAngle = 0,
  .isChanging = 0,
  .savedDegree = 120
};

myServo hipL = 
{
  .name = "hipL",
  .ID = 9,
  .degree = 120,
  .errorFixAngle = -5,
  .isChanging = 0,
  .savedDegree = 120
};

myServo hipR = 
{
  .name = "hipR",
  .ID = 10,
  .degree = 120,
  .errorFixAngle = -5,
  .isChanging = 0,
  .savedDegree = 120
};

myServo upperArmL = 
{
  .name = "upperArmL",
  .ID = 11,
  .degree = 120,
  .errorFixAngle = 5,
  .isChanging = 0,
  .savedDegree = 120
};

myServo upperArmR = 
{
  .name = "upperArmR",
  .ID = 12,
  .degree = 120,
  .errorFixAngle = 5,
  .isChanging = 0,
  .savedDegree = 120
};

myServo lowerArmL = 
{
  .name = "lowerArmL",
  .ID = 13,
  .degree = 120,
  .errorFixAngle = 5,
  .isChanging = 0,
  .savedDegree = 120
};

myServo lowerArmR = 
{
  .name = "lowerArmR",
  .ID = 14,
  .degree = 120,
  .errorFixAngle = 0,
  .isChanging = 0,
  .savedDegree = 120
};

myServo* servos[] = {
  &lowerFeetL, &lowerFeetR, &upperFeetL, &upperFeetR,
  &lowerLegL, &lowerLegR, &upperLegL, &upperLegR,
  &hipL, &hipR, &upperArmL, &upperArmR,
  &lowerArmL, &lowerArmR
};

void SetServoDegreeState(uint8_t ID, uint8_t degree)
{
  ID = ID - 1;
  if(ID >= 0 && ID <= 13 && degree >= 20 && degree <= 220 )
  {
    servos[ID] -> degree = degree;
  }
  return;
}

uint8_t ReadServoDegreeState(uint8_t ID)
{
  ID = ID - 1;
  return (servos[ID] -> degree + servos[ID] -> errorFixAngle);
}


