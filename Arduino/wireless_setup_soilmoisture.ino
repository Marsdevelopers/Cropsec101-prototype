#include <WiFi.h>
#include <HTTPClient.h>

#define ledPin 6
#define sensorPin A0

const char* ssid = "your_ssid"; // Replace with your WiFi SSID
const char* password = "your_password"; // Replace with your WiFi password
const char* server_url = "http://your_local_server_ip/moisture"; // Replace with your server URL

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected to WiFi with IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int moisture = readSensor();
  Serial.print("Moisture: ");
  Serial.println(moisture);

  // Create HTTP client
  HTTPClient http;

  // Specify content type header
  http.begin(server_url, HTTP_POST);
  http.addHeader("Content-Type", "application/json");

  // Prepare data to send
  String jsonData = "{\"moisture\": " + String(moisture) + "}";

  // Send HTTP POST request
  int httpCode = http.POST(jsonData);

  if (httpCode != HTTP_CODE_OK) {
    Serial.printf("HTTP POST failed with error %d\n", httpCode);
  } else {
    Serial.println("HTTP POST success");
  }

  http.end();

  delay(500);
}

int readSensor() {
  int sensorValue = analogRead(sensorPin);
  int outputValue = map(sensorValue, 0, 1023, 255, 0);
  analogWrite(ledPin, outputValue);
  return outputValue;
}
```



