# Poltry_farm
Here’s a sample `README.md` file tailored for your smart fish feeding system project using ESP32, ultrasonic sensor, servo, and OLED display:

---

## 🐟 Smart Fish Feeder with Ultrasonic Sensor using ESP32

This project is an automatic fish feeder system built using the **ESP32**, **ultrasonic sensor**, **servo motor**, and **0.96" OLED display**. It calculates the **distance to the water surface (or food level)** using the ultrasonic sensor and **translates it into a 0–100% food level display**. The servo releases food when the button is pressed.

---

### 📷 Features

* ✅ Real-time food level display in **percentage (%)**
* ✅ **Servo motor** rotates to release food
* ✅ **Push button** for manual feeding
* ✅ **OLED display** for easy monitoring
* ✅ Simple and compact design

---

### 🔌 Pin Connections

| Component        | Pin on ESP32 |
| ---------------- | ------------ |
| Ultrasonic TRIG  | D5           |
| Ultrasonic ECHO  | D18          |
| Servo Motor      | D4           |
| Push Button      | D15          |
| OLED Display SDA | D21          |
| OLED Display SCL | D22          |

---

### 📦 Components Required

* ESP32 DevKit V1
* HC-SR04 Ultrasonic Sensor
* SG90 Servo Motor
* Push Button
* 0.96" OLED Display (SSD1306)
* Breadboard and Jumper Wires
* Resistor (e.g., 10kΩ for button pull-up)

---

### 🔧 How It Works

* The ultrasonic sensor measures the distance to the water/food level.
* The distance is mapped to a **0–100% scale** (e.g., 10 cm = 0%, 2 cm = 100%).
* The percentage is displayed on the OLED.
* When the button is pressed, the servo rotates to drop food, then returns to its original position.

---

### 🧠 Code

The code is written in Arduino and uses the following libraries:

```cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>
```

**[👉 Click to open the code](./fish_feeder_code.ino)**

---

### 🚀 Getting Started

1. Install the required libraries:

   * `Adafruit GFX Library`
   * `Adafruit SSD1306`
   * `ESP32Servo`
2. Connect the components as shown in the table.
3. Upload the code using Arduino IDE.
4. Press the button to feed the fish!

---

### 📝 Notes

* The food level calculation assumes **10 cm = empty** and **2 cm = full**. You can adjust the logic as needed.
* Servo angle and duration can be tweaked in the code (`servo.write(...)` and `delay(...)`).

---


