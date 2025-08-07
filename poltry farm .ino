#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void drawBar(int x, int y, int percent) {
  int barWidth = map(percent, 0, 100, 0, 60);
  display.drawRect(x, y, 60, 8, SSD1306_WHITE);
  display.fillRect(x, y, barWidth, 8, SSD1306_WHITE);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  int foodLevel = 75;   // Simulated
  int waterLevel = 50;  // Simulated

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("🍽 FOOD  ");
  drawBar(64, 0, foodLevel);
  display.setCursor(100, 0);
  display.print(foodLevel);
  display.print("%");

  display.setCursor(0, 14);
  display.print("💧 WATER ");
  drawBar(64, 14, waterLevel);
  display.setCursor(100, 14);
  display.print(waterLevel);
  display.print("%");

  display.setCursor(0, 32);
  display.print("🌡 TEMP    ");
  display.print(temp, 1);
  display.print(" C");

  display.setCursor(0, 48);
  display.print("💨 HUMIDITY ");
  display.print(hum, 1);
  display.print(" %");

  display.display();
  delay(2000);
}
