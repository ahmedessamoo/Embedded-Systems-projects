/*
 * DC_motor.c
 *
 *  Created on: Jun 10, 2022
 *      Author: SHAMY
 */
#include <avr/io.h>
#include "Dcmotor.h"






void Dcmotor_init(void)
{
	// PORTD PIN6 & 7 OUTPUT
	GPIO_setupPinDirection(PORTD_ID, MotorIN1, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTD_ID, MotorIN2, PIN_OUTPUT);

	Dcmotor_stop();


}



//Rotate DCmotor clockwise by write PORTD PIN6 LOGIC_LOW & PORTD PIN7 LOGIC_HIGH

void Dcmotor_Rotateclockwise(void)
{

	GPIO_writePin(PORTD_ID, MotorIN1, LOGIC_LOW);
	GPIO_writePin(PORTD_ID, MotorIN2, LOGIC_HIGH);
}


//Rotate DCmotor Anti clockwise by write PORTD PIN6 LOGIC_HIGH & PORTD PIN7 LOGIC_LOW

void Dcmotor_Rotate_Anticlockwise(void)
{

	GPIO_writePin(PORTD_ID, MotorIN1 , LOGIC_HIGH);
	GPIO_writePin(PORTD_ID, MotorIN2, LOGIC_LOW);
}

//stop DCmotor by write PORTD Both PIN 6&7  LOGIC_LOW
void Dcmotor_stop(void)
{

	GPIO_writePin(PORTD_ID, MotorIN1 , LOGIC_LOW);
	GPIO_writePin(PORTD_ID, MotorIN1, LOGIC_LOW);

}
