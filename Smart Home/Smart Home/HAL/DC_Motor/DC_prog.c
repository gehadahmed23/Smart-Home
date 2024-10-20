/*
 * DC_prog.c
 *
 * Created: 12/08/2024 03:24:21 م
 *  Author: Gehad
 */ 

#include "DC_int.h"
void DC_init()
{
	DIO_voidSetPinDir(DIO_PORTC, 0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTC, 1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTC, 3, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTC, 2, DIO_PIN_OUTPUT);
	DIO_voidSetPinVal(DIO_PORTC, 0, DIO_PIN_LOW);
	DIO_voidSetPinVal(DIO_PORTC, 1, DIO_PIN_LOW);
	DIO_voidSetPinVal(DIO_PORTC, 2, DIO_PIN_LOW);
	DIO_voidSetPinVal(DIO_PORTC, 3, DIO_PIN_LOW);
}

void DC_Motor_voidRotate(DcMotor_State state, u8 pin, u8 speed)
{
	
	u16 duty_cycle;
	switch (state) {
		case off:
		DIO_voidSetPinVal(DIO_PORTC, pin, DIO_PIN_LOW);
		DIO_voidSetPinVal(DIO_PORTC, pin + 1, DIO_PIN_LOW);
		break;
		case CW: //with direction of clock
		DIO_voidSetPinVal(DIO_PORTC, pin, DIO_PIN_HIGH);
		DIO_voidSetPinVal(DIO_PORTC, pin + 1, DIO_PIN_LOW);
		break;
		case A_CW:
		DIO_voidSetPinVal(DIO_PORTC, pin, DIO_PIN_LOW);
		DIO_voidSetPinVal(DIO_PORTC, pin + 1, DIO_PIN_HIGH);
		break;
	}
	/*Speed*/
	if (speed > 100) {
		speed = 100; //max << mean i cannot exceed this limit
	}
	if (speed < 0) { //no negative
	speed = 0;
}
duty_cycle = ((float) speed / 100) * 255; //peroid of on/ totl peroid
timer_wave_fastPWM(duty_cycle);
}

