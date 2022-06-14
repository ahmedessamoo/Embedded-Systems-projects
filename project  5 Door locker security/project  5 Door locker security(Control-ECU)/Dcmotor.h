/*
 * Dcmotor.h
 *
 *  Created on: Jun 10, 2022
 *      Author: SHAMY
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"
#include "common_macros.h"
#include "gpio.h"
/***************************************************************************
 *                             Definitions
 ************************************************************************* */
#define  MotorIN1    PIN6_ID
#define  MotorIN2    PIN7_ID


/***************************************************************************
 *                             Functions Prototypes
 ************************************************************************* */
void Dcmotor_init(void);
void Dcmotor_Rotateclockwise(void);
void Dcmotor_Rotate_Anticlockwise(void);
void Dcmotor_stop(void);


#endif /* DCMOTOR_H_ */
