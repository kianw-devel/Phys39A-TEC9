const int analogPin = A0;
const float Vref = 5.0;
const float fixedResistance = 100.0;   // kOhm
const float R0 = 100.0;                // kOhm at 25 C
const float T0 = 298.15;               // 25 C in Kelvin
const float beta = 4540.0;             // Kelvin
const int numSamples = 1000;


// Takes 100 ADC readings and returns their average
float averageAdcSamples() {

  float totalADC = 0;

  for (int i = 0; i < numSamples; i++) {
    int count = analogRead(analogPin);
    totalADC += count;
  }

  float averageADC = totalADC / numSamples;

  return averageADC;
}


// Converts average ADC value to voltage
float adcToVoltage(float averageADC) {

  float voltage = averageADC * Vref / 1023.0;

  return voltage;
}


// Converts voltage to thermistor resistance in kOhm
float voltageToResistance(float voltage) {

  float resistance =
      fixedResistance * voltage / (Vref - voltage);

  return resistance;
}


// Converts resistance to temperature in Celsius
float resistanceToCelsius(float resistance) {

  float temperatureK =
      1.0 / ((1.0 / T0) +
      (1.0 / beta) * log(resistance / R0));

  float temperatureC = temperatureK - 273.15;

  return temperatureC;
}


// Prints one human-readable line
void printHumanReadable(float time_s,
                        float averageADC,
                        float voltage,
                        float resistance,
                        float temperature) {

  Serial.print("time = ");
  Serial.print(time_s, 3);
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
  Serial.print(temperature, 1);
  Serial.print(" C    ");

  Serial.print("samples = ");
  Serial.println(numSamples);
}


void setup() {

  Serial.begin(9600);

  Serial.println("Thermistor Temperature Measurement");
}


void loop() {

  // Start timing this measurement
  unsigned long time1 = micros();

  // 1. Average the raw ADC readings
  float averageADC = averageAdcSamples();

  // 2. Convert average ADC to voltage
  float voltage = adcToVoltage(averageADC);

  // 3. Convert voltage to resistance
  float resistance = voltageToResistance(voltage);

  // 4. Convert resistance to temperature
  float temperature = resistanceToCelsius(resistance);

  // Stop timing this measurement
  unsigned long time2 = micros();

  // Find elapsed microseconds
  unsigned long elapsedTime = time2 - time1;

  // Convert microseconds to seconds
  float time_s = elapsedTime / 1000000.0;

  // Print results
  printHumanReadable(time_s,
                     averageADC,
                     voltage,
                     resistance,
                     temperature);
}