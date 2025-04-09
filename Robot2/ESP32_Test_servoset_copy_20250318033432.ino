#include "MyUDP.h"
#include "MyUBTECH.h"

void setup() {
  xTaskCreate(ServosStart, "ServosControl", 4096, NULL, 1, NULL);
  xTaskCreate(UDPStart, "UDP", 4096, NULL, 1, NULL);
}

void loop() {
}


