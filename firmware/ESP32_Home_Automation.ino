#include <WiFi.h>
#include <WebServer.h>

// Smart Home Wi-Fi access point
const char* ssid = "AmansHOME";
const char* password = "Aman@123";

// Relay connections
const int RELAY1 = 26;
const int RELAY2 = 27;

// Most relay modules are active LOW.
// Change to false if your relay is active HIGH.
const bool RELAY_ACTIVE_LOW = true;

WebServer server(80);

void setRelay(int pin, bool turnOn) {
  if (RELAY_ACTIVE_LOW) {
    digitalWrite(pin, turnOn ? LOW : HIGH);
  } else {
    digitalWrite(pin, turnOn ? HIGH : LOW);
  }
}

void handleRoot() {
  server.send(200, "text/plain",
              "ESP32 Smart Home Automation is running.");
}

void handleBulb1On() {
  setRelay(RELAY1, true);
  server.send(200, "text/plain", "Bulb 1 ON");
}

void handleBulb1Off() {
  setRelay(RELAY1, false);
  server.send(200, "text/plain", "Bulb 1 OFF");
}

void handleBulb2On() {
  setRelay(RELAY2, true);
  server.send(200, "text/plain", "Bulb 2 ON");
}

void handleBulb2Off() {
  setRelay(RELAY2, false);
  server.send(200, "text/plain", "Bulb 2 OFF");
}

void setup() {
  Serial.begin(115200);

  // Initialize relays in the OFF state
  digitalWrite(RELAY1, RELAY_ACTIVE_LOW ? HIGH : LOW);
  digitalWrite(RELAY2, RELAY_ACTIVE_LOW ? HIGH : LOW);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  WiFi.mode(WIFI_AP);

  if (!WiFi.softAP(ssid, password)) {
    Serial.println("Wi-Fi access point failed!");
    return;
  }

  Serial.println("Smart Home Automation Started");
  Serial.print("Wi-Fi: ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", HTTP_GET, handleRoot);

  server.on("/bulb1/on", HTTP_GET, handleBulb1On);
  server.on("/bulb1/off", HTTP_GET, handleBulb1Off);

  server.on("/bulb2/on", HTTP_GET, handleBulb2On);
  server.on("/bulb2/off", HTTP_GET, handleBulb2Off);

  server.onNotFound([]() {
    server.send(404, "text/plain", "Unknown command");
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
