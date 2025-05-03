const int vibrationSignal = 8;
const int BUZZ = 11;

void setup() {
  Serial.begin(9600);
  pinMode(vibrationSignal, INPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  int sensorState = digitalRead(vibrationSignal);
  Serial.println("Vibration Status:");

  if (sensorState == 1) {
    Serial.println("Sensing Vibration - !!! DANGER !!!");
    tone(BUZZ, 2000);
    delay(2000);
  } else {
    Serial.println("No Vibration - SAFE");
    noTone(BUZZ);
  }
  delay(1000);
}
