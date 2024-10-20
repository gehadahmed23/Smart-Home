/*
 * TEMP.h
 *
 * Created: 10/20/2024 12:19:58 AM
 *  Author: Dell
 */ 


#ifndef TEMP_H_
#define TEMP_H_

#include "../../HAL/DC_Motor/DC_int.h"
#include "../../MCAL/ADC/ADC_int.h"

ADC_init();
DC_Init();
void TEMP_Speed(u8 bin);
void TEMP_OFF(u8 bin);



#endif /* TEMP_H_ */