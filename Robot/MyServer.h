#ifndef _MyServer_H_
#define _MyServer_H_

#include <WiFi.h>
#include <WebServer.h>
#include "MyServosDef.h"
#include "MyServo.h"
#include "MyServerDef.h"

void TaskWeb(void* WebData);
void handleRoot(void);

#endif