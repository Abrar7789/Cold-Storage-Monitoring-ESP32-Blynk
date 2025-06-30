// ==== BLYNK IoT DEFINES (must be first) ====
#define BLYNK_TEMPLATE_ID "TMPL3iwW28ish"
#define BLYNK_TEMPLATE_NAME "my project"
#define BLYNK_AUTH_TOKEN "2C0tsJr_LqbKjkM2w3cjtmFBMA_zUnx8"

// ==== Includes ====
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// ==== Wi-Fi credentials ====
char ssid[] = "cold storage";
char pass[] = "123456789";

// ==== Pin Definitions ====
#define DHTPIN 4
#define DHTTYPE DHT11
#define GAS_SENSOR_PIN 34
#define LDR_PIN 27
#define RELAY_PIN 26
#define BUZZER_PIN 25

// ==== Thresholds ====
#define TEMP_THRESHOLD 50
#define GAS_THRESHOLD 500

// ==== Objects ====
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Use 0x27 or 0x3F depending on your LCD module

void setup() {
  Serial.begin(115200);

  // Initialize LCD
  lcd.begin();
  lcd.backlight();

  // Start DHT sensor
  dht.begin();

  // Set pin modes
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  digitalWrite(RELAY_PIN, HIGH);   // Relay OFF
  digitalWrite(BUZZER_PIN, LOW);   // Buzzer OFF

  // Connect to WiFi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // LCD Welcome Message
  lcd.setCursor(0, 0);
  lcd.print(" Cold Storage ");
  lcd.setCursor(0, 1);
  lcd.print("   Monitoring   ");
  delay(2000);
  lcd.clear();
}

void loop() {
  Blynk.run();

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int gasValue = analogRead(GAS_SENSOR_PIN);
  int ldrState = digitalRead(LDR_PIN); // LOW = dark, HIGH = light

  // Display on Serial Monitor
  Serial.print("Temp: "); Serial.print(temperature);
  Serial.print("  Hum: "); Serial.print(humidity);
  Serial.print("  Gas: "); Serial.print(gasValue);
  Serial.print("  LDR: "); Serial.println(ldrState == LOW ? "open" : "close");

  // Update LCD
  lcd.setCursor(0, 0);
  lcd.print("T:"); lcd.print(temperature, 1); lcd.print("C ");
  lcd.print("H:"); lcd.print(humidity, 0); lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("G:"); lcd.print(gasValue);
  lcd.print(" L:"); lcd.print(ldrState == LOW ? "open " : "close");

  // Alert conditions
  bool alert = (temperature > TEMP_THRESHOLD) || (gasValue > GAS_THRESHOLD) || (ldrState == LOW);

  digitalWrite(RELAY_PIN, alert ? LOW : HIGH);   // Relay ON if alert
  digitalWrite(BUZZER_PIN, alert ? HIGH : LOW);  // Buzzer ON if alert

  // Send to Blynk
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, gasValue);
  Blynk.virtualWrite(V3, alert ? 1 : 0); // Relay status
  Blynk.virtualWrite(V4, ldrState == LOW ? 1 : 0); // LDR status

  delay(2000);
}
