/*
 * 
 * FileName: ADC.c
 * Version: 1
 *
 * Created: 3/25/2025 12:02:12 PM
 * Author: Yash Bhandari
 * 
 *
 * Operations:
 *   Initializes and configures the ADC module to continuously read
 *   analog input from channel 1 (PORTF.1). The ADC operates in 8-bit
 *   left-adjusted mode, and the conversion results are stored in the
 *   global variable `adc_value` through an interrupt service routine.
 */

/* NOTE: Includes */
#include "ADC.h"

/* NOTE: Function implementations */

// initializes ADC and I/O ports for continuous 8-bit conversions on ADC1
void IO_init(void)
{
    // configure PORT E as output (for debugging or control signals)
    DDRE = 0xFF;
    PORTE = 0x00;

    // configure PORT F as input (ADC pins)
    DDRF = 0x00;
    PORTF = DDRF;  // disable pull-ups

    // configure PORT A as output for LED bar display
    DDRA = 0xFF;
    PORTA = 0xFF;

    // enable ADC and set prescaler to 128 (125 kHz ADC clock)
    ADCSRA = (1 << ADEN);
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

    // select AVcc as voltage reference and left-adjust result for 8-bit mode
    ADMUX = (1 << REFS0) | (1 << ADLAR);

    // select ADC channel 1 (PORTF.1)
    ADMUX = (ADMUX & 0xE0) | 1;

    // enable ADC interrupt and start first conversion
    ADCSRA |= (1 << ADIE) | (1 << ADSC);
}

// handles ADC conversion complete interrupt and updates adc_value
ISR(ADC_vect)
{
    // read the 8-bit result from ADCH register
    adc_value = ADCH;

    // reselect ADC1 and start the next conversion
    ADMUX = (ADMUX & 0xE0) | 1;
    ADCSRA |= (1 << ADSC);
}
