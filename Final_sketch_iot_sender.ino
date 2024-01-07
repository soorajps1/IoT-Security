#include <ESP8266WiFi.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

const char* ssid = "Sooraj's Ideapad";
const char* password = "12345678";
const char* apiKey = "LO6QE2MGK0Y6TIVP";

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  float temperature = temp.temperature; // Read temperature from MPU6050

  String binaryRepresentation = decTo8BitBinary(static_cast<int>(temperature));
  String grayCode = binaryToGrayCode(binaryRepresentation);
  Serial.print("Sensor read temperature: ");
  Serial.println(temperature);
  Serial.print("Binary of temperature: ");
  Serial.println(binaryRepresentation);
  Serial.print("Gray Code of corresponding binary: ");
  Serial.println(grayCode);

  // Send Gray code to ThingSpeak
  sendToThingSpeak(grayCode);

  delay(5000);
}

// Function to convert decimal to 8-bit binary representation
String decTo8BitBinary(int val) {
  String binary = "";

  for (int i = 7; i >= 0; --i) {
    binary += (val & (1 << i)) ? '1' : '0';
  }

  return binary;
}

// Function to convert binary to Gray code
String binaryToGrayCode(String binary) {
  String grayCode = "";
  grayCode += binary[0];

  for (int i = 1; i < binary.length(); ++i) {
    grayCode += (binary[i - 1] != binary[i]) ? '1' : '0';
  }

  return grayCode;
}

// Function to send data to ThingSpeak
void sendToThingSpeak(String data) {
  WiFiClient client;

  if (client.connect("api.thingspeak.com", 80)) {
    String url = "/update?api_key=" + String(apiKey) + "&field1=" + data;
    client.println("GET " + url + " HTTP/1.1");
    client.println("Host: api.thingspeak.com");
    client.println("Connection: close");
    client.println();
    delay(500); // Allow time for response
    client.stop();
  } else {
    Serial.println("Failed to connect to ThingSpeak");
  }
}
