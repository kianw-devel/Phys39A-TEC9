const int analogPin = A0;
const int numSamples = 100;

void setup() {
  Serial.begin(9600);
}

void loop() {

  float time1 = millis();
  // Add together 100 raw ADC readings
  float totalADC = 0;

  for (int i = 0; i < numSamples; i++) {
    int count = analogRead(analogPin);
    totalADC += count;
  }

  float time2 = millis();

  float time_s = (time2 - time1) / 10.0;

  // Calculate average ADC value
  float averageADC = totalADC / 100.0;

  // Convert average ADC value to voltage
  float voltage = averageADC * 5.0 / 1023.0;

  // Calculate thermistor resistance in kOhm
  float resistance = 100.0 * voltage / (5.0 - voltage);

  // Calculate temperature in Kelvin
  // resistance is in kOhm, so R0 = 100 kOhm
  float temperature_K = 1.0 / ((1.0 / 298.15) + (1.0 / 4540.0) * log(resistance / 100.0));

  // Convert Kelvin to Celsius
  float temperature_C = temperature_K - 273.15;


  // Print everything in one human-readable line
  Serial.print("time = ");
  Serial.print(time_s, 2);
  Serial.print(" s    ");

  Serial.print("average ADC = ");
  Serial.print(averageADC, 1);
  Serial.print(" counts    ");

  Serial.print("voltage = ");
  Serial.print(voltage, 3);
  Serial.print(" V    ");

  Serial.print("resistance = ");
  Serial.print(resistance, 2);
  Serial.print(" kOhm    ");

  Serial.print("temperature = ");
  Serial.print(temperature_C, 1);
  Serial.print(" C    ");

  Serial.print("samples = ");
  Serial.println(numSamples);
}
