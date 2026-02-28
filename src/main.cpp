#include <Arduino.h>

// Define LDR analog pin (Use A0)
#define LDR_PIN A0

// Create variable to store sensor reading
int ldrValue;

void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Print system initialization message
    Serial.println("LDR Light Intensity Monitoring System Initialized");
}

void loop() {

    // Read analog value from LDR
    ldrValue = analogRead(LDR_PIN);

    // Print raw ADC value
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);

    // Apply threshold logic (Bright / Dark detection)
    if (ldrValue > 500) {   // Adjust threshold based on calibration
        Serial.println("Bright Environment");
    } else {
        Serial.println("Dark Environment");
    }

    // Add delay (500ms)
    delay(500);
}
