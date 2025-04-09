#include "MyUDP.h"

IPAddress local_IP(192, 168, 4, 10); 
IPAddress gateway(192, 168, 4, 1); 
IPAddress subnet(255, 255, 255, 0);
const char* ssid = "ESP32Test";
const char* password = "1145141919";

WiFiUDP myUDP;
const unsigned int udpLocalPort = 514;
IPAddress target_IP(192, 168, 4, 255); 
const unsigned int udpTargetPort = 114;

void UDPStart(void* udpData)
{
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ssid, password);
  
  vTaskDelay(100);

  myUDP.begin(udpLocalPort);

  char packetBuffer[255];

  while (1)
  {
    int packetSize = myUDP.parsePacket();

    if (packetSize)
    {
      int len = myUDP.read(packetBuffer, sizeof(packetBuffer) - 1);
      if (len > 0)
      {
        packetBuffer[len] = '\0';
      }
      else {
        packetBuffer[0] = '\0';
      }

      int a, b, c, d;
      if (sscanf(packetBuffer, "ID:%d Degree:%d", &a, &b) == 2)
      {
        SetServoDegreeState((uint8_t)a, (uint8_t)b);
        
      }

    }

    vTaskDelay(1);

  }

}

