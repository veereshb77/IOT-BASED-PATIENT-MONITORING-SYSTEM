
#define BLYNK_TEMPLATE_ID "TMPL3LP3d23jn"
#define BLYNK_TEMPLATE_NAME "smarthealthcare"
#define BLYNK_AUTH_TOKEN "ieRcfytunDzLeLQ2sMlXQvKR0d24s75-"

#include <Wire.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "DHT.h"
#include "MAX30105.h"  // Correct library for MAX30105

#define DHTTYPE DHT22
#define REPORTING_PERIOD_MS 1000
#define DS18B20 5
#define DHTPin 18

char auth[] = "ieRcfytunDzLeLQ2sMlXQvKR0d24s75-";
char ssid[] = "Xyz";
char pass[] = "123456789";

MAX30105 particleSensor;
DHT dht(DHTPin, DHTTYPE);
OneWire oneWire(DS18B20);
DallasTemperature sensors(&oneWire);
BlynkTimer timer;  // Optimized periodic updates

float Temperature, Humidity, bodytemperature, BPM, SpO2, body;

// Function to process MAX30105 sensor data
void readMAX30105() {
  long irValue = particleSensor.getIR();

  if (irValue < 50000) {  // If no finger is detected
    BPM = 0;
    SpO2 = 0;
  } else {
    BPM = irValue / 1000.0;  // Dummy value (real processing requires an algorithm)
    SpO2 = 98.0;             // Placeholder value
  }
}

// Function to send sensor data
void sendSensorData() {
  readMAX30105(); // Read heart rate and SpO2

  Temperature = dht.readTemperature();
  Humidity = dht.readHumidity();
  sensors.requestTemperatures();
  body = sensors.getTempCByIndex(0);
  bodytemperature = (body * 9 / 5) + 32;

  Serial.print("Heart rate: ");
  Serial.print(BPM);
  Serial.print(" bpm / SpO2: ");
  Serial.print(SpO2);
  Serial.println(" %");

  Serial.print("Room Temperature: ");
  Serial.print(Temperature);
  Serial.println("°C");

  Serial.print("Room Humidity: ");
  Serial.print(Humidity);
  Serial.println("%");

  Serial.print("Body Temperature: ");
  Serial.print(bodytemperature);
  Serial.println(" F");

  Blynk.virtualWrite(V3, Temperature);
  Blynk.virtualWrite(V8, Humidity);
  Blynk.virtualWrite(V2, BPM);
  Blynk.virtualWrite(V6, SpO2);
  Blynk.virtualWrite(V9, bodytemperature);
}

void setup() {
  Serial.begin(115200);
  pinMode(DHTPin, INPUT);
  dht.begin();
  sensors.begin();
  Blynk.begin(auth, ssid, pass);

  Serial.print("Initializing MAX30105 sensor...");
  if (!particleSensor.begin()) {
    Serial.println("FAILED");
    while (1);
  } else {
    Serial.println("SUCCESS");
    particleSensor.setup(); // Configure LED power
  }

  timer.setInterval(REPORTING_PERIOD_MS, sendSensorData);  // Set periodic data sending
}

void loop() {
  Blynk.run();
  timer.run();
}
