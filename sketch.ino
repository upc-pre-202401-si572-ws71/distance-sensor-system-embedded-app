/*
 * vehicle-distance-sensor-system
 *
 * Embedded Application that monitors a set of 4
 * ultrasonic distance sensors showing read values
 * on an lcd actuator
 *
 * https://wokwi.com/projects/398060024831689729
 */

#include "DisplayActuator.h"
#include "DistanceSensor.h"

// Define Assigned Trigger Pins
#define FL_TRIGGER_PIN 10
#define FR_TRIGGER_PIN 11
#define RL_TRIGGER_PIN 12
#define RR_TRIGGER_PIN 13

// Define Assigned Echo Pins
#define FL_ECHO_PIN 4
#define FR_ECHO_PIN 5
#define RL_ECHO_PIN 6
#define RR_ECHO_PIN 7

DisplayActuator displayActuator;
DistanceSensor flDistanceSensor(FL_TRIGGER_PIN, FL_ECHO_PIN);
DistanceSensor frDistanceSensor(FR_TRIGGER_PIN, FR_ECHO_PIN);
DistanceSensor rlDistanceSensor(RL_TRIGGER_PIN, RL_ECHO_PIN);
DistanceSensor rrDistanceSensor(RR_TRIGGER_PIN, RR_ECHO_PIN);

void setup() {
  // Initialize Display
  displayActuator.init();
}

void loop() {
  // Update Data Visualization
  updateDashboard();
}

void updateDashboard() {
  displayActuator.setCursor(0,0);
  displayActuator.printText("L=");
  displayActuator.printDistance(flDistanceSensor.readMetricSystemDistance());
  displayActuator.setCursor(9,0);
  displayActuator.printText("R=");
  displayActuator.printDistance(frDistanceSensor.readMetricSystemDistance());
  displayActuator.setCursor(0,1);
  displayActuator.printText("L=");
  displayActuator.printDistance(rlDistanceSensor.readMetricSystemDistance());
  displayActuator.setCursor(9,1);
  displayActuator.printText("R=");
  displayActuator.printDistance(rrDistanceSensor.readMetricSystemDistance());
}
