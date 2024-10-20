/*
 * LCD_prog.c
 *
 * Created: 8/14/2024 10:29:55 AM
 *  Author: Gehad Ahmed
 */ 

#include "LCD_int.h"

void LCD_vInit(void)
{
	_delay_ms(200);
	DIO_voidSetPinDir(DIO_PORTC,4,1);
	DIO_voidSetPinDir(DIO_PORTC,5,1);
	DIO_voidSetPinDir(DIO_PORTC,6,1);
	DIO_voidSetPinDir(DIO_PORTC,7,1);
	DIO_voidSetPinDir(DIO_PORTA,EN,1);
	DIO_voidSetPinDir(DIO_PORTA,RW,1);
	DIO_voidSetPinDir(DIO_PORTA,RS,1);
	DIO_voidSetPinVal(DIO_PORTA,RW,0);
	LCD_vSend_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	LCD_vSend_cmd(FOUR_BITS); //4bit mode
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	
}


static void send_falling_edge(void)
{
	DIO_voidSetPinVal(DIO_PORTA,EN,1);
	_delay_ms(2);
	DIO_voidSetPinVal(DIO_PORTA,EN,0);
	_delay_ms(2);
}
void LCD_vSend_cmd(char cmd)
{

	write_high_nibble(DIO_PORTC,cmd>>4);
	DIO_voidSetPinVal(DIO_PORTA,RS,0);
	send_falling_edge();
	write_high_nibble(DIO_PORTC,cmd);
	DIO_voidSetPinVal(DIO_PORTA,RS,0);
	send_falling_edge();
	_delay_ms(1);
}

void LCD_vSend_char(char data)
{

	write_high_nibble(DIO_PORTC,data>>4);
	DIO_voidSetPinVal(DIO_PORTA,RS,1);
	send_falling_edge();
	write_high_nibble(DIO_PORTC,data);
	DIO_voidSetPinVal(DIO_PORTA,RS,1);
	send_falling_edge();

	_delay_ms(1);
}


void LCD_vSend_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_vSend_char(*data);
		data++;
	}
}
void LCD_clearscreen()
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
}
void LCD_movecursor(char row,char coloumn)
{
	char data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	LCD_vSend_cmd(data);
	_delay_ms(1);
}
void LCD_vWriteNum(s32 NUM){
	if(NUM == 0){
		LCD_vSend_char('0');
	}
	if(NUM < 0){
		LCD_vSend_char('-');
		NUM *= -1;
	}
	s32 temp = 1;
	while(NUM > 0){
		temp = (temp * 10) + (NUM % 10);
		NUM /= 10;
	}
	while(temp != 1){
		LCD_vSend_char((temp % 10) + '0');
		temp /= 10;
	}
}
//void LCD_vSaveCustomChar(u8 CGRAMIndex, u8 CustomChar[]){
	//LCD_vSend_cmd(LCD_CGRAM_ADDRESS+CGRAMIndex*8);
	//
	//for(u8 i = 0 ; i<8; i++)
	//{
		//
		//LCD_vSend_char(CustomChar[i]);
	//}
	//
	//LCD_vSend_cmd(LCD_DDRAM_SETCURS);
//}
//void LCD_vWriteCustomChar(u8 CGRAMIndex){
	//if(CGRAMIndex){
		//LCD_vSend_char(CGRAMIndex);
	//}
//}