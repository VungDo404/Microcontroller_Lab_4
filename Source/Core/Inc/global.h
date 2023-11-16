/*
 * global.h
 *
 *  Created on: Nov 15, 2023
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "stdint.h"

#define PARSER_INIT 1
#define PARSER_END 2

#define UART_INIT 3
#define UART_SEND 4
#define UART_WAIT 5

extern int parser_state;
extern int uart_state;

#define MAX_BUFFER_SIZE 30
uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t temp;
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint32_t ADC_value;
#endif /* INC_GLOBAL_H_ */
