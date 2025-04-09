#include "WiFiType.h"
#include "MyServerUDP.h"

void TaskUDP(void* WebData)
{
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ssid, password);
  Udp.begin(localUdpPort);
  const int maxIndex = 9;
  Serial.println("TaskUDP start");
  Serial.printf("IP:%s, UDP:%d\n", WiFi.softAPIP().toString().c_str(), localUdpPort);


  while(1)
  {
    int angleValue[maxIndex+1];
    for (int i = 0; i <= maxIndex; i++) 
    {
      angleValue[i] = -1;
    }
    
    while(Udp.available())
    {
      Udp.read();
    }
    // clean the buffer

    Udp.parsePacket();

    for(int myIndex = 0; myIndex <= maxIndex; myIndex++)
    {
      if(Udp.available())
      {
        angleValue[myIndex] = Udp.read();
      }
    }

    if(angleValue[0] == 255 && angleValue[maxIndex] == 254)
    {
      if (angleValue[1] >= 0 && angleValue[1] <= 180) SetServoDegree(&ankleL, angleValue[1]);
      if (angleValue[2] >= 0 && angleValue[2] <= 180) SetServoDegree(&calfL, angleValue[2]);
      if (angleValue[3] >= 0 && angleValue[3] <= 180) SetServoDegree(&thighL, angleValue[3]);
      if (angleValue[4] >= 0 && angleValue[4] <= 180) SetServoDegree(&hipL, angleValue[4]);
      if (angleValue[5] >= 0 && angleValue[5] <= 180) SetServoDegree(&hipR, angleValue[5]);
      if (angleValue[6] >= 0 && angleValue[6] <= 180) SetServoDegree(&thighR, angleValue[6]);
      if (angleValue[7] >= 0 && angleValue[7] <= 180) SetServoDegree(&calfR, angleValue[7]);
      if (angleValue[8] >= 0 && angleValue[8] <= 180) SetServoDegree(&ankleR, angleValue[8]);

    }
    // make sure the data pack is end at a current point

    vTaskDelay(1/ (portTICK_PERIOD_MS)); 
  }

}

