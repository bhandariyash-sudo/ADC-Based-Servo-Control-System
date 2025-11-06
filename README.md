ADC-Based-Servo-Control-System
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
This project demonstrates how an ATmega2560 microcontroller can read an analog voltage using the ADC (Analog-to-Digital Converter) and use that data to control a servo motor through PWM (Pulse Width Modulation). The servo position changes in real time based on the potentiometer input, while an LED bar displays the corresponding 8-bit ADC value.

What It Does
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Continuously reads analog input from a potentiometer (0–5 V)

Converts the analog voltage to an 8-bit digital value (0–255)

Maps the ADC value to a servo rotation angle from 0° to 180°

Generates a PWM signal on OC3B (PORTE.4) using Timer3

Displays the live ADC value on PORTA LEDs as a visual indicator

Hardware Used
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ATmega2560 microcontroller

Potentiometer – provides analog voltage input

Servo motor – rotates based on PWM signal

LED bar (PORTA) – displays ADC values

Power supply (5 V) – powers the microcontroller and servo

Skills Practiced
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Configuring and reading from the ADC module

Generating PWM signals using Timer3 in Fast PWM mode

Mapping analog input ranges to servo output angles

Using interrupt service routines for real-time updates

Writing modular C code across header and implementation files

