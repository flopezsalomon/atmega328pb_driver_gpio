/*
* timer1_driver.h
*
* Created: 08-05-2021 23:49:38
*  Author: fernando
*/

#ifndef TIMER1_DRIVER_H_
#define TIMER1_DRIVER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include "hardware.h"

#define F_CPU 16000000UL

void timer1_driver_init(uint8_t timer_mode, uint16_t prescaler, uint8_t period, uint8_t interruption_mode);
void timer1_driver_set_timerflag(uint8_t value);
void timer1_driver_reset_tick(void);
uint8_t timer1_driver_get_timerflag(void);
uint32_t timer1_driver_get_tick(void);

#endif /* TIMER1_DRIVER_H_ */