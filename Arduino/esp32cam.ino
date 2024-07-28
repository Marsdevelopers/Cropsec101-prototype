#include <WiFi.h>
#include <HTTPClient.h>
#include <ESP32Camera.h>

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
const char* server_url = "http://localhost:3000/upload"; // Replace with your server endpoint

void setup() {
  Serial.begin(115200);
  camera_init(); // Initialize camera
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
  // Capture image
  camera_fb_t * fb = esp_camera_fb_alloc(FRAME_SIZE_QVGA);
  esp_err_t ret = esp_camera_fb_get(fb);
  if (ret != ESP_OK) {
    Serial.println("Error capturing image");
    esp_camera_fb_return(fb);
    return;
  }

  // Create HTTP client
  HTTPClient http;

  // Specify content type header
  http.begin(server_url, "POST");
  http.addHeader("Content-Type", "image/jpeg");

  // Send image data
  http.sendContent(fb->len, (uint8_t*)fb->buf);
  int httpCode = http.end();

  if (httpCode != HTTP_CODE_OK) {
    Serial.printf("HTTP POST failed with error %d\n", httpCode);
  } else {
    Serial.println("Image sent successfully");
  }

  esp_camera_fb_return(fb);
  delay(5000); // Adjust delay as needed
}



// Encode image as base64
std::string base64_encode(const uint8_t *data, size_t len) {
  // ... (base64 encoding implementation)
}

// ... (rest of your loop)
// ... (capture image)

std::string base64_image = base64_encode(fb->buf, fb->len);

// Send base64 encoded image as POST request
HTTPClient http;
http.begin(server_url, HTTP_POST);
http.addHeader("Content-Type", "application/json");
http.beginBody();
http.print("{\"image\": \"" + base64_image + "\"}");
http.end();

