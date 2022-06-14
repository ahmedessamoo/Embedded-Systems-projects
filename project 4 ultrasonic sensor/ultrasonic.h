/*
 * ultrasonic.h
 *
 *  Created on: Jun 3, 2022
 *      Author: SHAMY
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_



#include "std_types.h"
#include "gpio.h"



#define ULTRASONIC_TRIGGER_PORT_ID          PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID           PIN5_ID
#define ULTRASONIC_NUM_OF_DETECTED_EDGES    2


void Ultrasonic_init(void) ;
void Ultrasonic_Trigger(void) ;
uint16 ultrasonic_readdistance(void);
void Ultrasonic_edgeprocessing(void);



#endif /* ULTRASONIC_H_ */
