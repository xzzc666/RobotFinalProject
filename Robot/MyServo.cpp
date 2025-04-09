#include "MyServo.h"

void timerCallback(void* targetServo) 
{
  myServo* servoPtr = (myServo*)targetServo;
  digitalWrite(servoPtr->writePin,LOW);
  // reset the pulse
}

void TaskDelay(void* targetServo)
{
  myServo* servoPtr = (myServo*)targetServo;
  
  pinMode(servoPtr->writePin,OUTPUT);
  // initialize the pinMode

  esp_timer_create_args_t timerPluseArgs = {
  .callback = &timerCallback,
  .arg = servoPtr,
  .name = servoPtr->taskSignalName
  };

  esp_timer_handle_t timerPluse;
  esp_timer_create(&timerPluseArgs, &timerPluse);
  // initialize the timer

  while(1)
  {
    digitalWrite(servoPtr->writePin,HIGH);
    // pulse signal start
    esp_timer_start_once(timerPluse, servoPtr->delayTime); 
    // timer will turn of the pulse signal after delayTime

    vTaskDelay(20/ (portTICK_PERIOD_MS)); 
    // a period of signal
    
  }
}

void SetServoDegree(myServo* targetServo, int degree)
{
  if(targetServo->isSetting)
  {
    return;
  }

  targetServo->isSetting = 1;
  // lock, make sure it will not be over change

  degree = degree + targetServo->errorFixAngle;
  // fix the initial angle error

  if( degree > targetServo->limitAngleEnd)
  {
    degree = targetServo->limitAngleEnd;
    targetServo->degree = degree;
    targetServo->delayTime = map(degree,0,180,500,2500);
  }
  else if(degree < targetServo->limitAngleStart)
  {
    degree = targetServo->limitAngleStart;
    targetServo->degree = degree;
    targetServo->delayTime = map(degree,0,180,500,2500);
  }
  else
  {
    targetServo->degree = degree;
    targetServo->delayTime = map(degree,0,180,500,2500);
  }
  //make sure the degree data is legal
    
  targetServo->isSetting = 0;
  // unlock

    return;
}

