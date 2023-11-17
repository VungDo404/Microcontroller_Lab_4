/*
 * uart_communication_fsm.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */

#ifndef INC_UART_COMMUNICATION_FSM_H_
#define INC_UART_COMMUNICATION_FSM_H_
#include "global.h"
#include "main.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

extern uint32_t ADC_value;
extern uint32_t ADC_temp;



char str[100];
void uart_communication_fsm();

#endif /* INC_UART_COMMUNICATION_FSM_H_ */
