/*
 *      Author: Ahmed Ali
 *      Email:  Ahmali777@gmail.com
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_



#include <util/delay.h>
#include "../../lib/BITMATH.h"
#include "../../lib/TYPES.h"
#include "DIO_private.h"

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0

#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1


#define DIO_PORT_OUTPUT  0XFF
#define DIO_PORT_INPUT   0X00

#include <avr/io.h>

//PIN Function
//ddr
void DIO_voidSetPinDir(u8 u8PortId, u8 u8PinId, u8 u8PinDir);
//port
void DIO_voidSetPinVal(u8 u8PortId, u8 u8PinId, u8 u8PinVal);
void DIO_voidTogPinVal(u8 u8PortId, u8 u8PinId);
//pin
u8 DIO_u8GetPinVal(u8 u8PortId, u8 u8PinId);


//Port Function
void DIO_voidSetPortDir(u8 u8PortId, u8 u8PortDir);
void DIO_voidSetPortVal(u8 u8PortId, u8 u8PortVal);

void DIO_vconnectpullup(char portname ,char pinnumber, char connect_pullup);
void write_low_nibble(unsigned char portname,unsigned char value);
void write_high_nibble(unsigned char portname,unsigned char value);



#endif /* DIO_INT_H_ */
