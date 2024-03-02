// Include the library for LM35 temperature sensor
#include <Bounce2.h>

// Define the analog pin for LM35 sensor
const int sensorPin = A0;

// Define the pin for the onboard LED
const int ledPin = 13;

// Variables for tracking temperature and LED blinking
float tempC = 0;

// Debounce parameters for the LED state change
Bounce debouncer = Bounce();

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the LED pin as output
  pinMode(ledPin, OUTPUT);

  // Set up debouncer with a 50 ms interval
  debouncer.attach(ledPin);
  debouncer.interval(50);
}

void loop() {
  // Read the analog value from the LM35 sensor
  int sensorValue = analogRead(sensorPin);

  // Convert the analog value to temperature in Celsius
  tempC = (sensorValue * 5.0 / 1024.0) * 100.0;

  // Print the temperature value to the serial monitor
  Serial.print("Temperature (C): ");
  Serial.println(tempC);

  // Control the LED blink based on temperature
  if (tempC < 30) {
    // If the temperature is below 30°C, toggle the LED with debounce
    if (debouncer.update() && debouncer.read() == HIGH) {
      digitalWrite(ledPin, !digitalRead(ledPin));
    }
  } else {
    // If the temperature is 30°C or higher, toggle the LED with debounce
    if (debouncer.update() && debouncer.read() == HIGH) {
      digitalWrite(ledPin, !digitalRead(ledPin));
    }
  }
}
