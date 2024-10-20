///*
 //* ultrasonic.c
 //*
 //* Created: 2/19/2024 8:13:52 AM
 //*  Author: Dell
 //*/ 
//#include <avr/io.h>
//#define F_CPU 1000000UL
//#include <util/delay.h>
//#include "DIO.h"
//#include "std_macros.h"
//unsigned long a, b, high;
//short ultrasonic_distance(short* dis){
	//
	//TCCR1A = 0;
	//TIFR |= (1 << ICF1); // Clear ICF (Input Capture flag)
	//DIO_write('D', 3, 1); // Create pulse for 50 ms
	//_delay_ms(50);
	//DIO_write('D', 3, 0);
	//TCCR1B = 0xc1;  // Rising edge, no prescaler , noise canceler
	//while(IS_BIT_CLR(TIFR, ICF1));
	//a = ICR1;
	//TIFR |= (1 << ICF1);
	//TCCR1B = 0x81;  // Falling edge, no prescaler ,noise canceler
	//while(IS_BIT_CLR(TIFR, ICF1));
	//b = ICR1;
	//TIFR |= (1 << ICF1);
	//TCNT1 = 0;
	//TCCR1B = 0;    // Stop the timer
	//high = b - a;
	//dis = ((34600 * high) / (F_CPU * 2));
	//
	//return dis;
//}
//