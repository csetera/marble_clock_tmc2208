#include <Arduino.h>
#include "SimpleStepper.h"

/*
https://fabacademy.org/2022/labs/kannai/Instruction/tips/stepper_TMC2208/

RMS Current = MAX CURRENT / 1.41
VREF = ((RMS Current x 2.5) / 1.77)

RMS Current = 0.3 / 1.41 = 0.212765957
VREF = (0.212765957 x 2.5) / 1.77) = 0.531914894 / 1.77 = 0.300516889
*/
#define EN_PIN 4
#define DIR_PIN 8
#define STEP_PIN 7

#define MICROSTEPS 4
#define STEPS_PER_REVOLUTION (200 * MICROSTEPS)
#define STEPS_PER_MINUTE STEPS_PER_REVOLUTION

const unsigned long millisPerMinute = (unsigned long) 60 * (unsigned long) 1000;
const unsigned long stepDeltaMillis = millisPerMinute / STEPS_PER_MINUTE;

unsigned long nextStep = 0;
SimpleStepper stepper(EN_PIN, DIR_PIN, STEP_PIN);

/**
 * @brief Standard Arduino setup routine.  Called once.
 */
void setup() {
  Serial.begin(9600);
  stepper.init();
  stepper.setEnabled(true);
}

/**
 * @brief Standard Arduino method called repeatedly
 */
void loop() {
 unsigned long now = millis();
 if (now >= nextStep) {
  unsigned long deltaMillis = now - nextStep;
  nextStep = nextStep + stepDeltaMillis - deltaMillis;
  stepper.step();
 }
}