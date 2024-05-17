#include <Arduino.h>
#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int assignedTriggerPin, int assignedEchoPin) {
  _triggerPin = assignedTriggerPin;
  _echoPin = assignedEchoPin;
}

long DistanceSensor::readUltrasonicDistance() {
  // Setup Trigger Pin
  pinMode(_triggerPin, OUTPUT);
  // Clear Trigger Pin
  digitalWrite(_triggerPin, LOW);
  // Wait
  delayMicroseconds(2);
  // Activate Trigger Pin during 10 microseconds
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(10);
  // Deactivate Trigger Pin
  digitalWrite(_triggerPin, LOW);
  // Setup Echo Pin
  pinMode(_echoPin, INPUT);
  // Return Pulse value
  return pulseIn(_echoPin, HIGH); 
}

float DistanceSensor::readMetricSystemDistance() {
  // Convert Ultrasonic Pulse Reading into Centimeters 
  return readUltrasonicDistance()/58;
}