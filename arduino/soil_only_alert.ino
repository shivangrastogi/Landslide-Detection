const int sensorPin = A0;
int sensorValue;
int limit = 500;
const int BUZZ = 11;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("Soil Moisture Value: ");
  Serial.println(sensorValue);

  if (sensorValue < limit) {
    Serial.println("!!! DANGER !!!");
    tone(BUZZ, 2000);
    delay(2000);
  } else {
    Serial.println("SAFE");
    noTone(BUZZ);
  }
  delay(1000);
}
