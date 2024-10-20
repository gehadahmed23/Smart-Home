/*
 * UART.h
 *
 * Created: 10/20/2024 12:01:53 AM
 *  Author: Dell
 */ 


#ifndef UART_H_
#define UART_H_

#define F_CPU 8000000UL
#include "../../lib/BITMATH.h"
#include "../../lib/TYPES.h"
#include <util/delay.h>
#include <avr/io.h>

void UART_vInit(unsigned long baud);
void UART_vSendData(char data);
char UART_u8ReceiveData(void);
void UART_vSendstring( char *ptr);



#endif /* UART_H_ */