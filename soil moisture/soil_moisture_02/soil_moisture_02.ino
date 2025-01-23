#define AOUT_PIN 36 // ESP32 pin GPIO36 (ADC0) that connects to AOUT pin of moisture sensor

void setup() {
  Serial.begin(9600);
  // set the ADC attenuation to 11 dB (up to ~3.3V input)
  analogSetAttenuation(ADC_11db);
}

void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor
  
  // Convert the ADC value to percentage
  float percentage = (value / 4095.0) * 100.0; 
  
  Serial.print("Moisture value: ");
  Serial.println(value); // Raw ADC value
  
  Serial.print("Moisture percentage: ");
  Serial.print(percentage, 1); // Percentage with 1 decimal precision
  Serial.println(" %");

  delay(500);
}
