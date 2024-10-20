/*
 * LCD_config.h
 *
 * Created: 8/14/2024 10:30:19 AM
 *  Author: Gehad Ahmed
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

//Bit Mode
#define four_bits_mode

#define LCD_PORT DIO_PORTC
#define LCD_RS DIO_PORTA, DIO_PIN4
#define LCD_RW DIO_PORTA, DIO_PIN5
#define LCD_EN DIO_PORTA, DIO_PIN3





#endif /* LCD_CONFIG_H_ */