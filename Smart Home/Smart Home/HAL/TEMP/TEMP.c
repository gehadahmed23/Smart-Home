/*
 * TEMP.c
 *
 * Created: 10/20/2024 12:07:22 AM
 *  Author: Dell
 */ 

#include "TEMP.h"

void TEMP_Speed(u8 bin){
unsigned long  preassur, temperatue , volt, negative = 0;


	//calc part << negative tempreature are considred
	//calc part << negative tempreature are considred
	volt=ADC_Read()*2.5;
	temperatue=(ADC_Read()*0.25);
	
	
	//to know temp << + | -
	if(volt>=1000.00){ //mean tempreature is positive
	temperatue=(volt-1000)/10;
}
    if(volt< 1000.00) { // mean tempreature is negative
    temperatue=((1000-volt)/10);
	negative = 1;
            }

/////to get fan work
		if ((temperatue>= 100) && (temperatue<= 150)) {
			DC_Motor_voidRotate(CW, bin, 100);
			}
			else if ((temperatue>= 70) && (temperatue<= 99)) {
				DC_Motor_voidRotate(CW, bin, 75);
			} 
			else if ((temperatue>= 40) && (temperatue<= 69)) {
				DC_Motor_voidRotate(CW, bin, 50);
			}
			else if ((temperatue>= 21) && (temperatue<= 39)) {
				DC_Motor_voidRotate(A_CW, bin, 25);
			}
			else if ((temperatue<= -55) && (temperatue<= 20)) {
				DC_Motor_voidRotate(off, bin, 0);
			}
		
			LCD_vSend_string("Temp = ");
			if(negative)LCD_vSend_char('-');
			LCD_vWriteNum(temperatue);
			}	
			
void TEMP_OFF(u8 bin){
	DC_Motor_voidRotate(off, bin, 0);
}					