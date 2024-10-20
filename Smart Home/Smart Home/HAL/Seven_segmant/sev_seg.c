/*
 * sev_seg.c
 *
 * Created: 8/13/2024 10:54:32 AM
 *  Author: Dell
 */ 

#include "Sev_seg.h"
#include <util/delay.h>

u8 sev[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	
void seven_seg_vinit(u8 sev_port)
{
	DIO_voidSetPortDir(sev_port,DIO_PORT_OUTPUT);
}

void seven_seg_write(u8 sev_port,u8 num)
{
	#if SEV_TYPE == CATHODE 
		DIO_voidSetPortVal(sev_port,sev[num]);	
	#elif SEV_TYPE == ANODE 
		DIO_voidSetPortVal(sev_port,~(sev[num]));	
	#endif		
   
}
void Sev_voidCountUp(u8 sev_port){
	for(u8 i = 0; i <= 9; i++){
		seven_seg_write(sev_port, i);
		_delay_ms(DELEYTIME);
	}
}
void Sev_voidCountDown(u8 sev_port){
	for(s8 i = 9; i >= 0; i--){
		seven_seg_write(sev_port, i);
		_delay_ms(DELEYTIME);
	}
}
void Sev_voidTurnOFF(u8 sev_port){
	DIO_voidSetPortVal(sev_port,0x00);
}
void Sev_voidCheckAll(u8 sev_port){
	DIO_voidSetPortVal(sev_port,0xff);
}
void Sev_voidDisplay2Digit(u8 sev_port1, u8 sev_port2, u8 num){
	u8 dig1 = num / 10;
	u8 dig2 = num % 10;
	seven_seg_write(sev_port1, sev[dig1]);
	seven_seg_write(sev_port2, sev[dig2]);
}