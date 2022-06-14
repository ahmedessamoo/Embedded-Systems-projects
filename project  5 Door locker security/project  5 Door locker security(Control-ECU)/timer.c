/*
 * timer.c
 *
 *  Created on: Jun 10, 2022
 *      Author: SHAMY
 */



#include "timer.h"
#include "Dcmotor.h"

//static void(*g_tcallBackPtr)(void) = NULL_PTR;




static volatile g_counter;


ISR(TIMER0_OVF_vect)
{
	g_counter++;
	if(g_counter == 31)
	{
		Dcmotor_Rotateclockwise();

	}
	else if(g_counter == 92)
	{
		Dcmotor_stop();
	}
	else if(g_counter == 124)
	{
		Dcmotor_Rotate_Anticlockwise();

	}


}


ISR(TIMER0_COMP_vect)
{
	g_counter++;
	if(g_counter == 31)
	{
		Dcmotor_Rotateclockwise();

	}
	else if(g_counter == 92)
	{
		Dcmotor_stop();
	}
	else if(g_counter == 124)
	{
		Dcmotor_Rotate_Anticlockwise();

	}

}


void Timer0_Init(const Timer_Config *config)
{
	uint8 data;
	data = config->Mode;

#if(data == Normal_mode)
	void Timer0_Normalmode(void);
#elif(data == CTC_mode)
	void Timer0_CTCmode(void);
#endif

}

void Timer0_Normalmode(void)
{
	TCNT0 =  0;
	TIMSK |= (1<<TOIE0);
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);

}



void Timer0_CTCmode(void)
{
	TCNT0 = 0;
	OCR0 = 255;
	TIMSK = (1<<OCIE0);
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<COM01) | (1<<CS02)| (1<<CS00);


}

void Timer0_stop(void)
{
	TCCR0 = 0;
	TCNT0 = 0;
	OCR0 = 0;
	TIMSK = 0;

}


