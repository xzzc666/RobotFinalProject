#ifndef _MyServerUDP_H_
#define _MyServerUDP_H_

#include <WiFi.h>
#include <WiFiUdp.h>
#include <WebServer.h>
#include "MyServosDef.h"
#include "MyServo.h"
#include "MyServerDef.h"

void TaskUDP(void* WebData);

#endif