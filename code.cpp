#define POT_PIN A0  // Potentiometer connected to A0
#define LED_PIN 9   // LED connected to PWM pin 9

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);  // Start Serial Monitor
}

void loop() {
  int potValue = analogRead(POT_PIN);  // Read potentiometer (0-1023)
  float voltage = potValue * (5.0 / 1024.0);  // Convert to voltage (0-5V)
  int brightness = map(potValue, 0, 1024, 0, 255);  // Map to PWM range (0-255)
  
  analogWrite(LED_PIN, brightness);  // Adjust LED brightness

  Serial.print("Potentiometer: ");
  Serial.print(voltage);  // Print voltage with 2 decimal places
  Serial.print("V | Brightness: ");
  Serial.println(brightness);

  delay(100);
}
