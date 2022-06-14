/*
 * buzzer.c
 *
 *  Created on: Jun 10, 2022
 *      Author: SHAMY
 */




#include "buzzer.h"


void buzzer_init(void)
{
	// Buzzer pin 3 at PORTD is output

	GPIO_setupPinDirection(buzzer_port ,buzzer_pin, PIN_OUTPUT);
	 buzzer_Off();// buzzer off at begining



}

void buzzer_on(void)
{
	// Buzzer on by set its PIN
	GPIO_writePin(buzzer_port, buzzer_pin, LOGIC_HIGH);
}

void buzzer_Off(void)
{
	// Buzzer on by clear its PIN
	GPIO_writePin(buzzer_port, buzzer_pin, LOGIC_LOW);
}
