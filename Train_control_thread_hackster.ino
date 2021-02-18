#include "webserver_handling.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Scheduler.h>

class HandleClient:public Task{
  protected:
    void loop(){
      server.handleClient();
    }
} client_task;




void setup() {
  train.setAcceleration(true);
  WiFi.hostname(train.getName());
  WiFi.mode(WIFI_STA);


  //modify this line
  WiFi.begin("SSID", "PW");
  
  
  
  Serial.begin(115200);
  Serial.println();
  Serial.println("Starting..");
  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println(WiFi.localIP());
  Scheduler.start(&client_task);
  Scheduler.start(&train);
  Scheduler.begin();
}

void loop() {
  //Nothing :)
}
