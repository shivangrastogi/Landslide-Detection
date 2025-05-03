#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(9, 5); // RX, TX

void setup() {
  gsmSerial.begin(9600); // GSM Module
  Serial.begin(9600);    // Serial Monitor
  delay(1000);
  Serial.println("Preparing to send SMS");
  sendMessage();
}

void loop() {
}

void sendMessage() {
  Serial.println("Setting GSM in text mode");
  gsmSerial.println("AT+CMGF=1"); // Set SMS to text mode
  delay(2000);

  Serial.println("Sending SMS to the desired phone number!");
  gsmSerial.println("AT+CMGS=\"+xxxxxxxxxxx\""); // Replace with phone number
  delay(2000);

  gsmSerial.println("Hello from SIM900 - Landslide Detector Alert!"); // SMS content
  delay(200);

  gsmSerial.write(26); // ASCII code of CTRL+Z to send
  delay(2000);
}
