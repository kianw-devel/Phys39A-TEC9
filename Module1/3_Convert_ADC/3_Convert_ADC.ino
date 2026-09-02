const int analogPin = A0;
const float Vref = 5.0;
float volt_total = 0;
float mean;
float voltage;
float s;
float sum;
float s1;
float s1000;

//declaring array for St.Dev.
float unav_values[100];
float ave_values[100];


void setup() {
  Serial.begin(9600);
}

void loop() {

  // 100 sequential unaveraged voltage values
  for (int i = 0; i < 100; i++) {

    int count = analogRead(analogPin);
    voltage = count * Vref / 1023.0;
    unav_values[i] = voltage;
    volt_total += voltage;
    Serial.print("Unaveraged:");
    Serial.println(voltage, 4);
  }
  mean = volt_total/100;
  Serial.print("Mean_Unaveraged:");
  Serial.println(mean, 4);
  


  //calculating standard deviation for the unaveraged values
  for(int i = 0; i < 100; i++){
    sum += pow((unav_values[i] - mean),2);
  }
  s = sqrt((1.0/99.0)*sum);
  s1 = s;
  Serial.print("Unaveraged-standard-dev:");
  Serial.println(s, 4);

  sum = 0;
  s=0;


  //set these to zero for next run through
  volt_total = 0;
  mean = 0;


  // 100 averaged voltage values
  for (int i = 0; i < 100; i++) {

    float totalVolt = 0;

    // Take 1000 measurements for each averaged value
    for (int j = 0; j < 1000; j++) {

      int count = analogRead(analogPin);
      voltage = count * Vref / 1023.0;

      totalVolt += voltage;

    }
    float voltAve = totalVolt / 1000.0;
    volt_total += voltAve;
    ave_values[i] = voltAve;

    Serial.print("Averaged:");
    Serial.println(voltAve, 4);
  }
  
  //calculating standard deviation for the averaged values

  mean = volt_total/100;


  Serial.print("Mean_Averaged:");
  Serial.println(mean, 4);

  sum = 0;

  for(int i = 0; i < 100; i++){
    sum += pow((ave_values[i] - mean),2);
  }
  s = sqrt((1.0/99.0)*sum);
  s1000 = s;

  Serial.print("Averaged-standard-dev:");
  Serial.println(s, 4);

  sum = 0;
  s = 0;
  volt_total = 0;
  mean = 0;

  float measured_ratio = s1000 / s1;
  float predicted_ratio = 1.0 / sqrt(1000.0);

  Serial.print("Measured-ratio:");
  Serial.println(measured_ratio, 4);

  Serial.print("Predicted-ratio:");
  Serial.println(predicted_ratio, 4);
}