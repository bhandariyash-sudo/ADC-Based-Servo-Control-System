/*
 * 
 * FileName: servo.c
 * Version: 1
 *
 * Created: 3/25/2025 12:01:46 PM
 * Author: Yash Bhandari
 * 
 *
 * Operations:
 *   Implements initialization and control functions for a servo motor
 *   using Timer3 on the ATmega2560. The servo is driven by a 50Hz PWM
 *   signal on OC3B (PORTE.4), where pulse width (1–2 ms) determines
 *   angular position from 0°–180°.
 */

/* NOTE: Includes */
#include "servo.h"

/* NOTE: Function implementations */

// initializes Timer3 for 50Hz PWM servo control on OC3B (PORTE.4)
void initServo(void)
{
    // set non-inverting Fast PWM mode (WGM3[3:0] = 1110)
    TCCR3A = (1 << COM3B1) | (1 << WGM31);

    // select Fast PWM mode with ICR3 as TOP, prescaler = 8
    TCCR3B = (1 << WGM33) | (1 << WGM32) | (1 << CS31);

    // set TOP value for 50Hz frequency (20ms period)
    // formula: TOP = (16MHz / (8 * 50Hz)) - 1 = 39,999
    ICR3 = 39999;

    // set initial neutral position (1.5ms pulse width)
    OCR3B = 3000;
}

// converts a degree value (0°–180°) to a PWM pulse width (1–2ms)
void servo_deg(uint8_t deg)
{
    // map degree to pulse width using linear interpolation
    OCR3B = (4200 / 180) * deg + 1000;
}
