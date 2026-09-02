const int analogPin = A0;
const int ledPin = 9;
const float Vref = 5.0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  float totalCount = 0;

  // Average 1000 ADC readings
  for (int i = 0; i < 1000; i++) {
    int count = analogRead(analogPin);
    totalCount += count;
  }

  // Averaged ADC number
  float averageCount = totalCount / 1000.0;

  // Convert ADC number to voltage
  float voltage = averageCount * Vref / 1023.0;

  // Convert 0-1023 ADC range to 0-255 PWM range
  int pwmValue = averageCount * 255.0 / 1023.0;

  // Send PWM signal to pin 9
  analogWrite(ledPin, pwmValue);

  // Print values so we can see what's happening
  Serial.print("Average Voltage: ");
  Serial.print(voltage, 4);

  Serial.print(" V    PWM: ");
  Serial.println(pwmValue);

  delay(100);
}