/*
 * global.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Admin
 */
#include "global.h"


int uart_state = UART_IDLING;
int	parser_state = PARSER_INIT;
uint8_t command_data[MAX_BUFFER_SIZE];
void clear(){
	memset(buffer,'\0', sizeof(buffer));
	index_buffer = 0;
	temp = '\0';
}
