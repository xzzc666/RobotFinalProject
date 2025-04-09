#ifndef _MyServerDef_H_
#define _MyServerDef_H_

#include <WebServer.h>
#include <WiFi.h>
#include <WiFiUdp.h>

// 声明全局变量
extern WebServer server;
extern IPAddress local_IP;
extern IPAddress gateway;
extern IPAddress subnet;
extern const char* ssid;
extern const char* password;

extern WiFiUDP Udp;
extern unsigned int localUdpPort;

#endif