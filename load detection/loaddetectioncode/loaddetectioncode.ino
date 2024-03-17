//include all necessary libraries needed
#include <HX711.h>

// Load cell pins
const int LOAD_CELL_DOUT_PIN = 12;
const int LOAD_CELL_CLK_PIN = 11;

// HX711 object
HX711 loadCell(LOAD_CELL_DOUT_PIN, LOAD_CELL_CLK_PIN);

// Calibration factor
const float CALIBRATION_FACTOR = 1.0;

// Motor pins
const int MOTOR_PIN = 2;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Initialize the load cell
  loadCell.begin();

  // Set the calibration factor
  loadCell.set_scale(CALIBRATION_FACTOR);

  // Tare the load cell
  loadCell.tare();

  // Initialize the motor pin as output
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  // Read the load cell value
  float load = loadCell.get_units();

  // Check if the load is over the maximum limit
  if (load > MAX_LOAD) {
    // Stop the motor
    digitalWrite(MOTOR_PIN, LOW);

    // Print a message to the serial monitor
    Serial.println("Overload detected. Stopping motor.");
  } else {
    // Start the motor
    digitalWrite(MOTOR_PIN, HIGH);
  }

  // Wait for a short period of time before taking the next reading
  delay(100);
}