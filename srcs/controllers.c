/**
 * @authors Camilo Arteaga, Simon Sanchez, Camilo Alvarez
 * @file controllers.c
 * @brief Functions for GiBo controllers
 */

#include "include/controllers.h"

/**
 * @brief Debounces a GPIO pin.
 *
 * This function initializes the GPIO pin, sets it as an input, and debounces the input.
 * It uses a time-based approach for debouncing.
 *
 * @param gpio_pin The GPIO pin number to debounce.
 * @return Debounced state of the GPIO pin.
 */
int debounce_gpio(uint gpio_pin) {
    gpio_init(gpio_pin);
    gpio_set_dir(gpio_pin, GPIO_IN);

    /// Variables for debouncing
    uint32_t last_state = gpio_get(gpio_pin);
    absolute_time_t last_time = get_absolute_time();

    while (1) {
        /// Read the current state of the GPIO pin
        uint32_t current_state = gpio_get(gpio_pin);

        /// Check if the state has changed
        if (current_state != last_state) {
            // Update the last state and time
            last_state = current_state;
            last_time = get_absolute_time();
        }

        /// Check if the debounce delay has passed
        if (absolute_time_diff_us(last_time, get_absolute_time()) >= DEBOUNCE_DELAY_US) {
            return current_state; // Debounced state
        }

        tight_loop_contents();
    }
}

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
char read_directions(uint gpio_pins[], size_t num_pins) {
    char result = 0;
    char button = 0;

    /// Initialize the GPIO subsystem
    stdio_init_all();

    for (size_t i = 0; i < num_pins; ++i) {
        int debounced_state = debounce_gpio(gpio_pins[i]);

        /// Update the result based on the debounced state
        if (debounced_state) {
            result |= (1 << i);
        }
    }

    /// Decode the result and print
    for (size_t i = 0; i < num_pins; ++i) {
        if (result & (1 << i)) {
            printf("Direction from GPIO %u: ", gpio_pins[i]);

            switch (i) {
                case 0:
                    printf("U\n");
                    button = 'U';
                    break;
                case 1:
                    printf("D\n");
                    button = 'D';
                    break;
                case 2:
                    printf("R\n");
                    button = 'R';
                    break;
                case 3:
                    printf("L\n");
                    button = 'L';
                    break;
                case 4:
                    printf("X\n");
                    button = 'X';
                    break;
                case 5:
                    printf("Y\n");
                    button = 'Y';
                    break;
                default:
                    printf("Unknown\n");
            }
        }
    }
    return button;
}
