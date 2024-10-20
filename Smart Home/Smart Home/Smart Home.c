/*
 * Fan_System.c
 *
 * Created: 10/20/2024 3:55:08 PM
 *  Author: Dell
 */ 


#include <avr/io.h>
#include "MCAL/DIO/DIO_int.h"
#include "MCAL/ADC/ADC_int.h"
#include "MCAL/TIMER/Timer_int.h"
#include "HAL/TEMP/TEMP.h"
#include "HAL/Keybad/Keypad_int.h"
#include "HAL/LCD/LCD_int.h"
#include "HAL/DC_Motor/DC_int.h"
#include "Lib/TYPES.H"
#include "Lib/BITMATH.H"
#include "Communication/UART/UART.h"
#include "HAL/LED/LED_int.h"
#include "MCAL/EEPROM/EEPROM.h"

#define  EEPROM_STATUS_LOCATION 0x20
#define  EEPROM_PASSWORD_LOCATION1 0x21
#define  EEPROM_PASSWORD_LOCATION2 0x22
#define  EEPROM_PASSWORD_LOCATION3 0x23
#define  EEPROM_PASSWORD_LOCATION4 0x24
#define  MAX_TRIES 3
#define  Repeat_process 1
#define NOTPRESSED 0xff
volatile u8  counter2 = 0, distance, time =  10;
char arr[4];
char value=NOTPRESSED, i, tries=MAX_TRIES, repeat = Repeat_process;

void Set_password(){
	
		for (i=0;i<=3;i++)
		{
			EEPROM_write(EEPROM_PASSWORD_LOCATION1+i,'1');
		}
		EEPROM_write(EEPROM_STATUS_LOCATION,0x00);
	
}

void Enter_password(){
	label_repeat:
	label_repeat2:
	LCD_clearscreen();
	arr[0] = arr[1] = arr[2] = arr[3] = NOTPRESSED;
	LCD_vSend_string("Enter_password :");
	LCD_movecursor(2, 2);
	for (u8 i = 0; i < 4; i++)
	{
		
		do
		{
			arr[i] = keypad_u8check_press();
			
		} while (arr[i] == NOTPRESSED);
		
		LCD_vSend_char(arr[i]);
		_delay_ms(500);
		LCD_movecursor(2,2+i);
		LCD_vSend_char('*');
		_delay_ms(10);
	}
	
	if(EEPROM_read(EEPROM_PASSWORD_LOCATION1)==arr[0] &&  EEPROM_read(EEPROM_PASSWORD_LOCATION2)==arr[1] && EEPROM_read(EEPROM_PASSWORD_LOCATION3)==arr[2] && EEPROM_read(EEPROM_PASSWORD_LOCATION4)==arr[3])
	{
		LCD_clearscreen();
		LCD_movecursor(1, 3);
		LCD_vSend_string("Right password");
		LCD_movecursor(2,3);
		LCD_vSend_string("Home opened");
		_delay_ms(1000);
		LCD_clearscreen();
		LCD_vSend_string("Welcome to the");
		LCD_movecursor(2, 5);
		LCD_vSend_string("My Home");
		_delay_ms(1000);
	}
	else
	{
		tries=tries-1;
		if (tries>0)
		{
			LCD_clearscreen();
			LCD_vSend_string("Wrong password");
			_delay_ms(1000);
			LCD_clearscreen();
			LCD_vSend_string("tries left:");
			LCD_vSend_char(tries+48);
			_delay_ms(1000);
			goto label_repeat;
			
		}
		else
		{
			if(repeat > 0){
				LCD_clearscreen();
				LCD_vSend_string("Wrong password");
				_delay_ms(1000);
				LCD_clearscreen();
				LCD_vSend_string("Wait 10 seconds");
				LCD_movecursor(2, 4); //2, 4
				LCD_vSend_string("to repeat");
				time = 10;
				while (time > 0)
				{
					
					LCD_clearscreen();
					LCD_vSend_string("Left ");
					LCD_vSend_char(--time + '0');
					LCD_vSend_string(" seconds");
					_delay_ms(1000);
				}
				repeat--, time = 10, tries = MAX_TRIES;
				goto label_repeat2;
			}
		}
	}
	
}
#include <avr/delay.h>

u8  flag = 0, TV_ON = 0, Fan_ON = 0, Led_ON = 0, AirConditioner_ON = 0, volt1, temp;
int main(void)
{
	ADC_init();
	LCD_vInit();
	DC_init();
	keypad_vInit();
	UART_vInit(9600);
	LED_VINIT(DIO_PORTA, 6);
	LED_VINIT(DIO_PORTA, 5);
	SET_BIT(DDRA, 7);
	Set_password();
	Enter_password();
	timer1_wave_fastPWM_A(90);
	_delay_ms(3000);
	LCD_clearscreen();
	timer1_wave_fastPWM_A(0);
    while(1)
    {
		volt1=ADC_Read()*2.5;
		temp =ADC_Read()*0.25;
		
		
		//to know temp << + | -
		if(volt1>=1000){ //mean tempreature is positive
		temp=(volt1-1000)/10;
	}
	if(volt1< 1000.00) { // mean tempreature is negative
	temp=((1000-volt1)/10);
	}	
	if(temp >= 90){
		SET_BIT(PORTA, 7);
		LED_vTurnOn(DIO_PORTA, 5);
	}	
	
	else{
		CLR_BIT(PORTA, 7);
		LED_vTurnOff(DIO_PORTA, 5);
	}	
		if(flag == 0){
			LCD_vSend_string("Room1");
			u8 check = 0xff;
			do
			{
				check = keypad_u8check_press();
			} while (check != '1');
			timer1_wave_fastPWM_B(90);
			_delay_ms(3000);
			LCD_clearscreen();
			timer1_wave_fastPWM_B(0);
			flag = 1;
		}
		LCD_clearscreen();
		LCD_vSend_string("1.TV 2.Fan 3.Led");
		LCD_movecursor(2,1);
		LCD_vSend_string("4.AirConditioner");
		u8 check = 0xff;
		do 
		{
			check = keypad_u8check_press();
		} while (check == 0xff);
		LCD_clearscreen();
		LCD_vSend_char(check);
		_delay_ms(500);
		if(check == '1'){
			UART_vSendData(check);
		}			
		else if (check == '2')
		{
			if (Fan_ON == 0)
			{
				Fan_ON++;
				TEMP_Speed(0);
				_delay_ms(1000);
			}
			else {
				Fan_ON = 0;
				TEMP_OFF(0);
				_delay_ms(1000);
			}
			
		}
		else if(check == '3'){
			LED_vToggle(DIO_PORTA, 6);
		}
		else if(check == '4'){
			  if(AirConditioner_ON == 0){
				  TEMP_Speed(2);
				  AirConditioner_ON = 1;
				  _delay_ms(1000);
			  }
			  else {
				  AirConditioner_ON = 0;
				  TEMP_OFF(2);
				  _delay_ms(1000);
			  }
		}
		else if(check == '5'){
			timer1_wave_fastPWM_B(0);
			_delay_ms(3000);
			LCD_clearscreen();
			timer1_wave_fastPWM_B(30);
			flag = 0;
		}
		
        //TODO:: Please write your application code 
    }
}