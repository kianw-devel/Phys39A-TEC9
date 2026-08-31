const int analogPin = A0;
const float Vref = 5.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int count = analogRead(analogPin);
  float voltage = count * Vref / 1023.0;

  Serial.print(count);
  Serial.print(",");
  Serial.println(voltage, 4);

  delay(100);
}