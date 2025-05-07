#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32";
const char* password = "12345678";

WebServer server(80);

const int light = 2;

void powerLight() {
  if (server.hasArg("light")) {
    String lightState = server.arg("light");
    
    if (lightState == "on") {
      digitalWrite(light, HIGH);
      server.send(200, "text/plain", "Light was turned ON!");
      Serial.println("Light was turned ON!");
    } else if (lightState == "off") {
      digitalWrite(light, LOW);
      server.send(200, "text/plain", "Light was turned OFF!");
      Serial.println("Light was turned OFF!");
    }
  } else {
    server.send(400, "text/plain", "Something wrong happend :(");
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(light, OUTPUT);

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP Address is ");
  Serial.println(IP);

  server.on("/lightState", HTTP_GET, powerLight);
  server.begin();
  Serial.println("HTTP Server Started!");
}

void loop() {
  server.handleClient();
}
