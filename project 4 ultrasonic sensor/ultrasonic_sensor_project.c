/*
 * ultrasonic_sensor_project.c
 *
 *  Created on: Jun 3, 2022
 *      Author: SHAMY
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "icu.h"
#include "lcd.h"
#include "ultrasonic.h"
#include "gpio.h"



uint16 result;


extern  timer_counts;

extern timer_value  ;

extern total_distance ;


int main(void)
{

	SREG |= (1<<7);


	 LCD_init();
	 Ultrasonic_init();
	 LCD_displayString("distance = ");







	 while(1)
	 {

		 result =  ultrasonic_readdistance() ;
		 LCD_moveCursor(0,11);
		 LCD_intgerToString(result);
		 LCD_displayString("cm");
		 Ultrasonic_init();


	 }








}
