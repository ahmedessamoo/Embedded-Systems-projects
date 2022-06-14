/*
 * pwm_driver.c
 *
 *  Created on: May 29, 2022
 *      Author: SHAMY
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "gpio.h"
#include "pwm.h"





void PWM_Timer0_Start(uint8 duty_cycle)
{
	 TCNT0 = 0;
	 OCR0  = ((float)duty_cycle / 100) * 255;
	 TCCR0 = (1<<WGM00) |(1<<WGM01) | (1<<COM01)| (1<<CS01);

	 GPIO_setupPinDirection(PORTB_ID , PIN3_ID, PIN_OUTPUT);



}
