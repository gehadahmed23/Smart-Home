/*
 * LED_int.h
 *
 * Created: 8/13/2024 2:39:46 AM
 *  Author: Dell
 */ 


#ifndef LED_INT_H_
#define LED_INT_H_
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_private.h"

void LED_VINIT(unsigned char portname, unsigned char pinnumber);
void LED_vTurnOn(unsigned char portname, unsigned char pinnumber);
void LED_vTurnOff(unsigned char portname, unsigned char pinnumber);
void LED_vToggle(unsigned char portname, unsigned char pinnumber);


#endif /* LED_INT_H_ */