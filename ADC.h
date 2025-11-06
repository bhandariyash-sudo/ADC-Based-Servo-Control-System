/*
 * FileName: ADC.h
 * Version: 1
 *
 * Created: 3/25/2025 12:02:26 PM
 * Author: Yash Bhandari
 *
 * Operations: header for ADC initialization and configuration
 */

#ifndef ADC_h_INCLUDED
#define ADC_h_INCLUDED

#if defined(__cplusplus)
extern "C" {
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

/* NOTE: Global Variables */
// stores the most recent 8-bit ADC conversion result
extern volatile uint8_t adc_value;

/* NOTE: Function prototypes */
// initializes ADC and related I/O ports
void IO_init(void);

#if defined(__cplusplus)
} /* extern "C" */
#endif

#endif // ADC_h_INCLUDED
