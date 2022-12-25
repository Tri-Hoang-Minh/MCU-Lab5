/*
 * uart_communication.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */


#include "uart_communication.h"
#include "string.h"
#include "main.h"
#include "global.h"
#include "stdio.h"

void UART_communication_fsm(){
	char str[50];
	switch (communication_status)
	{
		case RECEIVE_COMMAND:
			HAL_ADC_Start(&hadc1);
			value_ADC= HAL_ADC_GetValue(&hadc1);
			HAL_ADC_Stop(&hadc1);
			if (command_flag==1)
			{
				uint8_t temp[MAX_BUFFER_SIZE]="!RST#";
				if (find_string(command_data, temp)==1)
				{
					communication_status=SEND_ADC;
					setTimer1(1);
				}
				command_flag=0;
			}


			break;
		case SEND_ADC:
			if (command_flag==1)
			{
				uint8_t temp[MAX_BUFFER_SIZE]="!OK#";
				if (find_string(command_data, temp)==1)
				{
					setTimer1(0);
					communication_status=RECEIVE_COMMAND;
				}
				command_flag=0;
			}
			if (timer1_flag==1)
			{

				HAL_UART_Transmit (&huart2 , (void*)str , sprintf (str,"\n%ld\n",value_ADC), 1000);
				setTimer1(300);
			}

			break;
		default:
			break;
	}
}
