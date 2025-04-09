#include "MyServer.h"

void TaskWeb(void* WebData)
{

  WiFi.softAP(ssid, password);

  server.on("/", handleRoot);

  server.begin();

  while(1)
  {
    server.handleClient(); 
    vTaskDelay(10/ (portTICK_PERIOD_MS)); 
  }

}

void handleRoot() {
  if (server.hasArg("hipL")) {
    String sliderValue = server.arg("hipL");
    int servoValue = sliderValue.toInt();
    SetServoDegree(&hipL, servoValue); 
  }

  if (server.hasArg("hipR")) {
    String sliderValue = server.arg("hipR");
    int servoValue = sliderValue.toInt();
    SetServoDegree(&hipR, servoValue); 
  }

  if (server.hasArg("thighL")) {
    String sliderValue = server.arg("thighL");
    int servoValue = sliderValue.toInt();
    SetServoDegree(&thighL, servoValue);
  }

  if (server.hasArg("thighR")) {
    String sliderValue = server.arg("thighR");
    int servoValue = sliderValue.toInt();
    SetServoDegree(&thighR, servoValue);
  }

  if (server.hasArg("calfL")) {
    String sliderValue = server.arg("calfL");
    int servoValue = sliderValue.toInt();
    SetServoDegree(&calfL, servoValue);
  }

  if (server.hasArg("calfR")) {
    String sliderValue = server.arg("calfR");
    int servoValue = sliderValue.toInt();
    SetServoDegree(&calfR, servoValue); 
  }

  if (server.hasArg("ankleL")) {
    String sliderValue = server.arg("ankleL");
    int servoValue = sliderValue.toInt();
    SetServoDegree(&ankleL, servoValue); 
  }

  if (server.hasArg("ankleR")) {
    String sliderValue = server.arg("ankleR");
    int servoValue = sliderValue.toInt();
    SetServoDegree(&ankleR, servoValue); 
  }


  String html = "<!DOCTYPE html><html><body>";
  html += "<h6>ESP32 Control</h6>";
  html += "<form action='/' method='GET'>";
    html += "<!DOCTYPE html><html><body>";

  // hipL
  html += "<div style='display: flex; align-items: center; margin-bottom: 10px;'>";
  html += "<h6>hipL</h6>";
  html += "<h6 style='margin-left: 10px;'>" + String(hipL.degree) + "</h6>";
  html += "<input type='number' name='hipL' min='0' max='180' value='" + String(hipL.degree) + "' style='margin-left: 10px;'>";
  html += "</div>";

  // hipR
  html += "<div style='display: flex; align-items: center; margin-bottom: 10px;'>";
  html += "<h6>hipR</h6>";
  html += "<h6 style='margin-left: 10px;'>" + String(hipR.degree) + "</h6>";
  html += "<input type='number' name='hipR' min='0' max='180' value='" + String(hipR.degree) + "' style='margin-left: 10px;'>";
  html += "</div>";

  // thighL
  html += "<div style='display: flex; align-items: center; margin-bottom: 10px;'>";
  html += "<h6>thighL</h6>";
  html += "<h6 style='margin-left: 10px;'>" + String(thighL.degree) + "</h6>";
  html += "<input type='number' name='thighL' min='0' max='180' value='" + String(thighL.degree) + "' style='margin-left: 10px;'>";
  html += "</div>";

  // thighR
  html += "<div style='display: flex; align-items: center; margin-bottom: 10px;'>";
  html += "<h6>thighR</h6>";
  html += "<h6 style='margin-left: 10px;'>" + String(thighR.degree) + "</h6>";
  html += "<input type='number' name='thighR' min='0' max='180' value='" + String(thighR.degree) + "' style='margin-left: 10px;'>";
  html += "</div>";

  // calfL
  html += "<div style='display: flex; align-items: center; margin-bottom: 10px;'>";
  html += "<h6>calfL</h6>";
  html += "<h6 style='margin-left: 10px;'>" + String(calfL.degree) + "</h6>";
  html += "<input type='number' name='calfL' min='0' max='180' value='" + String(calfL.degree) + "' style='margin-left: 10px;'>";
  html += "</div>";

  // calfR
  html += "<div style='display: flex; align-items: center; margin-bottom: 10px;'>";
  html += "<h6>calfR</h6>";
  html += "<h6 style='margin-left: 10px;'>" + String(calfR.degree) + "</h6>";
  html += "<input type='number' name='calfR' min='0' max='180' value='" + String(calfR.degree) + "' style='margin-left: 10px;'>";
  html += "</div>";

  // ankleL
  html += "<div style='display: flex; align-items: center; margin-bottom: 10px;'>";
  html += "<h6>ankleL</h6>";
  html += "<h6 style='margin-left: 10px;'>" + String(ankleL.degree) + "</h6>";
  html += "<input type='number' name='ankleL' min='0' max='180' value='" + String(ankleL.degree) + "' style='margin-left: 10px;'>";
  html += "</div>";

  // ankleR
  html += "<div style='display: flex; align-items: center; margin-bottom: 10px;'>";
  html += "<h6>ankleR</h6>";
  html += "<h6 style='margin-left: 10px;'>" + String(ankleR.degree) + "</h6>";
  html += "<input type='number' name='ankleR' min='0' max='180' value='" + String(ankleR.degree) + "' style='margin-left: 10px;'>";
  html += "</div>";


  html += "<input type='submit' value='Submit'>"; 
  html += "</form>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}