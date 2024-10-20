/*
 * Keypad_int.h
 *
 * Created: 8/13/2024 1:59:55 PM
 *  Author: Dell
 */ 


#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_
 #define F_CPU 8000000UL
 #include <util/delay.h>
 #include "Keypad_config.h"
 #include "../../MCAL/DIO/DIO_int.h"
 
 
void keypad_vInit();
u8 keypad_u8check_press();



#endif /* KEYPAD_INT_H_ */