const int potPin = A1;
const int directionPin = 11;

const int heatPin = 9;
const int coolPin = 10;

const int numSamples = 1000;


void setup() {

  Serial.begin(9600);

  pinMode(directionPin, INPUT);

  pinMode(heatPin, OUTPUT);
  pinMode(coolPin, OUTPUT);

}


void loop() {

  // Add together 1000 trim-pot ADC readings
  float totalADC = 0;

  for (int i = 0; i < numSamples; i++) {

    int count = analogRead(potPin);

    totalADC += count;

  }

  // Find average ADC value
  float averageADC = totalADC / numSamples;


  // Map ADC range 0-1023 to PWM range 0-255
  int pwmValue = map((int)averageADC, 0, 1023, 0, 255);


  // Read heat/cool direction from pin 11
  int direction = digitalRead(directionPin);


  if (direction == HIGH) {

    // Heat
    analogWrite(heatPin, pwmValue);
    analogWrite(coolPin, 0);

  }

  else {

    // Cool
    analogWrite(heatPin, 0);
    analogWrite(coolPin, pwmValue);

  }


  // Print values to Serial Monitor
  Serial.print("average ADC = ");
  Serial.print(averageADC, 1);

  Serial.print("    PWM = ");
  Serial.print(pwmValue);

  Serial.print("    direction = ");

  if (direction == HIGH) {

    Serial.println("heat");

  }

  else {

    Serial.println("cool");

  }

}