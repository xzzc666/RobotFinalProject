#include "MyServerDef.h"

WebServer server(80);
IPAddress local_IP(192, 168, 4, 10); 
IPAddress gateway(192, 168, 4, 1); 
IPAddress subnet(255, 255, 255, 0);
const char* ssid = "ESP32Test";
const char* password = "1145141919";

WiFiUDP Udp;
unsigned int localUdpPort = 101;