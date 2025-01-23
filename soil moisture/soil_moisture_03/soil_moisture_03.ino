#define AOUT_PIN 36 // ESP32 pin GPIO36 (ADC0) that connects to AOUT pin of moisture sensor

void setup() {
  Serial.begin(9600);
  // set the ADC attenuation to 11 dB (up to ~3.3V input)
  analogSetAttenuation(ADC_11db);
}

void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor

  // Map the value from 0-4095 to 1-10
  int scaledValue = map(value, 0, 4095, 1, 10);

  Serial.print("Moisture value (1-10): ");
  Serial.println(scaledValue); // print the scaled value
  
  delay(500);
}
