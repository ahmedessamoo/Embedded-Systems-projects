/*
 * dcmotor_driver.c
 *
 *  Created on: May 29, 2022
 *      Author: SHAMY
 */



#include <avr/io.h>
#include "gpio.h"
#include "dcmotor.h"
#include "pwm.h"




	/* Motor is stop at the beginning */



	void DcMotor_init(void)
	{
		GPIO_setupPinDirection(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,PIN_OUTPUT);
		GPIO_setupPinDirection(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,PIN_OUTPUT);


		GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);

	}


	void DcMotor_Rotate(DcMotor_State state , uint8 speed)
	{

		if(state == DC_MOTOR_CW)
		{
			/* Rotates the Motor CW */
			GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
			GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_HIGH);

			PWM_Timer0_Start(speed);
		}
		else if(state == DC_MOTOR_ACW)
		{
			/* Rotates the Motor A-CW */
			GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_HIGH);
			GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);

			PWM_Timer0_Start(speed);
		}
		else if(state == DC_MOTOR_STOP)
		{
			/* Stop the Motor */
			GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
			GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);

			PWM_Timer0_Start(speed);
		}
		else
		{
			//
		}


    }
