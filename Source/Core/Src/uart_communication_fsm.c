/*
 * uart_communication_fsm.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */
#include "uart_communication_fsm.h"


char RESP_OK[] = "OK#";
char RESP_RST[] = "RST#";
uint32_t ADC_value = 0;
uint32_t ADC_temp = 0;

void uart_communication_fsm(){
	switch (uart_state) {
		case UART_IDLING:
				break;
		case UART_PROCESS:
			if(strcmp((const char *)buffer, RESP_RST) == 0){
				uart_state = UART_SEND;
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);
				HAL_ADC_Stop(&hadc1);
			}
			break;
		case UART_SEND:
			uart_state = UART_WAIT;
			setTimer(300, 1);
			ADC_temp = ADC_value;
			HAL_UART_Transmit(&huart2 ,(void*)str, sprintf(str , "\r\n!ADC=%d#\r", ADC_temp), 100);
			break;
		case UART_WAIT:
			if(timer_flag[1] == 1){
				uart_state = UART_SEND;
			}
			if(strcmp((const char *)buffer, RESP_OK) == 0){
				HAL_UART_Transmit(&huart2 , (void*)str , sprintf(str , "\r"), 50);
				uart_state = UART_IDLING;
			}
			break;
		default:
			uart_state = UART_IDLING;
			parser_state = PARSER_INIT;
			break;
	}
}
