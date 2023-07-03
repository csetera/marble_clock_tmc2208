#pragma once

#include <Arduino.h>
#include <stdint.h>

/**
 * @brief Direction control enumeration.
 */
enum Direction {
    CCW = LOW,
    CW = HIGH
};

/**
 * @brief A simple wrapper around GPIO required
 * to manage the TMC2208 stepper driver.
 */
class SimpleStepper {
    static const long PULSE_WIDTH_MICROS = 1;

public:
    /**
     * @brief Construct a new Simple Stepper object
     *
     * @param enablePin
     * @param directionPin
     * @param stepPin
     */
    SimpleStepper(uint8_t enablePin, uint8_t directionPin, uint8_t stepPin): _enablePin(enablePin), _directionPin(directionPin), _stepPin(stepPin) {}

    /**
     * @brief Initialize the simple stepper.  Sets the configured pins to OUTPUT mode.
     */
    void init();

    /**
     * @brief Set the Direction of the stepper for the forthcoming steps.
     *
     * @param direction
     */
    void setDirection(Direction direction);

    /**
     * @brief Enable or disable the stepper motor.
     *
     * @param enabled
     */
    void setEnabled(bool enabled);

    /**
     * @brief Execute a single step.
     *
     */
    void step();

private:
    uint8_t _enablePin;
    uint8_t _directionPin;
    uint8_t _stepPin;
};
