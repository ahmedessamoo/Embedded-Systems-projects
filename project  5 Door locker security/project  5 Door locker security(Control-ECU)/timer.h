/*
 * timer.h
 *
 *  Created on: Jun 10, 2022
 *      Author: SHAMY
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "std_types.h"
#include <avr/io.h>
#include <avr/interrupt.h>



/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	Normal_mode , CTC_mode
}Timer_Mode;




typedef struct
{
	Timer_Mode Mode;

}Timer_Config;





/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void Timer0_Init(const Timer_Config * config);
void Timer0_Normalmode(void);
void Timer0_CTCmode(void);
void Timer0_stop(void);
void Timer0_set_callback(void(*a_ptr)(void));

#endif /* TIMER_H_ */
