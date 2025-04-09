#include "MyUBTECH.h"

void ApplyServoAngle(uint8_t targetID)
{
  uint8_t angle = ReadServoDegreeState(targetID);
  uint8_t dataTrans[10] = 
  {
    0xFA, 
    0xAF,
    targetID,
    0x01,
    angle,
    0x00,
    0x00,
    0x00,
    0x00,
    0xED
  };

  dataTrans[8] = (uint8_t)((targetID + 0x01 + angle) & 0xFF);

  Serial.write(dataTrans,10);

}

void SetServoID(uint8_t IDBefore, uint8_t IDAfter)
{
  if(IDAfter > 240)
  {
    IDAfter = 240;
  }

  if(IDBefore > 240)
  {
    IDBefore = 240;
  }
  
  uint8_t dataTrans[10] = 
  {
    0xFA, 
    0xAF,
    IDBefore,
    0xCD,
    0x00,
    IDAfter,
    0x00,
    0x00,
    0x00,
    0xED
  };

  dataTrans[8] = (uint8_t)((IDBefore + 0xCD + IDAfter) & 0xFF);

  Serial.write(dataTrans,10);


}
// will not act on the servoState 

void ServosStart(void* servosData)
{
  Serial.begin(115200);
  vTaskDelay(100);
  while(1)
  {
    for(int i = 1; i <= 14; i++)
    {
      ApplyServoAngle(i);
      vTaskDelay(1);
    }
    
  }
}