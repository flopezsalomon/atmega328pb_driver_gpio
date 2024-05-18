/**
* @file gpio_driver.c
* @brief Implementation of GPIO driver functions.
*
* This file provides the implementation of functions declared in gpio_driver.h for GPIO operations.
*/

#include "gpio_driver.h"

/**
* @brief Initializes a GPIO pin.
* @param port Pointer to the port_t structure containing GPIO configuration.
* @param base_port Base address of the GPIO port.
* @param pin GPIO pin number.
* @param direction Configuration direction of GPIO pin.
* @param offset Offset used for bit manipulation.
*/
void gpio_init_pin(port_t *port , volatile uint8_t *base_port , uint8_t pin, direction_t direction,uint8_t offset)
{
	port->pin       = pin;
	port->port      = base_port;
	port->direction = direction;
	port->offset    = offset;
}

/**
* @brief Writes a state to a GPIO pin.
* @param port Pointer to the port_t structure containing GPIO configuration.
* @param state State to write to the GPIO pin.
*/
void gpio_write_pin(port_t *port, state_t state )
{
	switch(state)
	{
		case HIGH:
		*(port->port + (port->offset)) |= (1<<port->pin);
		break;
		
		case LOW:
		*(port->port + (port->offset)) &= ~(1<<port->pin);
		break;
		
		default:
		break;
	}
}

/**
* @brief Reads the current state of a GPIO pin.
* @param port Pointer to the port_t structure containing GPIO configuration.
* @return uint8_t The current state of the GPIO pin, extracted and normalized to a single bit value.
* This function reads the value from the hardware port address accounting for the pin offset and returns
* the result, shifted to the least significant bit position.
*/
uint8_t gpio_read_pin(port_t *port)
{
	return ((*(port->port-(port->offset)) & (1<<port->pin))>>port->pin);
}

/**
* @brief Configures a GPIO pin.
* @param port Pointer to the port_t structure containing GPIO configuration.
* Details how the GPIO pin should be configured based on its intended direction,
* supporting OUTPUT, INPUT, and INPUT_PULLUP modes.
*/
void gpio_config_pin(port_t *port) // TODO: check function name ...
{
	switch(port->direction)
	{
		case OUTPUT:
		*(port->port)  |= (1<<port->pin);
		break;
		
		case INPUT:
		*(port->port) &= ~(1<<port->pin);
		break;
		
		case INPUT_PULLUP:
		break;
	}
}

/**
* @brief Toggles the state of a GPIO pin.
* @param port Pointer to the port_t structure containing GPIO configuration.
* This function changes the current state of the pin to the opposite state (i.e., HIGH to LOW or LOW to HIGH).
*/
void gpio_toogle(port_t *port)
{
	*(port->port + (port->offset)) ^= (1<<port->pin);
}
