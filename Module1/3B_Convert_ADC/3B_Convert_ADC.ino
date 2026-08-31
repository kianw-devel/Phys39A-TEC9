const int analogPin = A0;
const float Vref = 5.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp;
  float totalVolt=0;
  int count = analogRead(analogPin);
  float voltage = count * Vref / 1023.0;
  //100 sequential unaveraged voltage values
  for (int i=0; i<100; i++) {
    count = analogRead(analogPin);
    Serial.print("Unaveraged Voltage: ");
    Serial.println(voltage, 4);
  }
  //100 averaged voltage values
  for (int i=0; i<100; i++) {
    for(int j=0; j<1000;j++){
      count = analogRead(analogPin);
      totalVolt += voltage;
    }
    Serial.print("Averaged Voltage: ");
    float voltAve = totalVolt/1000;
    Serial.println(voltAve, 4);
    totalVolt = 0;
  }
  // Serial.print(count);
  // Serial.print(",");
  // Serial.println(voltage, 4);

  delay(100);
}