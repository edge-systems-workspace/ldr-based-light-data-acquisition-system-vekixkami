#include <Arduino.h>   // Include core Arduino library for basic functions

// Define LDR analog pin (Use A0)
#define LDR_PIN A0      // LDR sensor connected to analog pin A0

// Create variable to store sensor reading
int ldrValue;           // Stores raw analog value from LDR (0–1023)

void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Print system initialization message to Serial Monitor
    Serial.println("LDR Light Intensity Monitoring System Initialized");
}

void loop() {

    // Read analog value from LDR
    // Value ranges from 0 (dark) to 1023 (bright light)
    ldrValue = analogRead(LDR_PIN);

    // Print raw ADC value to Serial Monitor
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);

    // Apply threshold logic to detect brightness level
    // Threshold (500) can be adjusted based on calibration
    if (ldrValue > 500) {   
        Serial.println("Bright Environment");   // High light intensity detected
    } else {
        Serial.println("Dark Environment");     // Low light intensity detected
    }

    // Add delay (500ms) for stable readings and readable output
    delay(500);
}
