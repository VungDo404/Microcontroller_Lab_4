/*
 * global.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Admin
 */
#include "global.h"


int parser_state = 0;
int uart_state = 0;
void clear(){
	memset(buffer,0, sizeof(buffer));
	index_buffer = 0;
	temp = 0;
}
