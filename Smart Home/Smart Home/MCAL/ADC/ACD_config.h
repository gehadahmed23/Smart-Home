/*
 * ACD_config.h
 *
 * Created: 8/15/2024 11:36:24 AM
 *  Author: Dell
 */ 


#ifndef ACD_CONFIG_H_
#define ACD_CONFIG_H_


#define EXT			0x00
#define VCC			0x01
#define INT			0x03

#define REFERENCE	VCC


//
#define DIV_2		0x00
#define DIV_4		0x02
#define DIV_8		0x03
#define DIV_16		0x04
#define DIV_32		0x05
#define DIV_64		0x06
#define DIV_128		0x07

#define PRESCALE	DIV_8
//
#define ADJ_right			0
#define ADJ_left			1
#define Result_Adjust		ADJ_right

/*/
#define Enable 1
#define Disable 0

#define Interrupt Disable
*/


#endif /* ACD_CONFIG_H_ */