/*
 * command_parser.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */
#include "command_parser_fsm.h"

void command_parser_fsm(){
	switch (parser_state) {
		case PARSER_INIT:
			if(temp == '!'){
				clear();
				parser_state = PARSER_END;
				if(uart_state == UART_IDLING)
					uart_state = UART_PROCESS;
			}
			clear();
			break;
		case PARSER_END:
			if(temp == '!' || temp == '#'){
				clear();
				parser_state = PARSER_INIT;
			}
			break;
		default:
			break;
	}
}
