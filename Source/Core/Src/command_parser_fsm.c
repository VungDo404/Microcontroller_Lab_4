/*
 * command_parser.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */
#include "command_parser_fsm.h"
void myMemCpy(void *dest, void *src, size_t n)  {
	char *csrc = (char *)src;
	char *cdest = (char *)dest;
	for (int i=0; i<n; i++)
		cdest[i] = csrc[i];
}
void command_parser_fsm(){
	switch (parser_state) {
		case PARSER_INIT:
			if(temp == '!')
				parser_state = PARSER_END;
			clear();
			break;
		case PARSER_END:
			if(temp == '!' )
				clear();
			if(temp == '#'){
				memcpy(command_data,buffer,sizeof(buffer));
//				myMemCpy(command_data,buffer,sizeof(buffer));
				clear();
				uart_state = UART_PROCESS;
				parser_state = PARSER_INIT;
			}
			break;
		default:
			break;
	}
}
