/*
 * LCD_int.h
 *
 * Created: 8/14/2024 10:30:07 AM
 *  Author: Gehad Ahmed
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_

 
 #include <util/delay.h>
 #include "../../MCAL/DIO/DIO_int.h"
 #include "LCD_config.h"
 
#include "../../MCAL/DIO/DIO_int.h"
#include "LCD_config.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#if defined four_bits_mode
#define EN 3
#define RS 4
#define RW 5
#define FOUR_BITS 0x28
#elif defined eight_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif
void LCD_vInit(void);
static void send_falling_edge(void);
void LCD_vSend_cmd(char cmd);
void LCD_vSend_char(char data);
void LCD_vSend_string(char *data);
void LCD_clearscreen();
void LCD_movecursor(char row,char coloumn);
void LCD_vWriteNum(s32 NUM);
void LCD_vSaveCustomChar(u8 CGRAMIndex, u8 CustomChar[]);
void LCD_vWriteCustomChar(u8 CGRAMIndex);




#endif /* LCD_INT_H_ */