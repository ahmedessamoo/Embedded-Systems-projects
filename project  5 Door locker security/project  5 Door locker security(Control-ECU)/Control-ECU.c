/*
 * Control-ECU.c
 *
 *  Created on: Jun 10, 2022
 *      Author: SHAMY
 */


#include "Atmega16_config.h"



/*******************************************************************************
 *                               Global  Variables                                *
 *******************************************************************************/

volatile uint8  g_pass[6] ;
volatile uint8 g_temppass ;
volatile uint8 g_savedpass[6];

volatile uint8 g_incoming_signal = wait_byte ;

uint8 i ;







/*******************************************************************************
 *                                Main program                                   *
 *******************************************************************************/


int main(void)
{


/*******************************************************************************
	                               Drivers Initialization                                  *
 *******************************************************************************/
	Timer_Config configuration = {Normal_mode};
	UART_init(9600);
	TWI_init();/*initialize i2c/twi */
	buzzer_init();/*initialize buzzer */
	Dcmotor_init();/*initialize i2c/twi */
	EEPROM_init(); /*initialize Dc motor */

    Timer0_Init(&configuration);
    SREG |= (1<<7);/* configure I-Bit to be set to enable global interrupts */





 while(1)
    {


	   g_incoming_signal = UART_recieveByte();

	 //  while(g_incoming_signal == wait_byte){} wait until signal coming


    	if(g_incoming_signal == SavePass_byte)
    	{
    		for(i = 0 ; i<6 ; i++)
    		{
    			g_pass[i] =   UART_recieveByte();


    		}
    		// save pass in The External EEPROM
    		EEPROM_writeByte(0x0311,g_pass);
    		g_incoming_signal =wait_byte;
    	}

    	if(g_incoming_signal == PwMatch_byte)
    	{
    		//Timer0_Normalmode();
    		//Timer0_stop();
    		 Dcmotor_Rotateclockwise();
    		 _delay_ms(1000);
    		 Dcmotor_stop();
    		 UART_sendByte(wait_byte);
    		 _delay_ms(3000);
    		 Dcmotor_Rotate_Anticlockwise();
    		 _delay_ms(1000);
    		 Dcmotor_stop();
    		g_incoming_signal = wait_byte ;

    	}
    	else if(g_incoming_signal == Error_byte)
    	{
    		buzzer_on();
    		_delay_ms(1000);
    		buzzer_Off();
    		g_incoming_signal =wait_byte ;

    	}


    }


	}


