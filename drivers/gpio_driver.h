/**
* @file gpio_driver.h
* @brief Header file for GPIO driver functions.
*
* This file provides the declarations of functions and data types used for GPIO operations.
*/

#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <avr/io.h>

/**
* @enum state_t
* @brief Defines possible states of a GPIO pin.
*/
typedef enum state {
	LOW  = 0,
	HIGH = 1,
	ZERO = 0,
	ONE  = 1,
	OFF  = 0,
	ON   = 1
} state_t;

/**
* @enum direction_t
* @brief Defines direction modes for GPIO pins.
*/
typedef enum direction{
	INPUT        = 0,
	OUTPUT       = 1,
	INPUT_PULLUP = 2
}direction_t;

/**
* @struct port_t
* @brief Represents a GPIO port configuration.
*
* This structure holds information about the GPIO port configuration including the port address, pin number,
* direction, and offset for operations.
*/
typedef struct
{
	volatile uint8_t *port;
	uint8_t pin;
	direction_t direction;
	uint8_t offset;
}port_t;

void gpio_init_pin(port_t *port , volatile uint8_t *base_port , uint8_t pin, direction_t direction, uint8_t offset);

void gpio_write_pin(port_t *port, state_t state );

void gpio_config_pin(port_t *port);

uint8_t gpio_read_pin(port_t *port);

void gpio_toogle(port_t *port);


#endif  //GPIO_DRIVER_H