/*
 * Atmega16_config.h
 *
 *  Created on: Jun 10, 2022
 *      Author: SHAMY
 */

#ifndef ATMEGA16_CONFIG_H_
#define ATMEGA16_CONFIG_H_

/***************************************************************************
 *                             Definitions
 ************************************************************************* */

#ifndef F_CPU
#define F_CPU 8000000UL
#endif



#define wait_byte       0X00
#define SavePass_byte   0X01
#define PwMatch_byte    0X02
#define Error_byte      0X03


/***************************************************************************
 *                             libraries
 ************************************************************************* */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "std_types.h"
#include "common_macros.h"
#include "Dcmotor.h"
#include "timer.h"
#include "gpio.h"
#include "twi.h"
#include "uart.h"
#include "eeprom.h"
#include "buzzer.h"




#endif /* ATMEGA16_CONFIG_H_ */
