/*
 * ultrasonic_driver.c
 *
 *  Created on: Jun 3, 2022
 *      Author: SHAMY
 */



#include <avr/io.h>
#include "gpio.h"
#include "std_types.h"
#include "ultrasonic.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include  "icu.h"



uint8 timer_counts ;

uint16 timer_value ;

uint8 total_distance;






void Ultrasonic_init(void)
{
	Icu_ConfigType config = {F_CPU_8 , RISING } ;


	Icu_setCallBack(Ultrasonic_edgeprocessing);

	Icu_init(&config);

	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,PIN_OUTPUT);

}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_LOW);

}


uint16 ultrasonic_readdistance(void)
{



	Icu_clearTimerValue();

	Ultrasonic_Trigger();

	while(timer_counts  != ULTRASONIC_NUM_OF_DETECTED_EDGES);

	total_distance = timer_value / 58 ;
	return total_distance ;

	 timer_counts = 0 ;
	 timer_value = 0 ;
	 total_distance  = 0;




}


void Ultrasonic_edgeprocessing(void)
{
	timer_counts++ ;
	if(timer_counts == 1)
	{

		Icu_clearTimerValue();
		/* Detect falling edge */
		Icu_setEdgeDetectionType(FALLING);

	}
	else if(timer_counts == 2)
	{
		timer_value = Icu_getInputCaptureValue()  ;
		Icu_setEdgeDetectionType(RISING);

	}



}


