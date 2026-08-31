
const int analogPin = A0;
const float Vref = 5.0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  // 100 sequential unaveraged voltage values
  for (int i = 0; i < 100; i++) {

    int count = analogRead(analogPin);
    float voltage = count * Vref / 1023.0;
    Serial.print("Unaveraged:");
    Serial.println(voltage, 4);
  }

  // 100 averaged voltage values
  for (int i = 0; i < 100; i++) {

    float totalVolt = 0;

    // Take 1000 measurements for each averaged value
    for (int j = 0; j < 1000; j++) {

      int count = analogRead(analogPin);
      float voltage = count * Vref / 1023.0;

      totalVolt += voltage;
    }

    float voltAve = totalVolt / 1000.0;
    Serial.print("Averaged:");
    Serial.println(voltAve, 4);
  }
}