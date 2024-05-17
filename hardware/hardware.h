#ifndef HARDWARE_H
#define HARDWARE_H

#include <avr/io.h>

#define EXTERNAL_CLOCK 16000000UL // Defining the CPU Frequency

// GPIO register ports

#define PORT_B &DDRB 
#define PORT_D &DDRD
#define PORT_C &DDRC

// All GPIO pin 

#define PIN_0 (0)
#define PIN_1 (1)
#define PIN_2 (2)
#define PIN_3 (3)
#define PIN_4 (4)
#define PIN_5 (5)
#define PIN_6 (6)
#define PIN_7 (7)

// Define here others 
#define OFFSET (0x01)

// USART register config
#define B9600	9600
#define B19200	19200
#define B38400	38400
#define B115200 115200
//#define USART_BAUDRATE B38400 // Desired Baud Rate
#define USART_BAUDRATE B9600 
#define USART_BAUDRATE2 B115200

#define BAUD_PRESCALER (((EXTERNAL_CLOCK / (USART_BAUDRATE * 16UL))) - 1)

#define BAUD_PRESCALER2 (((EXTERNAL_CLOCK / (USART_BAUDRATE2 * 16UL))))

#define ASYNCHRONOUS	(0<<UMSEL00)	// USART Mode Selection
#define NONE			(0<<UPM00)		// USART Parity Bit Selection
#define EVEN_PARITY		(2<<UPM00)
#define ODD_PARITY		(3<<UPM00)
#define ONE_BIT			(0<<USBS0)      // Stop Bit Selection
#define TWO_BIT			(1<<USBS0)	

#define FIVE_BIT  (0<<UCSZ00)			// USART Data Bit Selection
#define SIX_BIT   (1<<UCSZ00)
#define SEVEN_BIT (2<<UCSZ00)
#define EIGHT_BIT (3<<UCSZ00)

/////////////////////////////
#define _1024_PRESCALER 1024
#define _256_PRESCALER  256
////////////////////////////////

/* ADC Channel Selection */
#define CHANNEL_0		(PINC0)
#define CHANNEL_1		(PINC1)
#define CHANNEL_2		(PINC2)
#define CHANNEL_3		(PINC3)
#define CHANNEL_4		(PINC4)
#define CHANNEL_5		(PINC5)
#define INTERNAL_TEMPERATURE_SENSOR (8)
#define GND (15)

/* ADC Clock settings */
#define PRESCALAR_2		(0x01)		// ADC_CLK = CLK/2
#define PRESCALAR_4		(0x02)		// ADC_CLK = CLK/4
#define PRESCALAR_8		(0x03)		// ADC_CLK = CLK/8
#define PRESCALAR_16	(0x04)		// ADC_CLK = CLK/16
#define PRESCALAR_32	(0x05)		// ADC_CLK = CLK/32
#define PRESCALAR_64	(0x06)		// ADC_CLK = CLK/64
#define PRESCALAR_128	(0x07)		// ADC_CLK = CLK/128

#define ADC_PRESCALER_2    (1<<ADPS0)
#define ADC_PRESCALER_4    (1<<ADPS1)
#define ADC_PRESCALER_8    (1<<ADPS1) | (1<<ADPS0)
#define ADC_PRESCALER_16   (1<<ADPS2)
#define ADC_PRESCALER_32   (1<<ADPS2) | (1<<ADPS0)
#define ADC_PRESCALER_64   (1<<ADPS2) | (1<<ADPS1)
#define ADC_PRESCALER_128  (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0)
#define ADC_PRESCALER_MASK (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0)

// output adjust
#define LEFT_OUTPUT_ADJUST  (0x00)
#define RIGHT_OUTPUT_ADJUST (0x01)

/* Reference voltage settings */
#define	AREF			  (0x00)
#define AVCC			  (0x01)
#define BAND_REF		  (0x03)

 #define ADC_VOLTAGE_REFERENCE_AREF (0<<REFS0)
 #define ADC_VOLTAGE_REFERENCE_AVCC (1<<REFS0)
 #define ADC_VOLTAGE_REFERENCE_IREF (1<<REFS1) | (1<<REFS0)
 #define ADC_VOLTAGE_REFERENCE_MASK (1<<REFS1) | (1<<REFS0)

////////////////////////////
#define WATCHDOG_PRESCALER_128K (6<<WDP0)
#define WATCHDOG_PRESCALER_64K  (5<<WDP0)
#define WATCHDOG_PRESCALER_32K  (4<<WDP0)
#define WATCHDOG_PRESCALER_16K  (3<<WDP0)
#define WATCHDOG_PRESCALER_8K   (2<<WDP0)
#define WATCHDOG_PRESCALER_4K   (1<<WDP0)


/*TIMER 0 configuration*/
#define TIMER0_MODE_CTC			(1<<WGM01)
#define TIMER0_MODE_FAST_PWM	(1<<WGM01) | (1<<WGM00)
#define TIMER0_MODE_MASK		(1<<WGM01) | (1<<WGM00)
//----------------------------------------------------------
#define TIMER0_PRESCALER_0		(0<<CS02) | (0<<CS01) | (0<<CS00)
#define TIMER0_PRESCALER_1		(1<<CS00)
#define TIMER0_PRESCALER_8		(1<<CS01)
#define TIMER0_PRESCALER_64		(1<<CS01) | (1<<CS00)
#define TIMER0_PRESCALER_256	(1<<CS02)
#define TIMER0_PRESCALER_1024   (1<<CS02) | (1<<CS00)
#define TIMER0_PRESCALER_MASK   (1<<CS02) | (1<<CS01) | (1<<CS00)
//--------------------------------------------------------
#define TIMER0_COMPARE_MATCH_A_INTERRUPT   (1<<OCIE0A)
#define TIMER0_COMPARE_MATCH_B_INTERRUPT   (1<<OCIE0B)

/*TIMER 1 configuration*/
#define TIMER1_MODE_CTC (1<<WGM12)
//-----------------------------------------------------
#define TIMER1_PRESCALER_256 (1<<CS12) 
//-----------------------------------------------------
#define TIMER1_COMPARE_MATCH_A_INTERRUPT (1<<OCIE1A);
 



#endif // HARDWARE_H