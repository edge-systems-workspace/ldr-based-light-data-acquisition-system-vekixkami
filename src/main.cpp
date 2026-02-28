#include <Arduino.h>

/**
 * @file main.ino
 * @brief Embedded Light Intensity Monitoring using LDR
 * @author Vedansh
 * @date 2026-02-28
 *
 * @details
 * This program reads analog brightness data from an LDR (Light Dependent Resistor)
 * connected to analog pin A0. The sensor outputs varying voltage based on light
 * intensity, which is converted into a digital value (0–1023) by the ADC.
 * A simple threshold logic is applied to classify the environment as
 * either Bright or Dark, and the results are displayed on the Serial Monitor.
 */

// Define LDR analog pin (Use A0)
#define LDR_PIN A0   ///< Analog pin connected to LDR sensor output

// Variable to store sensor reading
int ldrValue;        ///< Stores raw ADC value from LDR (0–1023)

/**
 * @brief Initializes serial communication and prints system message.
 *
 * This function runs once when the Arduino starts.
 * It sets up Serial communication to display light intensity readings.
 */
void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Print system initialization message
    Serial.println("LDR Light Intensity Monitoring System Initialized");
}

/**
 * @brief Continuously reads LDR value and determines brightness level.
 *
 * The loop reads analog data from the LDR sensor, prints the raw ADC value,
 * and applies a threshold-based logic to classify the environment as
 * bright or dark. A small delay ensures stable readings and readable output.
 */
void loop() {

    // Read analog value from LDR
    // Range: 0 (dark) to 1023 (very bright)
    ldrValue = analogRead(LDR_PIN);

    // Print raw ADC value to Serial Monitor
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);

    // Apply threshold logic (Bright / Dark detection)
    // Threshold value can be calibrated based on lighting conditions
    if (ldrValue > 500) {
        Serial.println("Bright Environment");  ///< High light intensity detected
    } else {
        Serial.println("Dark Environment");    ///< Low light intensity detected
    }

    // Add delay (500ms) for stable readings and readability
    delay(500);
}
