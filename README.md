# Landslide Detector Model

This project combines soil moisture sensors, vibration sensors, buzzers, GSM modules, and a PHP backend to detect potential landslides and log environmental data.

## 📂 Folder Structure

- `arduino/` → Arduino `.ino` codes:
  - `combined_sensor_alert.ino` → Checks both vibration + soil moisture.
  - `soil_only_alert.ino` → Checks only soil moisture.
  - `vibration_only_alert.ino` → Checks only vibration.
  - `gsm_send_sms.ino` → Sends SMS alerts using GSM module.
  
- `php/` → PHP script for logging DHT11 data:
  - `dht11_data_logger.php`

## 🛠 Hardware Components

- Arduino Uno
- Soil moisture sensor (A0)
- Vibration sensor (pin 8)
- Buzzer (pin 11)
- GSM module (SIM900)
- DHT11 temperature/humidity sensor

## 💾 Database Setup

- Create a MySQL database (e.g., `landslide_db`).
- Create a table (e.g., `dht11_data`) with:
  ```sql
  CREATE TABLE dht11_data (
    id INT AUTO_INCREMENT PRIMARY KEY,
    humidity VARCHAR(10),
    temperature VARCHAR(10),
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP
  );
