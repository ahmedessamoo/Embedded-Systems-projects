/*
 * fan_controller.c
 *
 *  Created on: May 29, 2022
 *      Author: SHAMY
 */


#include <avr/io.h>
#include "adc.h"
#include "dcmotor.h"
#include "lcd.h"
#include "lm35.h"




int main(void)
{

	uint8 temp ;
	ADC_ConfigType ADC_Configurations = {INTERNAL_VOLT,F_CPU_8};

	SREG  |= (1<<7);

	DcMotor_init();
	LCD_init();

	ADC_init(&ADC_Configurations);




	LCD_displayStringRowColumn(0,0,"fan is ");
	LCD_displayStringRowColumn(1,0,"temp =        c");

	ADC_init(&ADC_Configurations);
	while(1)
	{
		temp = LM35_getTemperature();


		if(temp < 30 )
		{

		}
		else if(temp >= 30 && temp < 60)
		{
			DcMotor_Rotate(DC_MOTOR_CW,25);
			LCD_moveCursor(0,7);
			LCD_displayString("ON");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temp);

		}
		else if (temp >= 60 && temp < 90)
		{
			DcMotor_Rotate(DC_MOTOR_CW,50);
			LCD_moveCursor(0,7);
			LCD_displayString("ON");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temp);

		}
		else if (temp >= 90 && temp < 120)
		{
			DcMotor_Rotate(DC_MOTOR_CW,75);
			LCD_moveCursor(0,7);
			LCD_displayString("ON");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temp);

		}
		else if (temp >= 120 )
		{
			DcMotor_Rotate(DC_MOTOR_CW,100);
			LCD_moveCursor(0,7);
			LCD_displayString("ON");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temp);

		}
	}







	return 0 ;
}
