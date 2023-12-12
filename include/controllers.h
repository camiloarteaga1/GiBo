#ifndef _CONTROLLERS_H
#define _CONTROLLERS_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define DEBOUNCE_DELAY_US 10000 /// Adjust debounce delay as needed

/**
 * @brief Debounces a GPIO pin.
 *
 * This function initializes the GPIO pin, sets it as an input, and debounces the input.
 * It uses a time-based approach for debouncing.
 *
 * @param gpio_pin The GPIO pin number to debounce.
 * @return Debounced state of the GPIO pin.
 */
int debounce_gpio(uint gpio_pin);

/**
 * @brief Reads directions from multiple GPIO pins and returns a character.
 *
 * This function initializes the GPIO subsystem, reads inputs from multiple GPIO pins,
 * and returns a character based on the detected direction.
 *
 * @param gpio_pins An array of GPIO pin numbers.
 * @param num_pins The number of GPIO pins in the array.
 * @return A character representing the detected direction ('U' (up), 'D' (down), 'R' (right), 'L' (left), 'X' (interact), 'Y' (pause), or 'Unknown').
 */
char read_directions(uint gpio_pins[], size_t num_pins);

#endif