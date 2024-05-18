/*
* atmega328pb_driver_gpio.c
*
* Created: 16-05-2024 20:48:56
* Author : Fernando Lopez Salomon
* Description: This file is intended to handle GPIO operations and task scheduling on the ATmega328PB.
*/

// Check if the CPU clock frequency is defined, otherwise define it and issue a warning
#ifndef F_CPU
#define F_CPU 16000000UL
#warning "F_CPU not defined! Assuming 16MHz."
#endif

#include "gpio_driver.h"
#include "hardware.h"
#include "application.h"
#include "task.h"
#include "timer1_driver.h"
#include <avr/io.h>
#include <stdio.h>

// Define the tick rate for the timer
const unsigned long timer_tick_rate  = 100;

// Array to store tasks
task_t tasks[NUMBER_OF_TASK];

// Structure to handle status LED operations
port_t status_led;

// Structure to handle user button
port_t user_button;

// Function declarations for tasks
void task_0(void);
void task_1(void);
void task_2(void);

int main(void)
{
	
	cli(); // Disable global interrupts
	
	gpio_init_pin(&status_led,PORT_STATUS_LED, STATUS_LED, OUTPUT, OFFSET_PORT_LED); // Initialize status LED pin
	gpio_config_pin(&status_led);
	gpio_write_pin(&status_led, LOW); // Set status LED to LOW initially
	
	gpio_init_pin(&user_button,PORT_USER_BUTTON, USER_BUTTON, INPUT, OFFSET_PORT_USER_BUTTON);
	gpio_config_pin(&user_button);
	
	timer1_driver_set_timerflag(1);
	timer1_driver_init(0,_256_PRESCALER,_100_MS_,0);  // Initialize timer1 with specific settings
	
	task_init(&tasks[0],400,0,&task_0,UNBLOCKED);
	task_init(&tasks[1],200,0,&task_1,UNBLOCKED);
	task_init(&tasks[2],500,0,&task_2,BLOCKED);
	
	sei(); // enable global interruptions
	
	while (1)
	{
		for (uint8_t i=0; i < NUMBER_OF_TASK; i++) {
			if (tasks[i].elapsedTime >= tasks[i].ticks && tasks[i].state) {
				tasks[i].fct();
				tasks[i].elapsedTime = 0;
			}
			tasks[i].elapsedTime += timer_tick_rate; // Increment task elapsed time
		}
		timer1_driver_set_timerflag(0);
		while(!timer1_driver_get_timerflag());	// Wait for the timer flag to be set
	}
}


void task_0(void)
{
	static uint8_t counter = 0;
	static uint8_t state   = 0;			// in this case zero means blocked
	if(!gpio_read_pin(&user_button)){	// user button is connected to ground
		counter++;
		if(counter>=2){
			counter = 0;
			state = !state;
			task_change_state(&tasks[1], state);
			gpio_write_pin(&status_led, LOW);
		}
	}
	else{
		counter = 0;
	}
}

void task_1(void)
{
	gpio_toogle(&status_led);  // Toggle the status LED
}

void task_2(void)
{
	// Add here Task 3 function content
}

