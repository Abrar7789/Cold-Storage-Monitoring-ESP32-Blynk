# Cold Storage Monitoring System using ESP32 and Blynk

This project is a smart IoT-based Cold Storage Monitoring System using the ESP32 microcontroller. It collects real-time data from multiple sensors and enables automatic control and remote monitoring through the Blynk mobile application.

---

## 🔧 Features

- Real-time monitoring of *temperature, **humidity, **gas leakage, and **ambient light*
- Automatic *fan control* via relay to maintain safe temperature
- *Buzzer alert* system on unsafe conditions
- *LCD Display* for local feedback
- *Blynk App* integration for mobile-based remote monitoring

---

## 🧰 Hardware Components

| Component       | Description |
|----------------|-------------|
| ESP32 Dev Board | Main microcontroller with Wi-Fi |
| DHT11 Sensor    | Measures temperature & humidity |
| MQ135 Sensor    | Detects harmful gas levels |
| LDR             | Detects light for door monitoring |
| Relay Module    | Controls external fan |
| Buzzer          | Audio alert for critical values |
| LCD (I2C 16x2)  | Displays sensor readings |
| Power Supply    | 12V adapter with buck converter |

---

## 📁 Folder Structure

Cold-Storage-Monitoring-ESP32-Blynk/ │ ├── code/              # Arduino source code (.ino file) ├── docs/              # documentation index (.doc) documentation (.docx) ├── images/            # Block diagram, circuit, Blynk screenshots ├── LICENSE            # GNU GPL v3 license ├── .gitignore         # Git ignored files └── README.md          # This file

## 🖥 How It Works

1. ESP32 reads sensor values from DHT11 (Temp/Humidity), MQ135 (Gas), and LDR (Light)
2. If values cross thresholds, ESP32 triggers:
   - *Buzzer* for alert
   - *Relay* to activate fan
   - *Data update* to Blynk via Wi-Fi
3. User monitors data on:
   - *LCD screen*
   - *Blynk mobile app* (with real-time values and alerts)

---

## 📲 Blynk App Integration

- Blynk is used to visualize and monitor all sensor data
- Mobile notifications can be configured for emergency triggers
- Easy to use and configure with ESP32 and mobile Wi-Fi

---

## 📸 Output Screenshots

![Block Diagram](images/blockdiagram.png)
![Circuit Diagram](images/ckt.png)
![Blynk UI](images/monitoring_results.jpg)
![LCD Reading](images/Hardware_output.jpg)

---

## 🚀 Getting Started

### Requirements:
- Arduino IDE
- ESP32 board support installed
- Blynk library

### Steps:
1. Clone or download this repository
2. Open Cold_Storage.ino in Arduino IDE
3. Add your Blynk Auth Token and Wi-Fi credentials
4. Upload code to ESP32
5. Monitor values on LCD and Blynk app

---

## 👥 Team Members

- *Shaik Abrar Ali*
- *k.Nanditha*
- *ch.Abhilash*

---

## 📄 License

This project is licensed under the *GNU General Public License v3.0 (GPLv3)*  
See the [LICENSE](LICENSE) file for details.
