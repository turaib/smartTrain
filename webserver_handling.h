#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#ifndef WS_HANDLING
#define WS_HANDLING
#include "server_content.h"
#include "train.h"

Train train("Locomotive",0);  //Train name, and GPIO pin (in this case, pin 0)
ESP8266WebServer server(80);


void handleRoot() {
  server.send(200, "text/html",content);
  train.setSpeed(0);
  train.engineOFF();
}

void handleNotFound() {
  String message = train.toString();
  for (uint8_t i = 0; i < server.args(); i++) {
    if(server.argName(i) == String("engine")){
      if(server.arg(i) == String("on")){
        train.engineON();
      }else{
        train.engineOFF();
      }
    }
    if(server.argName(i) == String("speed")){
      String spd=server.arg(i);
      train.setSpeed(spd.toInt());
    }
    
  }
  server.send(200, "text/plain", message);
}

#endif
