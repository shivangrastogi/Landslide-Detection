const int vib = 8;
const int BUZZ = 11;
int sensorPin = A0;
int sensorValue;
int limit = 500;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZ, OUTPUT);
  pinMode(vib, INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  int vibrationState = digitalRead(vib);

  Serial.print("Moisture Value: ");
  Serial.println(sensorValue);
  Serial.print("Vibration Status: ");
  Serial.println(vibrationState);

  if (sensorValue < limit || vibrationState == 1) {
    Serial.println("!!! DANGER !!!");
    tone(BUZZ, 2000);
    delay(2000);
  } else {
    Serial.println("SAFE");
    noTone(BUZZ);
  }
  delay(1000);
}
