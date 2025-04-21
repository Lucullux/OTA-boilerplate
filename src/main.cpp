#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "OTA.h"

// Wi-Fi credentials
const char* ssid = "USER";
const char* password = "PASS";

// OTA settings
const char* ota_hostname = "esp8266-ota";
const char* ota_password = "your_secure_password";

void setup() {
    Serial.begin(115200);
    delay(100);

    // Connect to Wi-Fi
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("Connecting to Wi-Fi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.print("Connected! IP address: ");
    Serial.println(WiFi.localIP());

    // Start OTA
    setupOTA(ota_hostname, ota_password);
}

void loop() {
    handleOTA();  // Keep OTA alive
}
