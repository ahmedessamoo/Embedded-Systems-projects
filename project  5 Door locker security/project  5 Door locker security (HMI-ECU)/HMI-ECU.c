/*
 * HMI-ECU.c
 *
 *  Created on: Jun 10, 2022
 *      Author: SHAMY
 */


#include "Atmega16_config.h"


/*******************************************************************************
 *                               Global  Variables                                *
 *******************************************************************************/

volatile uint8  g_pass[6] ; // global variable save within it the Entered Password

volatile uint8 g_compare_pass[6];// global variable to compare the password

volatile uint8 g_recievdresult;

volatile uint8  g_choice ; // user option choice either '+' or '-'

volatile sint8 g_Comparecounter ;

volatile uint8 g_firsttime = 1 ;



/*******************************************************************************
 *                                Main program                                   *
 *******************************************************************************/


int main(void)
{

	uint8 i ;
	uint8 g_incomingsignal = 0;



/*******************************************************************************
		                                Drivers Initialization                                  *
*******************************************************************************/

	LCD_init(); // Initialize LCD function
	UART_init(9600); // Initialize Uart with 9600 baud rate 9600 bits/second








	while(1)
	{
		if(g_firsttime == 1)
		{
			LCD_displayString("Enter a pass :");

			LCD_moveCursor(1,0);

			// get the entered pass
			for(i= 0 ; i<6; i++)
			{
				g_pass[i]  = KEYPAD_getPressedKey();
				_delay_ms(300);
				LCD_displayCharacter('*');
			}
			LCD_clearScreen();

			LCD_displayString("re-enter again: ");
			LCD_moveCursor(1,0);

			// save  the re-entered pass  in compare_pass
			for(i= 0 ; i<6; i++)
			{
				g_compare_pass[i]  = KEYPAD_getPressedKey();
				_delay_ms(300);
				LCD_displayCharacter('*');
				_delay_ms(300);
			}

			for(i = 0; i<6;i++)
			{
				if(g_compare_pass[i] == g_pass[i]  ) // if match send  the password to second mc2
				{
					g_Comparecounter ++;
					UART_sendByte(SavePass_byte);
					UART_sendByte(g_pass[i]);
					if(g_Comparecounter == 6)
					{
						g_Comparecounter = 0;
						g_firsttime = 0;
						UART_sendByte(wait_byte);

					}

				}
				else // if not match
				{
					UART_sendByte(Error_byte);
					LCD_displayString("un-Match pass!");
					_delay_ms(1000);
					LCD_clearScreen();
					continue;
				}
			}

		}
		else
		{

			UART_sendByte(wait_byte);
			LCD_clearScreen();
			LCD_displayString("+ : open door");
			LCD_moveCursor(1,0);
			LCD_displayString("- : change pass");
			g_choice = KEYPAD_getPressedKey();
			_delay_ms(300);
			if(g_choice == '+')// open the door option
			{
				LCD_clearScreen();
				LCD_displayString("Enter a pass :");
				LCD_moveCursor(1,0);
				for(i= 0 ; i<6; i++)
				{
					g_compare_pass[i]  = KEYPAD_getPressedKey();
					_delay_ms(300);
					LCD_displayCharacter('*');
					_delay_ms(300);
				}
				for(i=0 ; i<6; i++)
				{
					if(g_compare_pass[i] == g_pass[i])
					{
						g_Comparecounter++;
						if(g_Comparecounter == 6)
						{
							//	UART_sendByte(5);
							//	g_recievdresult =  UART_recieveByte();
							//	if(g_recievdresult == 1)
							//	{
							LCD_clearScreen();
							LCD_displayString("door opening..");
							UART_sendByte(PwMatch_byte); // if match send signal to second MC2 to open door
							_delay_ms(1000);
							g_incomingsignal =UART_recieveByte() ;
							if(g_incomingsignal  == wait_byte)
							{
								_delay_ms(1000);
								LCD_clearScreen();
								LCD_displayString("door closing..");
								UART_sendByte(wait_byte);
								continue;

							}

							//	}
							//else
							//{
							//	UART_sendByte(3);
							//	LCD_displayString("un-Match pass!");
							//	LCD_clearScreen();
							//	continue;

						}

						else
						{
							UART_sendByte(Error_byte);
							LCD_displayString("un-Match pass!");
							_delay_ms(500);
							LCD_clearScreen();
							continue;
						}

					}
				}


			}
			else if(g_choice == '-') // change pass option
			{
				g_firsttime = 1;
				LCD_clearScreen();
				continue;

			}

		}



	}


}

