/*
 * Slave.c
 *
 * Created: 10/20/2024 6:54:08 PM
 *  Author: Dell
 */ 


#include <avr/io.h>
#include "slava.h"

u16 check;
u8 TV_ON = 0;
int main(void)
{
	UART_vInit(9600);
    while(1)
    {
		check = UART_u8ReceiveData();
		if(check == '1'){
			if(TV_ON == 0){
			  timer1_wave_fastPWM_A(90);
			  TV_ON = 1;
			}	
			else{
				TV_ON = 0;
				timer1_wave_fastPWM_A(0);
			}		  
		}									
    }
}