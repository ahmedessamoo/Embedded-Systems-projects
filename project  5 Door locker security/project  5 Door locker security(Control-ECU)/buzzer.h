/*
 * buzzer.h
 *
 *  Created on: Jun 10, 2022
 *      Author: SHAMY
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"
#include "common_macros.h"
#include "gpio.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define buzzer_port  PORTD_ID
#define buzzer_pin   PIN3_ID


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void buzzer_init(void);
void buzzer_on(void);
void buzzer_Off(void);






#endif /* BUZZER_H_ */
