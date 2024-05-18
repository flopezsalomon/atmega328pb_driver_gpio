#ifndef APPLICATION_H
#define APPLICATION_H

#include "hardware.h"

#define NUMBER_OF_TASK (5)
#define FIRMWARE_VERSION	"1.0.0"
#define PROTOCOL_VERSION	"1.0.0"

// Add here mask for digital inputs
#define IGNITION_MASK		 (0x03)
#define DIGITAL_INPUT_0_MASK (0x00)
#define DIGITAL_INPUT_1_MASK (0x01)
#define DIGITAL_INPUT_2_MASK (0x02)

// Add here user level names for hardware
#define NAVIGATON_LED			PIN_0
#define STATUS_LED				PIN_5
#define IGNITION				PIN_4
#define DI_0					PIN_3
#define PORT_DI_0				PORT_B
#define PORT_STATUS_LED			PORT_B
#define PORT_NAVIGATION_LED		PORT_B
#define PORT_IGNITION			PORT_B
#define OFFSET_PORT_LED			OFFSET
#define OFFSET_PORT_IGNITION	OFFSET
#define OFFSET_PORT_DI			OFFSET
#define USER_BUTTON				PIN_7
#define PORT_USER_BUTTON		PORT_B
#define OFFSET_PORT_USER_BUTTON OFFSET

// user defines for USART port configuration
#define DATA_BIT	EIGHT_BIT			// USART Data Bit Selection
#define STOP_BIT	ONE_BIT				// USART Stop Bit Selection
#define PARITY_MODE NONE				// USART Parity Bit Selection
#define BAUDRATE	BAUD_PRESCALER      // Baud Rate
#define BAUDRATE2	BAUD_PRESCALER2
#define MODE		ASYNCHRONOUS
//////////////////////////////////////
#define TIMER_FRECUENCY TEN_HERTZ
#define PRESCALER _256_PRESCALER
////////////////////////////////////
#define VOLTAGE_REFERENCE AVCC
#define OUTPUT_ADJUST 1
#define FRECUENCY_DIVISOR PRESCALAR_4
#define ADC_CHANNEL CHANNEL_1

/////////////////////////////////

#define _1_SECOND_	100
#define _500_MS_	50
#define _100_MS_	10

/////////////////////////////////
#define ONE_HERTZ	1			// 1 second
#define TEN_HERTZ	10			// 0.1 second or 100 ms
#define _10_MS_		100			// 0.01 second or 10 ms
#define TWO_HERTS	2				// 500 ms
#define _100_MS_	10
///////////////////////////////////
#define F_50Hz    50UL		// Time Period 20ms
#define F_100Hz   100UL	// Time Period 10ms
#define F_200Hz   200UL	// Time Period 5ms
#define F_500Hz   500UL	// Time Period 2ms
#define F_1kHz    1000UL	// Time Period 1ms
#define F_5kHz    5000UL
#define F_10kHz   10000UL
#define F_20kHz   20000UL
#define F_40kHz   40000UL
#define F_50kHz   50000UL
#define F_100kHz  100000UL
#define F_200kHz  200000UL
#define F_500kHz  500000UL
#define F_1000kHz 1000000UL
#define F_1Mhz    1000000UL


#define IGNITION_ON  1
#define IGNITION_OFF 0
#define DEBOUNCE	 3

#define USART_OFFSET	 (0x08)
#define USART0_BASE_REG  (0xC0) // reference to pointer memory of register UCSR0
#define USART1_BASE_REG  (USART0_BASE_REG + USART_OFFSET)

#define SERVER_PARAMETERS_NUMBER	2
#define APN_PARAMETERS_NUMBER		3
#define MQTT_PARAMETERS_NUMBER		4

#define WAITING_CONNECTION_METHOD	0
#define WAITING_FOR_CONFIGURATION	1
#define WAITING_FOR_NEW_MSG			2

#define SOCKET 1
#define HTTP   2
#define MQTT   3

#define SOCKET_MASK 0x03
#define MQTT_MASK	0x07

#define SET_APN 0
#define SET_SERVER_AND_PORT 1
#define SET_MQTT_SERVER_AND_PORT 1
#define SET_MQTT_TOPIC 2

#define MCU_STATUS_REG (0x54)
#define ANSWER_OK (1)

#endif // APPLICATION_H