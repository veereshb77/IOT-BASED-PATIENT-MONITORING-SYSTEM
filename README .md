# IOT-BASED-PATIENT-MONITORING-SYSTEM
The Internet of Things technology has led to the development of various innovative solutions for healthcare. In this article, we will explore the creation of a Health Monitoring System using the Blynk App, ESP32 Board, MAX30100 Sensor, DHT11 Sensor, and DS18B20 Sensor.
Now we demonstrate how to build an IoT-based patient health monitoring system using the ESP32 microcontroller and the Blynk app. This project is designed to continuously monitor vital health parameters like heart rate, body temperature, and oxygen levels. The data is sent to the Blynk app in real time, allowing remote monitoring from anywhere.

# Circuit Components
| Sensor        | Measured Parameter | Purpose                     |
|---------------|--------------------|-----------------------------|
| DHT11         | Temperature         | Monitor body/environment temp |
| MAX30100      | Heart rate, SpO2    | Track pulse and oxygen level  |
| ESP32         | -                   | Microcontroller with Wi-Fi    |

# ESP32 Board
## ⚙️ ESP32 Board Overview
![image](https://github.com/user-attachments/assets/30c9d287-6760-44ec-ade0-7e9d1b026533)

The **ESP32** is a popular microcontroller board based on the **ESP32 SoC** developed by **Espressif Systems**. It is widely used in IoT and embedded applications due to its powerful features and wireless connectivity.

### 🔑 Key Features

- **Microcontroller**: 32-bit Xtensa® LX6 dual-core processor  
- **Clock Speed**: Up to 240 MHz  
- **Wireless Connectivity**: Built-in Wi-Fi and Bluetooth  
- **Multitasking**: Dual-core architecture supports parallel processing  
- **Ideal for**: Real-time applications, IoT systems, remote monitoring, and automation
  
# 🩺 IoT-Based Patient Monitoring System

A real-time IoT system built using **ESP32**, capable of measuring vital health parameters such as **heart rate**, **SpO₂**, **body temperature**, **ambient temperature**, and **humidity**. The data is displayed live on the **Blynk mobile app**, making it suitable for remote patient monitoring and health tracking.

---

## 🔧 Hardware Components

| Component   | Description                                  |
|------------|----------------------------------------------|
| **ESP32**  | Wi-Fi + Bluetooth-enabled microcontroller     |
| **MAX30100** | Pulse oximeter for Heart Rate and SpO₂      |
| **DHT11**  | Temperature and humidity sensor               |
| **DS18B20** | Digital body temperature sensor              |
| **Blynk App** | Mobile dashboard for real-time monitoring  |

---

## ⚙️ ESP32 Board Features

- **CPU**: Xtensa 32-bit LX6 Dual-core (160–240 MHz)  
- **RAM**: 520 KB SRAM  
- **Wi-Fi**: 802.11 b/g/n/e/i  
- **Bluetooth**: v4.2 BR/EDR and BLE  
- **Sensors**: 10 capacitive touch sensors, Hall sensor  
- **ADC**: 12-bit SAR ADC (up to 18 channels)  
- **PWM**: LED PWM (up to 16 channels)  
- **Power Efficiency**: Ultra-Low Power (ULP) co-processor  

---

## 📦 Sensor Descriptions

### MAX30100 - Pulse Oximeter & Heart Rate Sensor
![image](https://github.com/user-attachments/assets/54c6cb2d-c2ee-4921-be5e-bd4bc799ac85)

- Measures: Heart Rate & Blood Oxygen Saturation (SpO₂)  
- Communication: I2C  
- Features:  
  - Integrated red and IR LEDs  
  - Adjustable LED current and sampling rates  
  - Digital output via I2C  
- Principle: Differentiates between oxygenated and deoxygenated blood by measuring light absorption.

### DHT11 - Temperature & Humidity Sensor
![image](https://github.com/user-attachments/assets/2e1af66b-49c0-4a99-bc41-42c05b5a46d4)

- Measures: Ambient Temperature and Humidity  
- Temperature Range: 0–50°C (±2°C)  
- Humidity Range: 20–90% RH (±5%)  
- Communication: Digital signal

### DS18B20 - Waterproof Digital Thermometer
![image](https://github.com/user-attachments/assets/6d2fc580-cb74-44d3-888c-85a99150893c)

- Measures: Body Temperature  
- Temperature Range: -55°C to +125°C  
- Resolution: 9–12 bit  
- Communication: 1-Wire Protocol

---

## 🧪 Circuit Connections
![image](https://github.com/user-attachments/assets/284c0b3f-17ff-4c79-97b7-9c67fb37bfae)

### MAX30100
VCC → 3.3V
GND → GND
SDA → GPIO 21
SCL → GPIO 22

### DHT11
VCC → 3.3V
GND → GND
DATA → GPIO 18

### DS18B20

VCC → 3.3V
GND → GND
DATA → GPIO 5


---

## 📱 Blynk App Setup

1. **Download the Blynk App** from Google Play or App Store  
2. **Create a New Project**  
   - Device: ESP32  
   - Connection: Wi-Fi  
3. **Get Auth Token** sent via email  
4. **Add Widgets**  
   - Virtual Pin V3 → Temperature  
   - Virtual Pin V4 → Humidity  
   - Virtual Pin V5 → Heart Rate  
   - Virtual Pin V6 → SpO₂  
   - Virtual Pin V7 → Body Temperature  
5. **Insert Auth Token** in your Arduino code:  
   ```cpp
   char auth[] = "YourAuthTokenHere";

  
## 📚 Libraries Required

This project uses the following Arduino libraries. Please install them via the Arduino Library Manager or download from their official repositories:

| Library Name         | Description                          | Installation Method                     |
|----------------------|------------------------------------|---------------------------------------|
| **Blynk**            | Connects ESP32 with Blynk app      | Arduino Library Manager or [GitHub](https://github.com/blynkkk/blynk-library) |
| **DHT sensor library** | For DHT11/DHT22 temperature & humidity sensors | Arduino Library Manager or [GitHub](https://github.com/adafruit/DHT-sensor-library) |
| **OneWire**          | For 1-wire communication protocol  | Arduino Library Manager or [GitHub](https://github.com/PaulStoffregen/OneWire) |
| **DallasTemperature**| For DS18B20 temperature sensor     | Arduino Library Manager or [GitHub](https://github.com/milesburton/Arduino-Temperature-Control-Library) |
| **MAX30105**         | For MAX30105 pulse oximeter sensor | Arduino Library Manager or [GitHub](https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library) |

### How to install libraries via Arduino IDE:

1. Open Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries**.
3. Search for the library name.
4. Click **Install** on the matching result.

Make sure you install all required libraries before compiling the code.


## 🌟 Project Impact

This **IoT-Based Patient Monitoring System** empowers continuous, real-time health monitoring outside clinical settings, enhancing patient care by enabling early detection of abnormalities such as irregular heart rate or low oxygen levels. It reduces the need for frequent hospital visits, lowering healthcare costs and easing the burden on medical facilities. By leveraging affordable sensors and wireless connectivity, this system makes remote health monitoring accessible to underserved communities and improves overall health outcomes through timely intervention and data-driven decisions.





