/*
 * FileName: servo.h
 * Version: 1
 *
 * Created: 3/25/2025 12:01:58 PM
 * Author: Yash Bhandari
 *
 * Operations: header for servo motor control submodule
 */

#ifndef servo_h_INCLUDED
#define servo_h_INCLUDED

#if defined(__cplusplus)
extern "C" {
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

/* NOTE: Function prototypes */
// initializes Timer3 for PWM control of servo on OC3B (PORTE.4)
void initServo(void);
// sets servo position based on input angle in degrees (0–180)
void servo_deg(uint8_t deg);

#if defined(__cplusplus)
} /* extern "C" */
#endif

#endif // servo_h_INCLUDED
