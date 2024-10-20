/*
 * LED_prog.c
 *
 * Created: 8/13/2024 2:39:29 AM
 *  Author: Dell
 */ 
#include "LED_int.h"

void LED_VINIT(unsigned char portname, unsigned char pinnumber)
{
	DIO_voidSetPinDir(portname, pinnumber, DIO_PIN_OUTPUT);
}
void LED_vTurnOn(unsigned char portname, unsigned char pinnumber)
{
	DIO_voidSetPinVal(portname, pinnumber, DIO_PIN_HIGH);
}
void LED_vTurnOff(unsigned char portname, unsigned char pinnumber)
{
	DIO_voidSetPinVal(portname, pinnumber, DIO_PIN_LOW);
}
void LED_vToggle(unsigned char portname, unsigned char pinnumber)
{
	DIO_voidTogPinVal(portname, pinnumber);
}	