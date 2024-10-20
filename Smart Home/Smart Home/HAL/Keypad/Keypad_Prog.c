/*
 * Keypad_Prog.c
 *
 * Created: 8/13/2024 1:59:34 PM
 *  Author: Dell
 */ 
#include "Keypad_int.h"

u8 KPD[4][4]={
	{'7'  ,'8' , '9' ,'/'}, //R 0
	{'4'  ,'5' , '6' ,'*'}, //R 1
	{'1'  ,'2' , '3' ,'-'}, //R 2
	{'C','0' ,'=','+'}  //R 3
////    C0  C1 C2  C3
};
void keypad_vInit()
{
	DIO_voidSetPortDir(KEP_PORT, 0x0f);
	DIO_vconnectpullup(KEP_PORT,4,1);
	DIO_vconnectpullup(KEP_PORT,5,1);
	DIO_vconnectpullup(KEP_PORT,6,1);
	DIO_vconnectpullup(KEP_PORT,7,1);
	
}
u8 keypad_u8check_press()
{
  //char KPD[4][4]={{'7','4','1','/'},{'8','5','2','*'},{'9','6','3','-'},{'=','A','B','+'}};  
  u8 ROW,COL,x;
  u8 returnval=255;
  for(ROW=0;ROW<4;ROW++)
  {
	  DIO_voidSetPinVal(KEP_PORT,0,DIO_PIN_HIGH);
	  DIO_voidSetPinVal(KEP_PORT,1,DIO_PIN_HIGH);
      DIO_voidSetPinVal(KEP_PORT,2,DIO_PIN_HIGH);
	  DIO_voidSetPinVal(KEP_PORT,3,DIO_PIN_HIGH);
      DIO_voidSetPinVal(KEP_PORT,ROW,DIO_PIN_LOW);
 
	  for(COL=0;COL<4;COL++)
	  {
	    x=DIO_u8GetPinVal(KEP_PORT,(COL + 4));
	   if(x==0)
		{
		 returnval=KPD[ROW][COL];
		 break;
		} 
		
	  } 
	  if(x==0)
	  {
		  break;
	  }  
  
 }  
 _delay_ms(5);
  
  return returnval ;  
 }
 