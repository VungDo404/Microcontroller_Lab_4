/*
 * uart_communication_fsm.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */
#include "uart_communication_fsm.h"


uint32_t ADC_value = 0;
uint32_t ADC_temp = 0;

void uart_communication_fsm(){
	switch (uart_state) {
		case UART_IDLING:
			break;
		case UART_PROCESS:
			if(memcmp(command_data,"RST#",4) == 0){
				uart_state = UART_SEND;
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);
				HAL_ADC_Stop(&hadc1);
			}
			break;
		case UART_SEND:
			setTimer(300, 1);
			uart_state = UART_WAIT;
			ADC_temp = ADC_value;
			HAL_UART_Transmit(&huart2 ,(void*)str, sprintf(str , "\r\n!ADC=%d#\r", ADC_temp), 1000);
			break;
		case UART_WAIT:
			if(timer_flag[1] == 1)
				uart_state = UART_SEND;
			if(memcmp(command_data,"OK#",3) == 0)
				uart_state = UART_IDLING;
			break;
		default:
			break;
	}
}
