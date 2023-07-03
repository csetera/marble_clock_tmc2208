#include "SimpleStepper.h"

void SimpleStepper::init() {
    pinMode(_enablePin, OUTPUT);
    pinMode(_directionPin, OUTPUT);
    pinMode(_stepPin, OUTPUT);

    digitalWrite(_directionPin, Direction::CW);
    digitalWrite(_stepPin, LOW);

    setEnabled(true);
}

void SimpleStepper::setDirection(Direction direction) {
    digitalWrite(_directionPin, direction);
}

void SimpleStepper::setEnabled(bool enabled) {
    digitalWrite(_enablePin, enabled ? LOW : HIGH);
}

void SimpleStepper::step() {
    digitalWrite(_stepPin, HIGH);
    delayMicroseconds(PULSE_WIDTH_MICROS);
    digitalWrite(_stepPin, LOW);
}