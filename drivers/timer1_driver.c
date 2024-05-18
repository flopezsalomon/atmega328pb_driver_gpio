/*
* timer1.c
*
* Created: 08-05-2021 23:49:11
* Author: Fernando Lopez Salomon
*/
#include "timer1_driver.h"

// static local prototypes
static void timer1_driver_set_timer_mode(uint8_t mode);
static void timer1_driver_set_prescaler(uint16_t prescaler);
static void timer1_driver_set_compare_value(uint16_t prescaler , uint8_t period);
static void timer1_driver_set_interruption_mode(uint8_t mode);

// local variables
static volatile uint32_t tick;
static volatile uint8_t  timer_flag;


void timer1_driver_init(uint8_t timer_mode, uint16_t prescaler, uint8_t period, uint8_t interruption_mode)
{
	timer1_driver_set_timer_mode(timer_mode);
	timer1_driver_set_compare_value(prescaler,period);
	timer1_driver_set_interruption_mode(interruption_mode);
	timer1_driver_set_prescaler(prescaler);
}

uint32_t timer1_driver_get_tick(void)
{
	return tick;
}

void timer1_driver_reset_tick(void)
{
	tick = 0;
}

static void timer1_driver_set_timer_mode(uint8_t mode)
{
	switch(mode)
	{
		case 0:
		TCCR1B = TIMER1_MODE_CTC;
		break;
		
		case 1:
		break;
		
		default:
		break;
	}
}

static void timer1_driver_set_prescaler(uint16_t prescaler)
{
	switch(prescaler)
	{
		case _256_PRESCALER:
		TCNT1 = 0x0000;
		TCCR1B |= TIMER1_PRESCALER_256;
		break;
		
		case _1024_PRESCALER:
		break;
	}
}

static void timer1_driver_set_compare_value(uint16_t prescaler , uint8_t period)
{
	OCR1A = ((F_CPU/prescaler/period) - 1);  //Compare value
}

static void timer1_driver_set_interruption_mode(uint8_t mode)
{
	switch(mode)
	{
		case 0:
		TIMSK1 |= TIMER1_COMPARE_MATCH_A_INTERRUPT;
		break;
		
		case 1:
		break;
		
		default:
		break;
	}
}

uint8_t timer1_driver_get_timerflag(void)
{
	return timer_flag;
}

void timer1_driver_set_timerflag(uint8_t value)
{
	timer_flag = value;
}

ISR(TIMER1_COMPA_vect) {
	if(!timer_flag){
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
		{
			timer_flag = 1;
		}
	}
}